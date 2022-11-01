#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 505;

int a[N];
int b[N];
int dp[N][N];
pair <int, int> par[N][N];
int real[N * 2];
pair <int, int> pr[3][N][N * 2];
vector <int> vec;
vector <int> ans;


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vec.push_back(a[i]);
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		vec.push_back(b[i]);
	}
	sort(vec.begin(), vec.end());
	//cout << 47 << endl;
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	//cout << 48 << endl;
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
		real[x] = a[i];
		a[i] = x;
	}
	for (int i = 1; i <= m; i++) {
		int x = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
		real[x] = b[i];
		b[i] = x;
	}
	n++;
	m++;
	a[n] = vec.size();
	b[m] = vec.size();
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= vec.size(); k++) {
				pr[i % 2][j][k] = pr[1 - i % 2][j][k];
			}
		}
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k <= vec.size(); k++) {
				pr[i % 2][j][k] = max(pr[i % 2][j][k], pr[i % 2][j - 1][k]);
			//	cout << "57 " << i << " " << j << " " << k << " " << pr[i % 2][j][k].first << " " << pr[i % 2][j][k].second << endl;
			}
		//	cout << "48 " << i << " " << j << endl;
			if (a[i] == b[j]) {
				dp[i][j] = 1;
				for (int k = 0; k < a[i]; k++) {
					if (dp[pr[1 - i % 2][j - 1][k].first][pr[1 - i % 2][j - 1][k].second] + 1 > dp[i][j]) {
					//	pr[i % 2][j][k] = {i, j};
						par[i][j] = pr[1 - i % 2][j - 1][k];
						dp[i][j] = dp[pr[1 - i % 2][j - 1][k].first][pr[1 - i % 2][j - 1][k].second] + 1;
					}
				}
			//	cout << "49 " << i << " " << j << " " << dp[i][j] << endl;
				pr[i % 2][j][a[i]] = {i, j};
			}
		}
	}
	cout << dp[n][m] - 1 << endl;
	int x = n, y = m;
	while (x != 0) {
		pair <int, int> p = par[x][y];
		x = p.first, y = p.second;
	//	cout << x << " " << y << endl;
		ans.push_back(real[a[x]]);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 1; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}