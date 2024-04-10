#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 707;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
bool ok[N][N];
bool dp[N][N];
bool lewy[N][N];
bool prawy[N][N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i <= n; ++i){
		lewy[i][i] = true;
		prawy[i][i] = true;
		dp[i][i] = true;
		
		if(i < n && __gcd(in[i], in[i + 1]) > 1)
			lewy[i + 1][i] = true;
		if(1 < i && __gcd(in[i], in[i - 1]) > 1)
			prawy[i - 1][i] = true;
		
		for(int j = i + 1; j <= n; ++j)
			ok[i][j] = ok[j][i] = __gcd(in[i], in[j]) > 1;
	}
	
	for(int l = 1; l < n; ++l)
		for(int i = 1; i + l <= n; ++i){
			int j = i + l;
			for(int k = i; k <= j; ++k){
				if(!lewy[k][i] || !prawy[k][j])
					continue;
				
//				printf("%d %d :: %d :: %d %d\n", i, j, k, ok[k][j + 1], ok[k][i - 1]);
				if(j < n && ok[k][j + 1])
					lewy[j + 1][i] = true;
				if(1 < i && ok[k][i - 1])
					prawy[i - 1][j] = true;
				dp[i][j] = true;
			}
		}
	
	puts(dp[1][n] ? "Yes" : "No");
	return 0;
}