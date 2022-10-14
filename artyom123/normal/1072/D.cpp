#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <vector<int>> dp(n, vector <int> (n));
	vector <vector<char>> a(n, vector <char> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	if (a[0][0] == 'a') {
		dp[0][0] = 0;
	}
	if (a[0][0] != 'a') {
		dp[0][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && j > 0) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
				if (a[i][j] != 'a') {
					dp[i][j]++;
				}
			}
			if (i == 0 && j > 0) {
				dp[i][j] = dp[i][j - 1];
				if (a[i][j] != 'a') {
					dp[i][j]++;
				}
			}
			if (i > 0 && j == 0) {
				dp[i][j] = dp[i - 1][j];
				if (a[i][j] != 'a') {
					dp[i][j]++;
				}
			}
		}
	}
	string ans = "";
	int max_a = 0;
	vector <pair<int, int>> now;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] <= k) {
				if (i + j + 1 == max_a) {
					now.push_back({i, j});
				}
				if (i + j + 1 > max_a) {
					now.clear();
					now.push_back({i, j});
				}
				max_a = max(max_a, i + j + 1);
			}
		}
	}
	for (int i = 0; i < max_a; i++) {
		ans += 'a';
	}
	if (max_a == 0) {
		now.push_back({0, 0});
		ans += a[0][0];
	}
	vector <vector<bool>> usd(n, vector <bool> (n));
	while (1) {
		char min_let = 'z';
		vector <pair<int, int>> now1;
		for (int i = 0; i < now.size(); i++) {
			if (now[i].first < n - 1 && now[i].second < n - 1) {
				if (a[now[i].first][now[i].second + 1] < min_let && usd[now[i].first][now[i].second + 1] == 0) {
					min_let = a[now[i].first][now[i].second + 1];
					now1.clear();
					now1.push_back({now[i].first, now[i].second + 1});
					usd[now[i].first][now[i].second + 1] = 1;
				}
				else if (a[now[i].first][now[i].second + 1] == min_let && usd[now[i].first][now[i].second + 1] == 0){
					now1.push_back({now[i].first, now[i].second + 1});
					usd[now[i].first][now[i].second + 1] = 1;
				}
				if (a[now[i].first + 1][now[i].second] < min_let && usd[now[i].first + 1][now[i].second] == 0) {
					min_let = a[now[i].first + 1][now[i].second];
					now1.clear();
					now1.push_back({now[i].first + 1, now[i].second});
					usd[now[i].first + 1][now[i].second] = 1;
				}
				else if (a[now[i].first + 1][now[i].second] == min_let && usd[now[i].first + 1][now[i].second] == 0){
					now1.push_back({now[i].first + 1, now[i].second});
					usd[now[i].first + 1][now[i].second] = 1;
				}
			}
			if (now[i].first == n - 1 && now[i].second < n - 1) {
				if (a[now[i].first][now[i].second + 1] < min_let && usd[now[i].first][now[i].second + 1] == 0) {
					min_let = a[now[i].first][now[i].second + 1];
					now1.clear();
					now1.push_back({now[i].first, now[i].second + 1});
					usd[now[i].first][now[i].second + 1] = 1;
				}
				else if (a[now[i].first][now[i].second + 1] == min_let){
					now1.push_back({now[i].first, now[i].second + 1});
					usd[now[i].first][now[i].second + 1] = 1;
				}
			}
			if (now[i].first < n - 1 && now[i].second == n - 1 && usd[now[i].first + 1][now[i].second] == 0) {
				if (a[now[i].first + 1][now[i].second] < min_let) {
					min_let = a[now[i].first + 1][now[i].second];
					now1.clear();
					now1.push_back({now[i].first + 1, now[i].second});
					usd[now[i].first + 1][now[i].second] = 1;
				}
				else if (a[now[i].first + 1][now[i].second] == min_let){
					now1.push_back({now[i].first + 1, now[i].second});
					usd[now[i].first + 1][now[i].second] = 1;
				}
			}
			if (now[i].first == n - 1 && now[i].second == n - 1) {
				cout << ans;
				return 0;
			}
		}
		now = now1;
		ans += min_let;
	}
	return 0;
}