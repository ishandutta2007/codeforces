#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, l, r;
	cin >> n >> l >> r;

	{
		int x = (1 << l) - 1;
		x += (n - l);
		cout << x <<' ';
	}

	{
		ll x = (1 << r) - 1;
		x += (n-r) * (1LL << (r-1));
		cout << x;
	}
	return 0;
}