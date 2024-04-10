#include <bits/stdc++.h>
using namespace std;

const int L = 60, N = 100 * 1000 + 5;
int t = 0;

long long get(long long x, int y) {
	return (x >> y) & 1;
}

long long a[L];
long long b[L];
long long e[N];
int d[N];
vector <int> vec;


int main() {
	int n;
	cin >> n;
	long long xall = 0;
	for (int i = 0; i < n; i++) {
		cin >> e[i];
		xall ^= e[i];
	}
//	cout << "74 " << xall << endl;
	for (int i = L - 1; i >= 0; i--) {
		if (!get(xall, i)) {
			vec.push_back(i);
		}
	}
	for (int i = L - 1; i >= 0; i--) {
		if (get(xall, i)) {
			vec.push_back(i);
		}
	}	
	for (int i = 0; i < n; i++) {
		long long x = e[i], y = 0;
		xall ^= x;
		d[i] = -1;
		for (auto j : vec) {
			if (get(x, j)) {
				if (a[j] == 0) {
					a[j] = x;
					y ^= (1ll << t);
					d[i] = t;
					t++;
					b[j] = y;
					break;
				}
				else {
					x ^= a[j];
					y ^= b[j];
				}
			}
		}
	}
//	for (int j = 0; j < L; j++) {
//		cout << "71 " << j << " " << a[j] << " " << b[j] << endl;
//	}
/*	long long ans = 0;
	for (int j = L - 1; j >= 0; j--) {
		if (a[j] && !get(ans, j)) {
	//		cout << "72 " << j << " " << a[j] << endl;
			ans ^= a[j];
		}
	}
	cout << ans;*/
	long long ans = 0, mask = 0, nt = 0;
/*	for (int i = L - 1; i >= 0; i--) {
		nt ^= (1ll << i);
		if (!get(xall, i)) {
			if (a[i] && !get(ans, i)) {
				ans ^= a[i];
				mask ^= b[i];
			}
		}
	}
	for (int i = L - 1; i >= 0; i--) {
		if (get(xall, i)) {
			if (a[i] && !get(ans, i) && ((nt & a[i]) == 0)) {
				ans ^= a[i];
				mask ^= b[i];
			}
		}
	}*/
	for (auto j : vec) {
		if (a[j] && !get(ans, j)) {
	//		cout << "72 " << j << " " << a[j] << endl;
			mask ^= b[j];
			ans ^= a[j];
		}
	}	
	for (int i = 0; i < n; i++) {
		if (d[i] != -1 && get(mask, d[i])) {
			cout << "2 ";
		}
		else {
			cout << "1 ";
		}
	}
	return 0;
}