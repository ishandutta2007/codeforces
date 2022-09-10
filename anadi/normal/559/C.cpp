#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int M = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
PII in[N];
int x[N], y[N];

int sil[M];
int odw[M];

int dp[N];
int ile[N][N];

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a)%MX;
		
		b >>= 1;
		a = (1LL * a * a)%MX;
	}
	
	return ret;
}

int newton(int a, int b){
	return (((1LL * sil[a] * odw[b])%MX) * odw[a - b])%MX;
}

int main(){
	int h, w;
	scanf("%d %d %d", &h, &w, &n);
	
	n += 2;
	in[1] = {1, 1};
	in[n] = {h, w};
	
	for(int i = 2; i < n; ++i)
		scanf("%d %d", &in[i].st, &in[i].nd);
	sort(in + 1, in + n + 1);
	
	for(int i = 1; i <= n; ++i)
		x[i] = in[i].st, y[i] = in[i].nd;
	
	sil[0] = odw[0] = 1;
	for(int i = 1; i <= h + w; ++i)
		sil[i] = (1LL * sil[i - 1] * i)%MX;
	
	odw[h + w] = fast(sil[h + w], MX - 2);
	for(int i = h + w; i >= 2; --i)
		odw[i - 1] = (1LL * odw[i] * i)%MX;
		
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j)
			if(y[i] <= y[j])
				ile[i][j] = newton(x[j] - x[i] + y[j] - y[i], y[j] - y[i]);
	
	dp[1] = 1;
	for(int i = 2; i <= n; ++i){
		dp[i] = ile[1][i];
		for(int j = 2; j < i; ++j)
			dp[i] = (dp[i] + MX - (1LL * dp[j] * ile[j][i])%MX)%MX;
	}
	
	printf("%d\n", dp[n]);
	return 0;
}