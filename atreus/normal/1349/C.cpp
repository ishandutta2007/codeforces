#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 1000 + 10;
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

map<char,char> nex = { {'0', '1'}, {'1', '0'} };
string s[maxn];
pair<int,int> Q[maxn*maxn];
int dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int tail = 0, head = 0;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int z = 0; z < 4; z++){
				int i2 = i + x[z], j2 = j + y[z];
				if (0 <= i2 and i2 < n and 0 <= j2 and j2 < m and s[i][j] == s[i2][j2]){
					dp[i][j] = 0;
					Q[head++] = {i,j};
					break;
				}
			}
		}
	}
	while (tail < head){
		int i = Q[tail].first, j = Q[tail].second;
		tail ++;
		for (int z = 0; z < 4; z++){
			int i2 = i + x[z], j2 = j + y[z];
			if (0 <= i2 and i2 < n and 0 <= j2 and j2 < m and dp[i2][j2] == -1){
				dp[i2][j2] = dp[i][j] + 1;
				Q[head++] = {i2,j2};
			}
		}
	}
	while (t --){
		int i, j;
		ll p;
		cin >> i >> j >> p;
		i --, j --;
		if (dp[i][j] == -1 or dp[i][j] >= p){
			cout << s[i][j] << '\n';
			continue;
		}
		ll diff = p - dp[i][j];
		diff &= 1;
		if (diff == 0)
			cout << s[i][j] << '\n';
		else
			cout << nex[s[i][j]] << '\n';
	}
}