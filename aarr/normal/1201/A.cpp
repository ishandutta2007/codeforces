#include <iostream>
using namespace std;


const int N = 1005;


int a[N][7];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[j][s[j] - 'A']++;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int x, maxi = 0;
		cin >> x;
		for (int j = 0; j < 5; j++) {
			maxi = max(maxi, a[i][j]);
		}
		ans += maxi * x;
	}
	cout << ans;
	return 0;
}