#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n, k;
	cin >> n >> k;
	ll curr = 1;
	while (k != -n) {
		n--;
		k -= curr;
		curr++;
	}
// DBG(k)
	// assert(n >= 0 && k == 0);
	cout << n;
	return 0;
}