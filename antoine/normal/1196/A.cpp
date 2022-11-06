#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while(q--){
		ll a,b,c;
		cin >> a >> b >> c;
		ll s = a + b + c;
		cout << s/2 << '\n';
	}
	return 0;
}