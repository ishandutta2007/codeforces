#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v)  << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k, m, t;
	cin >> n >> k >> m >> t;
	while (t--) {
		int type, i;
		cin >> type >> i;
		if(type==1) {
			n++;
			k += i <= k;
		} else {
			assert(type==0);
			if(i < k ){
				n -= i;
				k -= i;
			} else {
				n = i;
			}
		}
		cout << n << ' ' <<k << '\n';
	}
	return 0;
}