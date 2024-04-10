#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;

int pars [MAX_N];
vector<int> children [MAX_N];
int ans [MAX_N];

void dfs (int vertex, int sgn) {
  ans[vertex] = sgn;
  for (int nxt : children[vertex]) {
    dfs(nxt, sgn * pars[nxt]);
  }
}

struct vec {
  int x, y, id;
};

vec operator+ (vec u, vec v) {
  u.x += v.x;
  u.y += v.y;
  return u;
}

vec operator- (vec u, vec v) {
  u.x -= v.x;
  u.y -= v.y;
  return u;
}

bool subunit (vec u) {
  return ((long long) u.x * (long long) u.x) +
    ((long long) u.y * (long long) u.y) <= 1000000000000LL;
}

int kind (vec u, vec v) {
  if (subunit(u + v)) {
    return 1;
  } else if (subunit(u - v)) {
    return -1;
  } else {
    return 0;
  }
}

long long len (vec u) {
  return (long long) u.x * (long long) u.x
    + (long long) u.y * (long long) u.y;
}

bool deld [MAX_N];

int main () {  
  int vectorc;
  cin >> vectorc;

  vector<vec> vectors (vectorc);
  for (int i = 0; i < vectorc; i++) {
    cin >> vectors[i].x >> vectors[i].y;
    vectors[i].id = i;
  }

  vector<vec> last = vectors;
  while (true) {
    vector<vec> cur;
    for (vec v : last) {
      if (!deld[v.id]) {
        cur.push_back(v);
      }
    }

    if (cur.size() <= 2) {
      last = cur;
      break;
    }

    random_shuffle(cur.begin(), cur.end());

    for (int i = 0; i < (int) cur.size() - 1; i += 2) {
      int sgn = kind(cur[i], cur[i + 1]);
      if (sgn == 1) {
        cur[i] = cur[i] + cur[i + 1];
        deld[cur[i + 1].id] = true;
        children[cur[i].id].push_back(cur[i + 1].id);
        pars[cur[i + 1].id] = 1;
        // cer << cur[i].id << " += " << cur[i + 1].id << endl;
      } else if (sgn == -1) {
        cur[i] = cur[i] - cur[i + 1];
        deld[cur[i + 1].id] = true;
        children[cur[i].id].push_back(cur[i + 1].id);
        pars[cur[i + 1].id] = -1;
        // cer << cur[i].id << " -= " << cur[i + 1].id << endl;
      }
    }

    last = cur;
  }

  if ((int) last.size() == 2) {
    if (len(last[0] + last[1]) < len(last[0] - last[1])) {
      children[last[0].id].push_back(last[1].id);
      pars[last[1].id] = 1;
    } else {
      children[last[0].id].push_back(last[1].id);
      pars[last[1].id] = -1;
    }
  }
  dfs(last[0].id, 1);


  long long sumx = 0, sumy = 0;
  for (int i = 0; i < vectorc; i++) {
    cout << ans[i] << " ";
    sumx += ans[i] * vectors[i].x;
    sumy += ans[i] * vectors[i].y;
  }
  cout << endl;
}