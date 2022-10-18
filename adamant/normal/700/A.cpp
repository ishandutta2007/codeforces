#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, v1, v2, k, L;
	cin >> n >> L >> v1 >> v2 >> k;
	int t = (n + k - 1) / k;
	double l = 0, r = L;
	for(int i = 0; i < 200; i++) {
		double ll = (l + r) / 2;
		double t1 = ll / v2;
		double t2 = (ll - t1 * v1) / (v1 + v2);
		double LL = (t1 + t2) * v1;
		double last_start = LL * (t - 1);
		if(last_start + ll < L) {
			l = ll;
		} else {
			r = ll;
		}
		
	}
	double ll = (l + r) / 2;
	cout << fixed << setprecision(12);
	cout << ll / v2 + (L - ll) / v1 << endl;
	return 0;
}