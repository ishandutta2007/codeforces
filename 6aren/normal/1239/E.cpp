#include<bits/stdc++.h>
using namespace std;
 
bool check[55][1500005];
vector<int> v;
int trace[55][1500005];
bool check1[55];
int a[55], res[3][55];
 
int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}
	check[0][0] = 1;
	sort(a + 1, a + 2 * n + 1);
	res[1][1] = a[1];
	res[2][n] = a[2];
	//cout << a[1] << ' ' << a[2] << endl;
	for (int i = 1; i <= 2 * n - 2; i++) {
		a[i] = a[i + 2];
	}
	for (int i = 1; i <= 2 * n - 2; i++) {
		for (int j = i - 1; j >= 0; j--) {
			for (int k = 1500000; k >= 0; k--) {
				if (check[j + 1][k]) continue;
				int t = k - a[i];
				if (t < 0) continue;
				if (check[j][t]) {
					check[j + 1][k] = 1;
					trace[j + 1][k] = i;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= 2 * n - 2; i++) {
		sum += a[i];
	}
	sum /= 2;
	int ans = 0;
	for (int i = sum; i >= 0; i--) {
		if (check[n - 1][i]) {
			ans = i;
			break;
		}
	}
	//cout << ans << endl;
	for (int i = n - 1; i >= 1; i--) {
		res[1][i + 1] = a[trace[i][ans]];
		check1[trace[i][ans]] = true;
		//cout << trace[i][ans] << ' ';
		//cout << ans << ' ';
		ans -= res[1][i + 1];
	}
	//cout << endl;
	for (int i = 1; i <= 2 * n - 2; i++) {
		if (!check1[i]) v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	//cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		res[2][i + 1] = v[v.size() - 1 - i]; 
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}