#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e16;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

struct SegTree {
  SegTree(int n) : n(n) {
    t = vector<ll>(4 * n);
  }

  void upd(int v, int pos, ll val, int tl, int tr) {
    if (tl == tr) {
      t[v] = val;
      return;
    } 
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      upd(2 * v, pos, val, tl, tm);
    } else {
      upd(2 * v + 1, pos, val, tm + 1, tr);
    }
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }

  ll get_max(int v, int l, int r, int tl, int tr) {
    if (l > tr || tl > r) return -INF;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return max(get_max(2 * v, l, r, tl, tm), get_max(2 * v + 1, l, r, tm + 1, tr));
  }

  int n;
  vector<ll> t;
};

vector<ll> prec_left_small(const vector<int>& h) {
  int n = (int)h.size();
  vector<ll> ans(n);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && h[st.back()] >= h[i]) {
      st.pop_back();
    }
    if (st.empty()) {
      ans[i] = INF;
    } else {
      ans[i] = st.back();
    }
    st.push_back(i);
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> h(n);
  vector<int> b(n);
  for (auto& x: h) cin >> x;
  for (auto& x: b) cin >> x;

  SegTree t(n + 1);
  vector<ll> dp(n + 1);
  vector<ll> left_small = prec_left_small(h);
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = dp[i] + b[i];
    int r = 0;
    if (left_small[i] != INF) {
      r = left_small[i] + 1;
    }
    if (left_small[i] != i - 1) {
      dp[i + 1] = max(dp[i + 1], t.get_max(1, r, i, 0, n) + b[i]);
    }
    if (left_small[i] != INF) {
      dp[i + 1] = max(dp[i + 1], dp[left_small[i] + 1]);
    }
    t.upd(1, i + 1, dp[i + 1], 0, n);
  }
  cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}