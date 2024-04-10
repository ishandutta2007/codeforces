// https://codeforces.com/contest/1257/submission/64860800

#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define int unsigned int
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (register int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (register int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 110;
vector <int> a;
main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a.resize(n);
	rep(i, n) cin >> a[i];
	a.resize(unique(a.begin(), a.end()) - a.begin());
	rep(i, lsh(30)) {
		int cnt = __builtin_popcount(a[0] ^ i);
		bool bad = false;
		rep(j, a.size()) if (__builtin_popcount(a[j] ^ i) != cnt) {
			bad = true;
			break;
		}
		if (!bad) {
			cout << i << endl;
			return 0;
		}
	} 
	cout << -1 << endl;
	return 0;
}