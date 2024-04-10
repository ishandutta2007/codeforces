#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll x,y, res = 1;
	const int mod = 998244353;
	cin >> x>>y;
	for(int i = 0; i < x + y; ++i)
		(res *= 2) %= mod;
	cout << res;

	return 0;
}