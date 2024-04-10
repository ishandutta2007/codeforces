#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e5 + 10;

int inter_len(int l1, int r1, int l2, int r2) {
  int l = max(l1, l2);
  int r = min(r1, r2);
  if (l > r) return 0;
  return (r - l + 1);
}

inline int dist(int l1, int r1, int l2, int r2) {
  return abs(l1 + r1 - l2 - r2);
}

int t[N], ad[N], a[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
      ad[v] = 0;
      return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
    ad[v] = 0;
}

inline void push(int v, int tl, int tr) {
    if (!ad[v])
        return;
    if (tl == tr) {
        t[v] += ad[v];
        ad[v] = 0;
        return;
    }
    t[v] += ad[v] * (tr - tl + 1);
    ad[2 * v] += ad[v], ad[2 * v + 1] += ad[v];
    ad[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (tl > r || l > tr)
        return;
    if (l <= tl && tr <= r) {
        ad[v] += x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, x);
    add(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
}

int getSum(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (tl > r || l > tr)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return getSum(2 * v, tl, tm, l, r) + getSum(2 * v + 1, tm + 1, tr, l, r);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> segs(m);
  for (int i = 0; i < m; ++i) {
    cin >> segs[i].first >> segs[i].second;
  }
  sort(segs.begin(), segs.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first + lhs.second < rhs.first + rhs.second; 
  });

  if (k == n) {
    ll ans = 0;
    for (auto& s: segs) {
      ans += (s.second - s.first + 1);
    }
    cout << ans << "\n";
    return;
  }

  ll ans = 0;
  for (int l1 = 1; l1 + k - 1 < n; ++l1) {
    int r1 = l1 + k - 1;
    int ptr = 0;
    ll sum_inter_1 = 0;
    int l2 = l1 + 1;
    int r2 = l2 + k - 1;
    fill(a, a + n + 1, 0);
    for (int i = 0; i < m; ++i) {
      if (dist(l1, r1, segs[i].first, segs[i].second) <= dist(l2, r2, segs[i].first, segs[i].second)) {
        sum_inter_1 += inter_len(segs[i].first, segs[i].second, l1, r1);
        ptr = i + 1;
      } else {
        a[segs[i].first]++;
        a[segs[i].second + 1]--;
      }
    }
    for (int i = 1; i <= n; ++i) {
      a[i] += a[i - 1]; 
    }
    build(1, 0, n);

    for (; l2 + k - 1 <= n; ++l2) {
      r2 = l2 + k - 1;
      while (ptr < m && dist(l1, r1, segs[ptr].first, segs[ptr].second) <= dist(l2, r2, segs[ptr].first, segs[ptr].second)) {
        add(1, 0, n, segs[ptr].first, segs[ptr].second, -1);
        sum_inter_1 += inter_len(segs[ptr].first, segs[ptr].second, l1, r1);
        ptr++;
      } 
      int sum_inter_2 = getSum(1, 0, n, l2, r2);
        /*
      if (l1 == 1) {
        cout << "l2: " << l2 << "(ptr=" << ptr <<  "), sum1: " << sum_inter_1 << ", sum2: " << sum_inter_2 << endl;
      }
      */
      ans = max(ans, sum_inter_1 + sum_inter_2);
    }
  }
  cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}