#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int K = 80;
const int N = 4007;
const int MX = 998244353;
const LL INF = 1e18 + 9LL;

int n, m, k;
int s[2][K];
int sum[2][N][K];
int cykl[2][N][K];
int dp[2][N + N][K];

PII E[2][N + N];
int sil[N], odw[N];
vector <PII> G[2][N];

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a)%MX;
		
		a = (1LL * a * a)%MX;
		b >>= 1;
	}
	
	return ret;
}

void read(int t, int _n){
	for(int i = 1; i < _n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		E[t][2 * i - 1] = {u, v};
		E[t][2 * i] = {v, u};
		
		G[t][u].push_back({v, 2 * i - 1});
		G[t][v].push_back({u, 2 * i});
	}
}

void get(int t, int _n){
	for(int i = 1; i <= _n; ++i)
		cykl[t][i][0] = 1,
		cykl[t][i][2] = G[t][i].size();

	int _m = _n + _n - 2;
	for(int i = 1; i <= _m; ++i){
		dp[t][i][2] = 1;
		sum[t][E[t][i].st][2]++;
	}
	
	for(int i = 4; i <= k; i += 2){
		for(int j = 1; j <= _m; ++j){
			LL help = 0LL;
			for(int ii = 2; ii < k; ++ii)
				help += (1LL * (sum[t][E[t][j].nd][ii] - dp[t][j - 1 + 2 * (j%2)][ii]) * dp[t][j][i - ii])%MX;
			
			dp[t][j][i] = ((help%MX) + MX)%MX;
			sum[t][E[t][j].st][i] = (sum[t][E[t][j].st][i] + dp[t][j][i])%MX;
		}
		
		for(int j = 1; j <= _n; ++j){
			LL help = 0LL;
			for(auto v: G[t][j])
				for(int ii = 2; ii <= i; ++ii)
					help += (1LL * cykl[t][j][i - ii] * dp[t][v.nd][ii])%MX;
			cykl[t][j][i] = help%MX;
		}
	}
	
	for(int i = 0; i <= k; i += 2)
		for(int j = 1; j <= _n; ++j)
			s[t][i] = (s[t][i] + cykl[t][j][i])%MX;
}

int symbol(int a, int b){
	if(b < 0 || a < b || a < 0)
		return 0;
	return (((1LL * sil[a] * odw[b])%MX) * odw[a - b])%MX;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	if(k%2 == 1){
		puts("0");
		return 0;
	}

	read(0, n);
	read(1, m);
	
	get(0, n);
	get(1, m);
	
	odw[0] = sil[0] = 1LL;
	for(int i = 1; i <= k; ++i){
		sil[i] = (1LL * sil[i - 1] * i)%MX;
		odw[i] = fast(sil[i], MX - 2);
	}
	
	LL res = 0LL;
	for(int i = 0; i <= k; i += 2)
		res = ((((1LL * s[0][i] * s[1][k - i])%MX) * symbol(k, i))%MX + res)%MX;
	printf("%lld\n", res);
	return 0;
}