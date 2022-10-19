#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 10100;

int n, p[M];
int c[M];
vector<int> a[M];
vector<pair<int, int>> ans;

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
}

void add(int u, int v) {
  ans.emplace_back(u, v);
}

void kill() {
  for (int i = 0; i < n; ++i) {
    c[i] = min(p[i], p[p[i]]);
    a[c[i]].push_back(i);
  }

  int res = 0;

  for (int v = 0; v < n; ++v)
    if (!a[v].empty()) {
      ++res;
      /*
      int u = p[v];

      if (a[v].size() == 1)
        continue;

      if (a[v].size() == 2) {
        add(u, v);
        continue;
      }

      vector<int> U, V;
      for (int x : a[v])
        if (x != u && x != v) {
          if (p[x] == u)
            U.push_back(x);
          else
            V.push_back(x);
        }

      if (U.empty()) {
        int x = V.back();
        V.pop_back();
        add(v, x);
        add(u, x);
        for (int y : V)
          add(x, y);
        continue;
      }

      int tv = V.back();
      V.pop_back();
      int tu = U.back();
      U.pop_back();

      add(v, tv);
      add(tv, tu);
      add(tu, u);
      for (int y : V)
        add(tv, y);
      for (int y : U)
        add(tu, y);
      */
    }

  cout << res << endl;
  return;

  //cout << ans.size() << "\n";
  //for (auto e : ans) {
    //cout << e.first << " " << e.second << "\n";
  //}
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}