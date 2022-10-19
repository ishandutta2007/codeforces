#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 1010;
const int A = 10;
const int inf = 2e9;

int n;
int m[M][M];
vector<int> ans[A][2];

int bit(int mask, int i) {
  return (mask >> i) & 1;
}

void ask(vector<int> w, vector<int> &to) {
  to.resize(n);
  fill(to.begin(), to.end(), inf);
  if (w.empty())
    return;

#ifdef LOCAL
  for (int i = 0; i < n; ++i) {
    int res = inf;
    for (int j : w)
      res = min(res, m[i][j]);
    to[i] = res;
  }
#else

  cout << w.size() << endl;
  for (int x : w)
    cout << x + 1 << " ";
  cout << endl;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    to[i] = x;
  }
#endif
}

void kill() {
  for (int i = 0; i < A; ++i) {
    vector<int> w[2];
    for (int j = 0; j < n; ++j)
      w[bit(j, i)].push_back(j);

    ask(w[0], ans[i][0]);
    ask(w[1], ans[i][1]);
  }

  cout << "-1" << endl;
  for (int i = 0; i < n; ++i) {
    int res = inf;
    for (int j = 0; j < A; ++j)
      res = min(res, ans[j][bit(i, j) ^ 1][i]);
    cout << res << endl;
#ifdef LOCAL
    int act = inf;
    for (int j = 0; j < n; ++j)
      if (i != j)
        act = min(act, m[i][j]);
    assert(act == res);
#endif
  }
}

void read() {
  cin >> n;
#ifdef LOCAL
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> m[i][j];
#endif
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}