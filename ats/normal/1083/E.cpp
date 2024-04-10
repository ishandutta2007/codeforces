#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

const ll INF = 8 * TEN(18);

using P = pair<ll, ll>;

#define int long long

ll dist(const pair<P, int>  &a, const pair<P, int>  &b) {
	ll dx = abs(a.first.first - b.first.first);
	return dx * b.first.second - b.second;
}

int n;
V<ll> dp;
vector<pair<P, int> > ps;
void solve2(int l, int r, int a, int b) {
	if (l == r) return;
	int md = (l + r) / 2;
	ll ma = -INF; int mi = -1;
	for (int i = a; i < b; i++) {
		ll cst = dp[i + 1] + dist(ps[md], ps[i + 1]);
		if (cst > ma) {
			ma = cst;
			mi = i;
		}
	}
	dp[md] = max(dp[md], ma);
	solve2(l, md, a, mi + 1);
	solve2(md + 1, r, mi, b);
}

void solve(int l, int r) {
	if (r - l == 1) {
		dp[l] = max(dp[l], dist(ps[l], ps[l + 1]) + dp[r]);
		return;
	}
	int md = (l + r) / 2;
	solve(md, r);
	solve2(l, md, md, r);
	solve(l, md);
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(20) << fixed;

	cin >> n; 
	dp = V<ll>(n + 1, 0); dp[n] = 0;
	ps.resize(n + 1);
	
	for (int i = 0; i < n; i++) {
		cin >> ps[i + 1].first.first >> ps[i + 1].first.second >> ps[i + 1].second;
	}

	ps[0].first.first = 0;
	ps[0].first.second = (int)1 << 40;
	ps[0].second = 0;
	sort(ps.begin(), ps.end());
	solve(0, n);
	/*for (int i = 0; i <= n; i++) {
		cerr << dp[i] << " ";
	}
	cerr << endl;*/
	cout << dp[0] << endl;
	return 0;
}