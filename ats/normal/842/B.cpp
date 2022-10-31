#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	int d, r;
	cin >> r >> d;
	int n;
	cin >> n;
	int res = 0;
	int x, y, ri;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> ri;
		if ((ri*2 <= d) && (r>=ri) &&(x*x + y*y >= (r - d + ri)*(r - d + ri) && (x*x + y*y <= (r - ri)*(r - ri)))) {
			res++;
		}
	}

	cout << res << endl;
	return 0;
}