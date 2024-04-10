#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	if(m >= 5) {
		vector<int> a(m), b(m);
		for(int i = 0; i < (m + 1) / 2; i++) a[i] = 2 * i + 1;
		for(int i = 0; i < m / 2; i++) a[(m + 1) / 2 + i] = 2 * i + 2;
		for(int i = 0; i < m / 2; i++) b[i] = 2 * i + 2;
		for(int i = 0; i < (m + 1) / 2; i++) b[m / 2 + i] = 2 * i + 1;
		cout << "YES\n";
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < m; j++)
				cout << (i % 2 ? b[j] : a[j]) + m * i << ' ';
	} else if(n >= 5) {
		vector<int> a(n), b(n);
		for(int i = 0; i < (n + 1) / 2; i++) a[i] = 2 * i + 1;
		for(int i = 0; i < n / 2; i++) a[(n + 1) / 2 + i] = 2 * i + 2;
		for(int i = 0; i < n / 2; i++) b[i] = 2 * i + 2;
		for(int i = 0; i < (n + 1) / 2; i++) b[n / 2 + i] = 2 * i + 1;
		vector<vector<int>> r(n, vector<int>(m));
		for(int j = 0; j < m; j++)
			for(int i = 0; i < n; i++) {
				r[i][j] = (j % 2 ? b[i] : a[i]);
				r[i][j] = (r[i][j] - 1) * m + j + 1;
			}
		cout << "YES\n";
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < m; j++)
				cout << r[i][j] << ' ';
	} else {
		if(n == 1 && m == 1) return cout << "YES\n1", 0;
		if(n == 3 && m == 3) return cout << "YES\n6 1 8\n7 5 3\n2 9 4", 0;
		if(n == 1 && m == 4) return cout << "YES\n2 4 1 3", 0;
		if(n == 4 && m == 1) return cout << "YES\n2\n4\n1\n3", 0;
		if(n == 3 && m == 4) return cout << "YES\n1 8 2 4\n6 11 5 7\n9 3 10 12", 0;
		if(n == 4 && m == 3) return cout << "YES\n1 5 3\n11 9 7\n4 2 6\n10 8 12", 0;
		if(n == 4 && m == 4) return cout << "YES\n1 16 2 4\n6 3 5 7\n9 8 10 12\n14 11 13 15", 0;
		if(n == 2 && m == 4) return cout << "YES\n1 8 2 4\n6 3 5 7", 0;
		if(n == 4 && m == 2) return cout << "YES\n1 4\n8 5\n3 2\n7 6", 0;
		cout << "NO";
	}
}