#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

typedef long long ll;

const int MAX_N = 105;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll lcm (ll p, ll q) {
  return (p / gcd(p, q)) * q;
}

int nxt [MAX_N];
int vis [MAX_N];
vector<int> cycs;

void dfs (int u, int src, int d) {
  if (vis[u] && u != src) failure();
  if (vis[u] && u == src) {
    cycs.push_back(d);
    return;
  }
  vis[u] = 1;
  dfs(nxt[u], src, d + 1);
}

int main () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, i, 0);
  }

  ll ans = 1;
  for (int cyc : cycs) {
    if (cyc % 2 == 0) cyc /= 2;
    ans = lcm(ans, cyc);
  }
  cout << ans << endl;
}