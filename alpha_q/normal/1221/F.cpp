#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000010;
const ll INF = 1e18 + 5;

int n, m; 
vector <ll> coord;
vector <int> st[N];
pair <ll, int> t[4 * N];
ll x[N], y[N], c[N], lazy[4 * N];

void init (int u = 1, int b = 1, int e = m) {
  if (b == e) return void(t[u] = {-coord[b], b});
  int mid = b + e >> 1;
  init(u << 1, b, mid), init(u << 1 | 1, mid + 1, e);
  t[u] = max(t[u << 1], t[u << 1 | 1]);
}

void push (int u, int b, int e) {
  t[u].first += lazy[u];
  if (b ^ e) {
    lazy[u << 1] += lazy[u], lazy[u << 1 | 1] += lazy[u];
  }
  lazy[u] = 0;
}

void update (int l, int r, ll v, int u = 1, int b = 1, int e = m) {
  if (lazy[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] += v;
    return push(u, b, e);
  }
  int mid = b + e >> 1;
  update(l, r, v, u << 1, b, mid);
  update(l, r, v, u << 1 | 1, mid + 1, e);
  t[u] = max(t[u << 1], t[u << 1 | 1]);
}

pair <ll, int> query (int l, int r, int u = 1, int b = 1, int e = m) {
  if (b > r or e < l) return {-INF, -1};
  if (lazy[u]) push(u, b, e);
  if (b >= l and e <= r) return t[u];
  int mid = b + e >> 1;
  return max(query(l, r, u << 1, b, mid), query(l, r, u << 1 | 1, mid + 1, e));
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld %lld", x + i, y + i, c + i);
    if (x[i] > y[i]) swap(x[i], y[i]);
    coord.emplace_back(x[i]);
    coord.emplace_back(y[i]);
  }
  sort(coord.begin(), coord.end());
  coord.erase(unique(coord.begin(), coord.end()), coord.end());
  m = coord.size(); 
  coord.insert(coord.begin(), -69696969);
  for (int i = 1; i <= n; ++i) {
    x[i] = lower_bound(coord.begin(), coord.end(), x[i]) - coord.begin();
    y[i] = lower_bound(coord.begin(), coord.end(), y[i]) - coord.begin();
    st[x[i]].emplace_back(i);
  }
  init();
  ll ans = 0; int fro = 1000000100, to = 1000000100;
  for (int i = m; i > 0; --i) {
    for (int id : st[i]) update(y[id], m, c[id]);
    pair <ll, int> yo = query(i, m);
    ll alt = yo.first + coord[i];
    if (ans < alt) ans = alt, fro = coord[i], to = coord[yo.second];
  }
  cout << ans << '\n';
  cout << fro << " " << fro << " " << to << " " << to << '\n';
  return 0;
}