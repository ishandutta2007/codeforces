#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 2e5 + 10;

int a[N];

ll tree[4 * N];
ll ad[4 * N];
ll mn[4 * N];
ll mx[4 * N];

void recalc(int v) {
  tree[v] = tree[2 * v] + tree[2 * v + 1];
  mn[v] = min(mn[2 * v], mn[2 * v + 1]);
  mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

void push(int v, int tl, int tr) {
  if (ad[v] == -1) return;
  tree[v] = ad[v] * (tr - tl + 1);
  mn[v] = max(mn[v], ad[v]);
  mx[v] = max(mx[v], ad[v]);
  if (tl < tr) {
    ad[2 * v] = max(ad[2 * v], ad[v]);
    ad[2 * v + 1] = max(ad[2 * v + 1], ad[v]);
  }
  ad[v] = -1;
}

void build(int v, int tl, int tr) {
  ad[v] = -1;
  if (tl == tr) {
    tree[v] = a[tl];
    mn[v] = a[tl];
    mx[v] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  recalc(v);
  //cout << tl << " " << tr << " " << tree[v] << endl;
}

void upd(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (tl > r || l > tr) return;
  if (l <= tl && tr <= r) {
    if (mn[v] >= val) return;
    if (mx[v] <= val) {
      ad[v] = val;
      push(v, tl, tr);
      return;
    }
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, l, r, val);
  upd(2 * v + 1, tm + 1, tr, l, r, val);
  recalc(v);
}

// (cnt, sum_costs)
pair<int, int> get(int v, int tl, int tr, int l, int y) {
  push(v, tl, tr);
  pair<int, int> ans = {0, 0}; 
  if (tr < l) return ans;
  if (mn[v] > y) return ans;
  /*
  if (mn[v] == mx[v]) {
    ll cnt = (tr - tl + 1);
    cnt = min(cnt, (ll)y / mn[v]);
    return {cnt, cnt * mn[v]};
  }
  */
  if (tree[v] <= y && tl >= l) {
    //cout << tl << " " << tr << " " << tree[v] << endl;
    return { tr - tl + 1, tree[v] };
  }
  if (tl == tr) {
    return ans;
  }
  int tm = (tl + tr) / 2;
  auto t1 = get(2 * v, tl, tm, l, y);
  auto t2 = get(2 * v + 1, tm + 1, tr, l, y - t1.second);
  return {t1.first + t2.first, t1.second + t2.second};
}

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  build(1, 0, n - 1);

  while (q--) {
    int typ, x, y;
    cin >> typ >> x >> y;
    x--;
    if (typ == 1) {
      upd(1, 0, n - 1, 0, x, y);
    } else {
      int cur = x;
      auto tmp_val = get(1, 0, n - 1, cur, y); 
      ll answer = tmp_val.first;
      cout << answer << "\n";
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}