#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int mn[N], mx[N], a[N];

int v[N];
bool can_move[N];

int maxinc(const vector<int>& v) {
	int n = v.size();
	vector<int> ps(n + 1, INF);
	ps[0] = -INF;
	for (auto x: v) {
		int id = upper_bound(ps.begin(), ps.end(), x) - ps.begin();
		ps[id] = x;
	}
	for (int i = n; i >= 0; --i) {
		if (ps[i] != INF) return i;
	}
	assert(false);
	return 0;
}

int calc(int l, int r) {
	if (l > r) return 0;
	//cout << l << " " << r << endl;
	int n = r - l + 1;
	copy(a + l, a + r + 1, v);
	for (int i = l; i <= r; ++i) {
		if (a[i] >= mn[i] && a[i] <= mx[i]) {
			can_move[i - l] = true;
		} else {
			can_move[i - l] = false;
		}
	}

	vector<int> to_count;
	for (int i = 0; i < n; ++i) {
		v[i] -= i;
		if (can_move[i]) {
			to_count.push_back(v[i]);
		}
	}
	/*
	cout << "tocount: "; for (auto x: to_count) {
		cout << x << " ";
	}
	cout << endl;
	*/
	int val = maxinc(to_count);
	//cout << "val: " << val << endl;
	return n - val;
}

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> cst;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
	}
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		cst.insert(x - 1);
	}

	fill(mn, mn + n, -INF);
	fill(mx, mx + n, INF);
	for (int i = 0; i < n; ++i) {
		if (cst.count(i)) {
			mn[i] = a[i];
		}	
		if (i > 0) {
			mn[i] = max(mn[i], mn[i - 1] + 1);
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		if (cst.count(i)) {
			mx[i] = a[i];
		}
		if (i + 1 < n) {
			mx[i] = min(mx[i], mx[i + 1] - 1);
		}
	}
	/*
	for (int i = 0; i < n; ++i) {
		cout << mn[i] << " " << mx[i] << endl;
	}
	*/

	for (int i = 0; i < n; ++i) {
		if (mn[i] > mx[i]) {
			cout << "-1\n";
			return;
		}
	}

	cst.insert(-1);
	cst.insert(n);
	int ans = 0;
	for (auto it = cst.begin(); it != cst.end(); ++it) {
		ans += calc((*it) + 1, (*next(it)) - 1);
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}