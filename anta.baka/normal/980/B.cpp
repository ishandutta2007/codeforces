#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int INF = 1e9, maxn = 1e6;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, k; cin >> m >> k;
	vector<vector<char>> a(4, vector<char>(m, '.'));
	cout << "YES\n";
	if(k % 2 == 0) {
		for(int j = 1; k; j++) {
			a[1][j] = a[2][j] = '#';
			k -= 2;
		}
	} else if(k <= m - 2) {
		a[1][m / 2] = '#';
		k--;
		for(int j = 1; k; j++) {
			a[1][m / 2 - j] = a[1][m / 2 + j] = '#';
			k -= 2;
		}
	} else {
		k++;
		for(int j = 1; k; j++) {
			a[1][j] = a[2][j] = '#';
			k -= 2;
		}
		a[1][2] = '.';
	}
	for(int i = 0; i < 4; i++, cout << endl)
		for(int j = 0; j < m; j++)
			cout << a[i][j];
}