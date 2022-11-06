#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, a[2];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;while(n--) {

		int x;
		cin >> x;++a[x&1];
	}
	cout << min(a[0], a[1]);
	return 0;
}