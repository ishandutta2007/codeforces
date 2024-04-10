#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int mod = 1e9 + 7, maxn = 1e6;

struct segTree {
	int n; vector<int> t;
	segTree(int n) : n(n), t(2 * n, 0) {}
	void upd(int v, int x) {
		t[v += n] = x;
		for(v >>= 1; v; v >>= 1) t[v] = (t[v * 2] + t[v * 2 + 1]) % mod;
	}
	int get(int l, int r) {
		int ret = 0;
		for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if(l & 1) ret = (ret + t[l]) % mod;
			if(!(r & 1)) ret = (ret + t[r]) % mod;
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	segTree t(maxn);
	vector<int> dp(maxn, 0);
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		int cur = t.get(0, x - 1);
		cur = (cur + 1) % mod;
		dp[x - 1] = ll(cur) * x % mod;
		t.upd(x - 1, dp[x - 1]);
	}
	int ans = 0;
	for(int i = 0; i < maxn; i++) ans = (ans + dp[i]) % mod;
	cout << ans;
}