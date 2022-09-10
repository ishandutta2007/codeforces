#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLD pair <LD, LD>
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int N = 1e3 + 9;

int n, m, k;
int dp[N][N][11];
int L[N][N];
char s[N];
char t[N];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	t[0] = '1';
	s[0] = '2';
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i] == t[j])
				L[i][j] = L[i - 1][j - 1] + 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int l = 1; l <= k; ++l){
				dp[i][j][l] = dp[i - L[i][j]][j - L[i][j]][l - 1] + L[i][j];			
				dp[i][j][l] = max(dp[i][j][l], max(dp[i - 1][j][l], dp[i][j - 1][l]));
				dp[i][j][l] = max(dp[i][j][l - 1], dp[i][j][l]);
			}
	
	printf("%d\n", dp[n][m][k]);
	return 0;
}