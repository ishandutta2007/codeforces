#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int N = 200 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;
int n, t, x, y;

pair <int, int> a[N];
signed main() {
	ios :: sync_with_stdio(false);
	int q;
	cin >> q;
	for (int ii = 0; ii < q; ii++) {
		cin >> n >> t >> x >> y;
		int n0 = 0, n1 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].second;
			if (a[i].second == 0) {
				n0++;
			}
			else {
				n1++;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i].first;
		/*	if (b[i] == 0) {
				vec1.push_back(a[i]);
			}
			else {
				vec2.push_back(a[i]);
			}*/
		}
	//	sort(vec1.begin(), vec1.end());
	//	sort(vec2.begin(), vec2.end());
		sort(a + 1, a + n + 1);
		int ans = 0, s = 0;
		a[n + 1].first = t + 1;
		int c = a[1].first - 1;
			int z = 0;
			if ((c) >= 1ll * n0 * x) {
				z = 0 + n0;
				z += min((c - n0 * x) / y, n1);
				ans = max(ans, z);
			}
			else {
				z = min(0 + (c) / x, n0);
				ans = max(ans, z);
			}
		for (int i = 1; i <= n; i++) {
			int d;
			if (a[i].second == 0) {
				d = x;
				n0--;
			}
			else {
				d = y;
				n1--;
			}
			s += d;
			if (s >= a[i + 1].first) {
			//	cout << "49 " << i << " " << s << endl;
				continue;
			}
			int c = a[i + 1].first - s - 1;
			int z = 0;
			if ((c) >= 1ll * n0 * x) {
				z = i + n0;
				z += min((c - n0 * x) / y, n1);
				ans = max(ans, z);
			}
			else {
				z = i + min((c) / x, n0);
				ans = max(ans, z);
			}
		//	cout << "73 " << i << " " << z << endl;
		}
		cout << ans << '\n';
	}
	return 0;
}