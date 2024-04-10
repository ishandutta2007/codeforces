#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int ile[N];

string s;
int dp[N][N][2];

int main(){
	cin >> s;
	cin >> n;
	
	if(n == 0){
		cout << "1\n";
		return 0;
	}
	
	for(int i = 2; i <= 1000; ++i)
		ile[i] = ile[__builtin_popcount(i)] + 1;
	
	s = '#' + s; dp[0][0][1] = 1;
	for(int i = 1; i < s.size(); ++i){
		dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
		for(int j = 1; j <= i; ++j){
			dp[i][j][0] = (dp[i - 1][j - 1][0] + dp[i - 1][j][0] + (s[i] == '1' ? dp[i - 1][j][1] : 0))%MX;
			dp[i][j][1] = s[i] == '0' ? dp[i - 1][j][1] : dp[i - 1][j - 1][1];
		}
	}
	
	int res = n == 1 ? -1 : 0;
	for(int i = 1; i <= 1000; ++i)
		if(ile[i] == n - 1)
			res = (res + dp[s.size() - 1][i][0] + dp[s.size() - 1][i][1])%MX;
	printf("%d\n", res);
	return 0;
}