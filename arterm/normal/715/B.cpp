#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 10100;
const ll inf = 1e18;

int n, m;
int xr[M];
int u[M], v[M];
ll len[M];
ll l;
int s, t;
vector<int> g[M];
vector<int> add;
ll d[M];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
bool used[M];

void read() {
  cin >> n >> m;
  cin >> l >> s >> t;

  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back(i);
    g[y].push_back(i);

    u[i] = x, v[i] = y;
    xr[i] = x ^ y;
    len[i] = w;
    if (w == 0)
      add.push_back(i);
  }
}

void assign(ll sum) {
  for (int id : add) {
    len[id] = min(sum, l) + 1;
    sum -= min(sum, l);
  }
}


ll dij() {
  q.emplace(0, s);
  fill(d, d + n, inf);
  d[s] = 0;
  fill(used, used + n, false);

  while (!q.empty()) {

    int u = q.top().second;
    q.pop();

    if (used[u])
      continue;

    used[u] = true;

    for (int i : g[u]) {
      int to = xr[i] ^ u;
      ll w = len[i];

      if (d[to] > d[u] + w) {
        d[to] = d[u] + w;
        q.emplace(d[to], to);
      }
    }
  }

  return d[t];
}

void kill() {
  ll le = 0, re = l * add.size();

  while (le < re) {
    ll me = (le + re) / 2;
    assign(me + 1);
    if (dij() > l)
      re = me;
    else
      le = me + 1;
  }

  assign(le);

  if (dij() != l) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for (int i = 0; i < m; ++i) {
    cout << u[i] << " " << v[i] << " " << len[i] << "\n";
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}