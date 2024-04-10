#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

point cmul(point a, point b) {
	return conj(a) * b;
}
ftype dot(point a, point b) {
	return cmul(a, b).x();
}
ftype cross(point a, point b) {
	return cmul(a, b).y();
}

bool is_square(point a, point b, point c, point d) {
	point r[4] = {a, b, c, d};
	int p[4] = {0, 1, 2, 3};
	do {
		a = r[p[0]], b = r[p[1]], c = r[p[2]], d = r[p[3]];
		b -= a;
		c -= a;
		d -= a;
		if(d * point(0, 1) == b && d + b == c && abs(cross(b, c)) > 0	) {
			return true;
		}
	} while(next_permutation(p, p + 4));
	return false;
}

void solve() {
	int x[4], y[4], a[4], b[4];
	point A[4], B[4];
	for(int i = 0; i < 4; i++) {
		cin >> x[i] >> y[i] >> a[i] >> b[i];
		A[i] = {x[i], y[i]};
		B[i] = {a[i], b[i]};
	}
	int ans = -1;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				for(int k = 0; k < 4; k++) {
					for(int l = 0; l < 4; l++) {
						if(is_square(A[0], A[1], A[2], A[3])) {
							int t = i + j + k + l;
							ans = (ans == -1 ? t : min(ans, t));
						}
						A[3] = B[3] + (A[3] - B[3]) * point(0, 1);
					}
						A[2] = B[2] + (A[2] - B[2]) * point(0, 1);
				}
						A[1] = B[1] + (A[1] - B[1]) * point(0, 1);
			}
						A[0] = B[0] + (A[0] - B[0]) * point(0, 1);
		}
	cout << ans << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		solve();
	}
	return 0;
}