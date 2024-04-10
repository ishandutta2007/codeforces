#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, s;
int place[107];
double dp[107][N];
double pref[107][N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &place[i]);
		s += place[i];
	}
	
	dp[0][0] = m - 1;
	for(int i = 0; i < s; ++i)
		pref[0][i] = m - 1;

	for(int i = 1; i <= n; ++i){
		for(int j = i; j < s; ++j){
			dp[i][j] = pref[i - 1][j - 1];
			if(j - m - 1 >= 0)
				dp[i][j] -= pref[i - 1][j - m - 1];
			
			if(j >= place[i])
				dp[i][j] -= dp[i - 1][j - place[i]];

			dp[i][j] /= m - 1;
			pref[i][j] = pref[i][j - 1] + dp[i][j];
		}
	}
	
	printf("%.9lf\n", pref[n][s - 1] + 1.0);
	return 0;
}