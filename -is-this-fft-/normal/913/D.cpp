#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_PROB = 200005;

vector<pair<int, int> > rem_at [MAX_PROB];

class fenwick {
  vector<int> tree;
  int vertexc;

public:
  fenwick (int _vertexc) {
    vertexc = _vertexc;
    tree = vector<int> (vertexc + 5, 0);
  }

  void add (int index, int val) {
    for (int i = index; i < vertexc; i += i & -i) {
      tree[i] += val;
    }
  }

  int get (int index) {
    int ans = 0;
    for (int i = index; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  int fwsum (int req) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      if (ans + (1 << i) < vertexc) {
        if (tree[ans + (1 << i)] < req) {
          req -= tree[ans + (1 << i)];
          ans += 1 << i;
        }
      }
    }
    ans++;

    if (ans == vertexc) {
      return -1;
    }
    return ans;
  }
};

struct problem {
  int value, delat, id;

  problem (int _value, int _delat, int _id) {
    value = _value;
    delat = _delat;
    id = _id;
  }
};

bool operator< (problem p, problem q) {
  return make_pair(p.value, p.id) < make_pair(q.value, q.id);
}

int main () {
  int problemc, length;
  cin >> problemc >> length;

  vector<problem> problems;
  for (int i = 0; i < problemc; i++) {
    int delat, value;
    cin >> delat >> value;

    problems.push_back(problem(value, delat, i + 1));
  }

  sort(problems.begin(), problems.end());

  fenwick timecost (MAX_PROB);
  fenwick present (MAX_PROB);
  for (int i = 0; i < problemc; i++) {
    timecost.add(i + 1, problems[i].value);
    present.add(i + 1, 1);
    rem_at[problems[i].delat].push_back(make_pair(i + 1, problems[i].value));
  }

  int ans = 0;
  for (int i = 1; i <= problemc; i++) {
    if (present.fwsum(i) != -1) {
      if (timecost.get(present.fwsum(i)) <= length) {
        ans = i;
      }
    }

    for (pair<int, int> p : rem_at[i]) {
      present.add(p.first, -1);
      timecost.add(p.first, -p.second);
    }
  }

  cout << ans << endl << ans << endl;
  int outc = ans;
  for (problem p : problems) {
    if (outc == 0) {
      break;
    }
    
    if (p.delat >= ans) {
      cout << p.id << ' ';
      outc--;
    }
  }
  cout << endl;
}