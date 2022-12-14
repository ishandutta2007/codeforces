#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 100;
pair <int, int> a[maxn][maxn];
int dp[maxn][maxn][2];
char par[maxn][maxn][2];
int x, y;
bool there;

string rev(string ab){
	string rev;
	for (int i = ab.size() - 1; i >= 0; i--)
		rev += ab[i];
	return rev;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int q;
			cin >> q;
			int d2 = 0, d5 = 0;
			if (q == 0){
				a[i][j].first = -1;
				a[i][j].second = -1;
				x = i;
				y = j;
				there = true;
			}
			else {
				while (q % 2 == 0){
					q /= 2;
					a[i][j].first ++;
				}
				while (q % 5 == 0){
					q /= 5;
					a[i][j].second ++;
				}
			}
		}
	}
	for (int i = 0; i <= n; i++){
		for (int k = 0; k <= 1; k++){
			dp[i][0][k] = 1000000000;
			dp[0][i][k] = 1000000000;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (a[i][j].first == -1){
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
				if (j != 1){
					par[i][j][0] = 'R';
					par[i][j][1] = 'R';
				}
				else {
					par[i][j][0] = 'D';
					par[i][j][1] = 'D';
				}
				continue;
			}
			if (i == 1 and j == 1){
				dp[i][j][0] = a[i][j].first;
				dp[i][j][1] = a[i][j].second;
				continue;
			}
			if (dp[i][j - 1][0] < dp[i - 1][j][0]){
				dp[i][j][0] = dp[i][j - 1][0] + a[i][j].first;
				par[i][j][0] = 'R';
			}
			else {
				dp[i][j][0] = dp[i - 1][j][0] + a[i][j].first;
				par[i][j][0] = 'D';
			}
			if (dp[i][j - 1][1] < dp[i - 1][j][1]){
				dp[i][j][1] = dp[i][j - 1][1] + a[i][j].second;
				par[i][j][1] = 'R';
			}
			else {
				dp[i][j][1] = dp[i - 1][j][1] + a[i][j].second;
				par[i][j][1] = 'D';
			}
		}
	}
	int pop = min (dp[n][n][1], dp[n][n][0]);
	if (pop >= 1 and there){
		cout << 1 << endl;
		for (int i = 1; i < x; i++)
			cout << 'D';
		for (int i = 1; i < n; i++)
			cout << 'R';
		for (int i = x; i < n; i++)
			cout << 'D';
		return 0;
	}
	string k;
	cout << pop << endl;
	if (dp[n][n][0] < dp[n][n][1]){
		int r = n, l = n;
		while (r > 1 || l > 1){
			if (par[r][l][0] == 'R'){
				k += 'R';
				l --;
			}
			else {
				k += 'D';
				r --;
			}
		}
	}
	else {
		int r = n, l = n;
		while (r > 1 || l > 1){
			if (par[r][l][1] == 'R'){
				k += 'R';
				l --;
			}
			else {
				k += 'D';
				r --;
			}
		}
	}
	cout << rev(k) << endl;
}