#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int> > mat;
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	mat.resize(n);
	int c1[2];
	c1[0] = 0;
	c1[1] = 0;
	for (int i = 0; i < n; i++) {
		mat[i].resize(m, 0);
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			
			c1[mat[i][j]]++;
		}
	}

	int res = 0;
	int c[2];
	
	for (int i = 0; i < n; i++) {
		c[0] = 0;
		c[1] = 0;
		for (int j = 0; j < m; j++) {
			c[mat[i][j]]++;
		}
		res += ((int)1 << c[0]) - 1;
		res += ((int)1 << c[1]) - 1;
	}

	for (int j = 0; j < m; j++) {
		c[0] = 0;
		c[1] = 0;
		for (int i = 0; i < n; i++) {
			c[mat[i][j]]++;
		}
		res += ((int)1 << c[0]) - 1;
		res += ((int)1 << c[1]) - 1;
	}
	res -= c1[0] + c1[1];
	cout << res << endl;
	return 0;
}