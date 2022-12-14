#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 100 + 10;
const int mod = 1e9 + 7;

int f[maxn];

int dp[maxn][maxn][maxn];

pair <pair <int, int>, int> pd[maxn][maxn][maxn];

bool mark[maxn][maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s, t, virus;
	cin >> s >> t >> virus;
	
	int ptr = 0;
	for (int i = 1; i < virus.size(); i++){
		while (ptr > 0 and virus[i] != virus[ptr]){
			ptr = f[ptr];
		}
		ptr += (virus[i] == virus[ptr]);
		f[i + 1] = ptr;
	}
	
	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 0; i <= s.size(); i++){
		for (int j = 0; j <= t.size(); j++){
			for (int k = 0; k < virus.size(); k++){
				if (dp[i][j][k] == -1)
					continue;
				if (dp[i + 1][j][k] < dp[i][j][k]){
					dp[i + 1][j][k] = dp[i][j][k];
					pd[i + 1][j][k] = {{i, j}, k};
					mark[i + 1][j][k] = 0;
				}
				if (dp[i][j + 1][k] < dp[i][j][k]){
					dp[i][j + 1][k] = dp[i][j][k];
					pd[i][j + 1][k] = {{i, j}, k};
					mark[i][j + 1][k] = 0;
				}
				if (i == s.size() or j == t.size())
					continue;
				if (s[i] != t[j]){
					if (dp[i + 1][j + 1][k] < dp[i][j][k]){
						dp[i + 1][j + 1][k] = dp[i][j][k];
						pd[i + 1][j + 1][k] = {{i, j}, k};
						mark[i + 1][j + 1][k] = 0;
					}
					continue;
				}
				int ptr = k;
				while (ptr > 0 and s[i] != virus[ptr]){
					ptr = f[ptr];
				}
				ptr += (s[i] == virus[ptr]);
				if (dp[i + 1][j + 1][ptr] < dp[i][j][k] + 1){
					dp[i + 1][j + 1][ptr] = dp[i][j][k] + 1;
					pd[i + 1][j + 1][ptr] = {{i, j}, k};
					mark[i + 1][j + 1][ptr] = 1;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < virus.size(); i++){
		answer = max(answer, dp[s.size()][t.size()][i]);
	}
	if (answer == 0)
		return cout << 0 << endl, 0;
	int fi = s.size(), se = t.size(), th;
	for (int i = 0; i < virus.size(); i++){
		if (dp[fi][se][i] == answer){
			th = i;
			break;
		}
	}
	string ans;
	while (answer){
		if (mark[fi][se][th]){
			ans += s[fi - 1];
			answer --;
		}
		auto it = pd[fi][se][th];
		fi = it.F.F, se = it.F.S, th = it.S;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}