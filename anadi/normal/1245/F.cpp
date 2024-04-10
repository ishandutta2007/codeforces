#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 31;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int fa[N], fb[N];
LL dp[N][2][2];

LL ask(int a, int b){
	for(int i = 0; i < 30; ++i){
		fa[i] = a & 1;
		fb[i] = b & 1;
		a >>= 1, b >>= 1;
	}
	
	for(int i = 0; i <= 30; ++i)
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
				dp[i][j][k] = 0;
	
	dp[30][1][1] = 1;
	for(int i = 30; i > 0; --i){
		for(int ba = 0; ba < 2; ++ba)
			for(int bb = 0; bb < 2; ++bb)
				for(int ca = 0; ca < 2; ++ca)
					for(int cb = 0; cb < 2; ++cb){
						if(ba && ca > fa[i - 1])
							continue;
						if(bb && cb > fb[i - 1])
							continue;

						if(ca & cb)
							continue;
						
						int na = ba, nb = bb;
						if(ba && ca < fa[i - 1])
							na = 0;
						
						if(bb && cb < fb[i - 1])
							nb = 0;
						
						dp[i - 1][na][nb] += dp[i][ba][bb];
					}
	}
	
	return dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1];
}

void solve(){
	int l, r;
	scanf("%d %d", &l, &r);
	
	l--;
	LL ans = ask(r, r);

	if(l >= 0)
		ans = ans - 2 * ask(l, r) + ask(l, l);
	printf("%lld\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}