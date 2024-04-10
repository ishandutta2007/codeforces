#include <iostream>
#define int long long
using namespace std;


const int N = 30;

int a[N + 5];
int b[N + 5];
int ps[N + 5];
long long chs[N + 5][N + 5];
int32_t main() {
	chs[0][0] = 1;
	for (int i = 1; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			chs[i][j] = chs[i - 1][j];
			if (j > 0) {
				chs[i][j] += chs[i - 1][j - 1];
			}
		}
	}
//	cout << chs[5][3] << endl;
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		for (int i = 0; i <= N; i++) {
			a[i] = 0;
			b[i] = 0;
			ps[i] = 0;
		}
		long long k;
		cin >> k;
		int s = 0;
		for (int i = 2; i <= N && k != 0; i++) {
			a[k % i]++;
			b[k % i]++;
			k /= i;
			s++;
		}
		int x = s;
		ps[0] = a[0];
		for (int i = 1; i < N; i++) {
			ps[i] = ps[i - 1] + a[i];
		}
		long long ans = 1;
		for (int i = N; i >= 1; i--) {
			long long y;
			if (s - i + 1 < 0) {
				if (a[i] > 0) {
					y = 0;
				}
				else {
					y = 1;
				}
			}
			else {
				y = chs[s - i + 1][a[i]];
			}
			ans *= y;
		//	cout << "73 " << i << " " << s << " " << y << endl;
			s -= a[i];
		}
	//	ans *= chs[s][a[0]];
	//	s = 0;
	//	cout << s << " " << ans << endl;
		if (b[0] == 0) {
			cout << ans - 1 << endl;
		}
		else {
			long long ans2 = 1;
			s = x - 1;
			a[0]--;
			for (int i = N; i >= 1; i--) {
				long long y;
				if (s - i + 1 < 0) {
					if (a[i] > 0) {
						y = 0;
					}
					else {
						y = 1;
					}
				}
				else {
					y = chs[s - i + 1][a[i]];
				}
				ans2 *= y;
			//	cout << "74 " << i << " " << s << " " << y << endl;
				s -= a[i];
			}
		//	ans2 *= chs[s][a[0]];
		//	cout << ans << " " << ans2 << endl;
			cout << ans - ans2 - 1 << endl;
		}
	}
	return 0;
}