#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> st(60);
	st[0] = 1;
	for (int i = 1; i < 60; ++i)
		st[i] = st[i - 1] * 2;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int d = 0, s = 0;
		for (int i = 1; i < 60; ++i) {
			if (s + st[i] > n - 1) {
				d = i - 1;
				break;
			}
			s += st[i];
		}
		if (d == 0) {
			cout << 1 << "\n";
			cout << 0 << "\n";
		}
		else if (s == n - 1) {
			cout << d << "\n";
			for (int i = 0; i < d; ++i)
				cout << st[i] << ' ';
			cout << "\n";
		}
		else {
			int x = n - 1 - s;
			cout << d + 1 << "\n";
			int s2 = 1;
			int f = 1;
			int m = 1;
			if (x == 1)
				cout << 0 << ' ';
			for (int i = 0; i < d+1; ++i) {
				if (f && s2 < x && s2 + st[i] >= x) {
					cout << x - s2 << ' ';
					m += x;
					if (m == n)
						break;
					cout << st[i] - (x - s2) << ' ';
					s2 = st[i];
					f = 0;
				}
				else if(i != d){
					cout << st[i] << ' ';
					s2 += st[i];
					m += s2;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}