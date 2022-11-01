#include <bits/stdc++.h>
using namespace std;


const int N = 400 * 1000 + 5, LG = 25, M = 40 * 1000 * 1000 + 7;
int b[M];
int a[N];


int main() {
	ios :: sync_with_stdio(false);
	int ans = 0, n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
/*	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j <= LG; j++) {
			int y = 1 << (j - 1), z = y << 1, t = x % z;
			int l = y + z - t, r = z * 2 - t, q = 0;
			l %= z, r %= z;
		//	pair <int, int> p = {r, 0};
			q += get(j, 0, r, 1, 0, z);
			q -= get(j, 0, l, 1, 0, z);
			if (l > r) {
				q += i;
			}
			q %= 2;
			if (q) {
				ans ^= 1 << (j - 1);
			}
		}
		for (int j = 1; j <= LG; j++) {
		//	s[j].insert({x % (1 << j), i});
			update(j, x % (1 << j), 1, 0, 1 << j);
			cout << i << " " << j << endl;
		}
	}*/
	for (int j = 1; j <= LG; j++) {
	//	cout << j << endl;
		for (int i = 0; i <= 1 << j; i++) {
			b[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			b[a[i] % (1 << j)]++;
		}
		for (int i = 1; i < 1 << j; i++) {
			b[i] += b[i - 1];
		}
		long long q = 0, q2 = 0;
		for (int i = 1; i <= n; i++) {
			int y = 1 << (j - 1), z = y << 1, t = a[i] % z;
			int l = y + z - t, r = z * 2 - t;
			l %= z, r %= z;
		//	pair <int, int> p = {r, 0};
			if (r > 0)
				q += b[r - 1];
			if (l > 0)
				q -= b[l - 1];
			if (l > r) {
				q += n;
			}
			if (t * 2 % z >= y) {
			//	q2++;
				q--;
			} 		
		}
	//	cout << j << " " << q << " " << q2 << endl;
		q /= 2;
	//	q += q2;
		if (q % 2) {
			ans ^= (1 << (j - 1));
		}
	}
	cout << ans;
	return 0;
}