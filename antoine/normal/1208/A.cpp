#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		int a, b, n;
		cin >> a >> b >> n;
		cout << vector<int>{a,b,a^b}[n%3] << '\n';
	}
	return 0;
}