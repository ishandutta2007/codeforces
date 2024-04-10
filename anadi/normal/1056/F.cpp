#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 107;
const int V = 1007;

const int MX = 1e9 + 7;
const D INF = 1e12;

int n;
D C, T;

D pt[N];
PII val[N];
D dp[N][N][V];
bool poss[N][N][V];

inline D kwa(D a){
	return a * a;
}

void solve(){
	scanf("%d", &n);
	scanf("%Lf %Lf", &C, &T);
	
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &val[i].st, &val[i].nd);

	sort(val + 1, val + n + 1);
	reverse(val + 1, val + n + 1);
	
	pt[0] = 1.0;
	for(int i = 1; i <= n; ++i)
		pt[i] = pt[i - 1] * (D)0.9;
	
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= i; ++j)
			for(int k = 0; k <= 10 * i; ++k)
				poss[i][j][k] = false;
	
	poss[0][0][0] = true;
	for(int i = 1; i <= n; ++i){
		poss[i][0][0] = true;
		for(int j = 1; j <= i; ++j){
			for(int k = 0; k <= 10 * i; ++k)
				poss[i][j][k] |= poss[i - 1][j][k];
			for(int k = val[i].nd; k <= 10 * i; ++k)
				poss[i][j][k] |= poss[i - 1][j - 1][k - val[i].nd];
		}

		for(int j = 1; j <= i; ++j)
			for(int k = 0; k <= 10 * i; ++k){
				if(!poss[i][j][k])	
					continue;
				
				dp[i][j][k] = INF;
				if(poss[i - 1][j][k])
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
				if(k >= val[i].nd && poss[i - 1][j - 1][k - val[i].nd])
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - val[i].nd] + val[i].st / pt[j]);
			}
	}
	
	int ans = 0;
	for(int i = 0; i <= n; ++i)
		for(int j = 10 * i; j >= 0; --j){
			if(!poss[n][i][j])
				continue;
			
//			printf("%d %d %d :: %.9Lf\n", n, i, j, dp[n][i][j]);
			D delta = kwa(1.0 / C - 10.0 * i + T) - 4.0 * dp[n][i][j] / C;
			if(delta < 0.0)
				continue;
			
			delta = sqrt(delta);
//			printf("%.9Lf\n", delta);
			D v = (1.0 / C + T - 10 * i + delta) * C / 2.0;
//			printf("%.9Lf\n", v);
			if(v < 1.0)
				continue;
			ans = max(ans, j);
		}
	
	printf("%d\n", ans);
}

int main(){
	int tc;
	scanf("%d", &tc);
	
	while(tc--)
		solve();
	return 0;
}