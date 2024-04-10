#include <iostream>
#include <set>
#include <string>
#include <algorithm>

const int FENLEN = 1 << 17;
const int MAX_LEN = 1000005;

using namespace std;

class fenwick {
  int *val;

public:
  fenwick () {
    val = new int [FENLEN];
    for (int i = 0; i < FENLEN; i++) {
      val[i] = 0;
    }
  }

  void add (int index, int num) {
    for (int i = index; i < FENLEN; i += i & -i) {
      val[i] += num;
    }
  }

  int get (int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= i & -i) {
      ans += val[i];
    }
    return ans;
  }

  int lastzero () { /* last index where get(i) == 0 */
    int ans = 0;
    for (int i = FENLEN / 2; i != 0; i /= 2) {
      if (get(ans + i) == 0) {
        ans += i;
      }
    }
    return ans;
  }
};

int compr [MAX_LEN];

struct query {
  int left, right, id, ans;
} queries [FENLEN];

bool byright (query p, query q) {
  if (p.right == q.right) {
    return p.id < q.id;
  } else {
    return p.right < q.right;
  }
}

bool orig (query p, query q) {
  return p.id < q.id;
}

int main () {
  ios::sync_with_stdio(false);

  string arr;
  cin >> arr;

  set<int, greater<int> > cpset;
  int queryc;
  cin >> queryc;
  cpset.insert(0);
  for (int i = 0; i < queryc; i++) {
    cin >> queries[i].left >> queries[i].right;
    queries[i].left--;
    queries[i].right--;
    queries[i].id = i;

    cpset.insert(queries[i].left);
  }

  int cur_comp = 1;
  for (auto i = cpset.begin(); i != cpset.end(); i++) {
    compr[*i] = cur_comp;
    cur_comp++;
  }

  sort(queries, queries + queryc, byright);
  int cur_query = 0, cur_left = compr[0];
  fenwick lvl, len;
  for (int i = 0; i < (int) arr.size(); i++) {
    if (compr[i] != 0) {
      cur_left = compr[i];
    }

    if (arr[i] == '(') {
      lvl.add(cur_left, 1);
    } else {
      int lz = lvl.lastzero();
      lvl.add(lz + 1, -1);
      len.add(lz + 1, 2);
    }

    while (i == queries[cur_query].right) {
      queries[cur_query].ans = len.get(compr[queries[cur_query].left]);
      cur_query++;
    }
  }

  sort(queries, queries + queryc, orig);

  for (int i = 0; i < queryc; i++) {
    cout << queries[i].ans << '\n';
  }
}