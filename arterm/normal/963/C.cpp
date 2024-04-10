#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> w, h;
map<pll, ll> c;

ll gcd(ll x, ll y) {
  while (x) {
    y %= x;
    swap(x, y);
  }
  return y;
}

ll lcm(ll x, ll y) {
  if (x == 0)
    return y;
  if (y == 0)
    return x;
  return x / gcd(x, y) * y;
}

void read() {
  ll n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll x, y, cnt;
    cin >> x >> y >> cnt;
    w.push_back(x);
    h.push_back(y);
    c[make_pair(x, y)] = cnt;
  }

  sort(all(w));
  sort(all(h));

  w.erase(unique(all(w)), w.end());
  h.erase(unique(all(h)), h.end());
}

void relax(ll &x, ll &y) {
  ll g = gcd(x, y);
  x /= g;
  y /= g;
}

bool check(ll a, ll b, ll x, ll y) {
  relax(a, x);
  relax(a, y);
  relax(b, x);
  relax(b, y);
  return a == 1 && b == 1 && x == 1 && y == 1;
}

void kill() {
  ll n = w.size();
  ll m = h.size();
  if ((ll) c.size() != 1ll * n * m) {
    cout << "0\n";
    return;
  }


  vector<vector<ll>> cnt(n, vector<ll>(m, 0));
  

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cnt[i][j] = c[make_pair(w[i], h[j])];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cerr << cnt[i][j] << " \n"[j + 1 == m];


  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (!check(cnt[0][0], cnt[i][j], cnt[i][0], cnt[0][j])) {
        cout << "0\n";
        return;
      }
    }


  ll g = 0;
  for (int j = 0; j < m; ++j)
    g = gcd(g, cnt[0][j]);

  ll G = 0;
  for (int i = 0; i < n; ++i) {
    ll a = cnt[i][0];
    ll b = cnt[0][0];
    relax(a, b);
    G = lcm(G, b);
  }


  if (g % G != 0) {
    cout << "0\n";
    return;
  }

  ll x = g / G;
  ll ans = 0;
  for (ll i = 1; i * i <= x; ++i)
    if (x % i == 0) {
      ans += 2;
      if (i * i == x)
        --ans;
    }

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}