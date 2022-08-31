#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 2e5 + 7;

vector <int> g[N], rg[N];

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    rg[b].push_back(a);
  }
  int k;
  cin >> k;
  vector <int> p(k);
  for (int i = 0; i < k; i++) {
    cin >> p[i];
    p[i]--;
  }
  int s = p[0], t = p.back();
  queue <int> q;
  q.push(t);
  vector <int> d(n, -1);
  d[t] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to : rg[v]) {
      if (d[to] == -1) {
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
  int l = 0, r = 0;
  for (int i = 0; i + 1 < k; i++) {
    if (d[p[i + 1]] != d[p[i]] - 1) {
      l++;
    }
    for (int j : g[p[i]]) {
      if (j != p[i + 1] && d[j] == d[p[i]] - 1) {
        r++;
        break;
      }
    }
  }
  cout << l << ' ' << r << endl;
}