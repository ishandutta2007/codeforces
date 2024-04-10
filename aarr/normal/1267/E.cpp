#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 105;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N][N];
int b[N];
vector <pair <int, int> > v[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	int ansfor = 0;
	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= m; i++) {
			v[k].push_back({a[i][n] - a[i][k], i});
		}
		v[k].push_back({inf, m + 1});
		sort(v[k].begin(), v[k].end());
		long long s = 0;
		int x;
		for (x = 0; x <= m && s <= 0; x++) {
			s += v[k][x].first;
		}
		b[k] = x;
		if (b[k] > b[ansfor]) {
			ansfor = k;
		}
	//	cout << "73 " << k << " " << x << endl;
	}
	cout << m - b[ansfor] + 1 << endl;
	for (int i = b[ansfor] - 1; i < m; i++) {
		cout << v[ansfor][i].second << " ";
	}
	return 0;
}