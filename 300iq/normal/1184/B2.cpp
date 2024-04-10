#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1000 + 7;

vector <int> gr[N];
int mt[N];
int u[N];

bool dfs(int v) {
  if (u[v]) {
    return false;
  }
  u[v] = true;
  for (int to : gr[v]) {
    if (mt[to] == -1 || dfs(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int inf = (int) (1e9) + 7;
  vector <vector <int> > g(n, vector <int> (n, inf));
  for (int i = 0; i < n; i++) g[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a][b] = g[b][a] = 1;
  }
  for (int k = 0; k < n; k++) {
    for (int i= 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  int s, b, k, h;
  cin >> s >> b >> k >> h;
  vector <int> x(s), a(s), f(s);
  for (int i = 0; i < s; i++) {
    cin >> x[i] >> a[i] >> f[i];
    x[i]--;
  }
  for (int i = 0; i < b; i++) {
    int y, d;
    cin >> y >> d;
    y--;
    for (int j = 0; j < s; j++) {
      if (g[y][x[j]] <= f[j] && a[j] >= d) {
        gr[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < b; i++) {
    mt[i] = -1;
  }
  vector <int> arr;
  for (int i = 0; i < s; i++) {
    if (dfs(i)) {
      arr.push_back(k);
      for (int j = 0; j < s; j++) {
        u[j] = 0;
      }
    } else {
      arr.push_back(0);
    }
  }
  sort(arr.begin(), arr.end());
  ll sum = 0;
  for (int x : arr) sum += x;
  ll well = 0;
  ll ans = (ll) (1e18) + 7;
  for (int i = 0; i <= (int) arr.size(); i++) {
    ans = min(ans, sum + well);
    well += h;
    well -= arr[i];
  }
  cout << ans << '\n';
}