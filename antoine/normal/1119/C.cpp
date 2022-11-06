#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, m;

auto in() {
	vector<vector<int>> a(n, vector<int>(m));
	for (vector<int> &v : a)
		for (int &x : v)
			cin >> x;
	return a;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	auto a = in(), b = in();
	for(int  i= 0;  i < n - 1; ++i)
		for(int j = 0; j < m - 1; ++j)
			if(a[i][j] != b[i][j]) {
				a[i][j] ^= 1;
				a[i+1][j] ^= 1;
				a[i][j+1] ^= 1;
				a[i+1][j+1] ^= 1;
			}

	cout << (a==b?"Yes":"No");
	return 0;
}