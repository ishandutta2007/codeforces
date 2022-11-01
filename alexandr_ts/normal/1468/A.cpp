#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll max_on_suf[N];

ll tree[4 * N];

void upd(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    tree[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm) {
    upd(2 * v, tl, tm, pos, val);
  } else {
    upd(2 * v + 1, tm + 1, tr, pos, val);
  }
  tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  if (tl > r || l > tr) return 0;
  if (l <= tl && tr <= r) return tree[v];
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int solve(const vector<ll>& a) {
  int n = a.size();
  fill(tree, tree + 4 * n + 10, 0);
  vector<ll> max_on_suf(n + 1);

  max_on_suf[n] = -INF;
  for (int i = n - 1; i >= 0; --i) {
    max_on_suf[i] = max(max_on_suf[i + 1], a[i]);
  }

  map<int, vector<int>> is_lb_for;
  vector<ll> left_bigger(n, -INF);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
    if (!st.empty()) {
      left_bigger[i] = st.back();
      is_lb_for[st.back()].push_back(i);
    }
    st.push_back(i);
  }

  /*
  for (auto [x, y]: is_lb_for) {
    cout << x << ": ";
    for (auto v: y) cout << v << ", ";cout << endl;
  }
  */

  vector<int> memo(n + 1, 0);

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int mx = get(1, 0, n, 0, a[i]) + 1;
    mx = max(mx, memo[i]);
    ans = max(ans, mx);

    for (auto u: is_lb_for[i]) {
      memo[u] = get(1, 0, n, 0, a[u]) + 2;
      //cout << "memo[" << u << "]: " << memo[u] << endl;
    }

    upd(1, 0, n, a[i], mx);
  }

  return ans;
}

int solveTL(const vector<ll>& a) {
  int ans = 0;
  int n = a.size();
  for (int mask = 1; mask < (1 << n); ++mask) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        v.push_back(a[i]);
      }
    }
    bool ok = true;
    for (int i = 1; i + 1 < v.size(); ++i) {
      if (min(v[i - 1], v[i]) > min(v[i], v[i + 1])) ok = false;
    }
    if (ok) {
      ans = max(ans, (int)v.size());
    }
  }
  return ans;
}

void stress() {
  int done = 0;
  mt19937 gen;
  while (true) {
    int n = gen() % 5 + 1;
    vector<ll> a(n);
    for (auto& x: a) {
      x = gen() % n + 1;
    }
    int c1 = solve(a);
    int c2 = solveTL(a);
    if (c1 != c2) {
      cout << "tl: " << c2 << ", my: " << c1 << endl;
      cout << n << endl;
      for (auto x: a) cout << x << " ";
      cout << endl;
      assert(c1 == c2);
    }
  } 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

//  stress();

	int t = 1;
  cin >> t;
	while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x: a) cin >> x;
		cout << solve(a) << "\n";
	}
}