#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		int m = 0;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			m = max(m, a[j]);
		}		
		vector<int> p21(m), p22(n - m);
		vector<int> p11(m), p12(n - m);
		for (int j = 0; j < m; ++j) {
			p21[j] = 0;
			p11[j] = 0;
		}
		for (int j = 0; j < n - m; ++j) {
			p22[j] = 0;
			p12[j] = 0;
		}
		pair<bool, bool>sp = { true, true };
		for (int j = 0; j < m; ++j) 
			p11[a[j] - 1] = 1;
		for (int j = m; j < n; ++j) {
			if (a[j] > n - m)
				break;
			p12[a[j] - 1] = 1;
		}
		for (int j = 0; j < m; ++j) {
			if (p11[j] != 1)
				sp.first = false;
		}
		for (int j = 0; j < n - m; ++j) {
			if (p12[j] != 1)
				sp.first = false;
		}
		for (int j = n - 1; j >= n-m; --j) 
			p21[a[j] - 1] = 1;
		for (int j = n - m - 1; j >= 0; --j) {
			if (a[j] > n - m)
				break;
			p22[a[j] - 1] = 1;
		}
		for (int j = 0; j < m; ++j)
			if (p21[j] != 1)
				sp.second = false;
		for (int j = 0; j < n-m; ++j)
			if (p22[j] != 1)
				sp.second = false;
		if (sp.first && sp.second) {
			if (m != n - m) {
				cout << 2 << endl;
				cout << m << ' ' << n - m << endl;
				cout << n - m << ' ' << m << endl;
			}
			else {
				cout << 1 << endl;
				cout << m << ' ' << n - m << endl;
			}
		}
		else if (sp.first) {
			cout << 1 << endl;
			cout << m << ' ' << n - m << endl;
		}
		else if (sp.second) {
			cout << 1 << endl;
			cout << n - m << ' ' << m << endl;
		}
		else
			cout << 0 << endl;
	
	}
	return 0;
}