#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
vector< int > g[N];
pll dp[N][2];
int n;
void add(ll &x, ll y){
	x = (x + y) % mod;
}
void dfs(int v, int pr){
	dp[v][0] = {0, 1};
	for(auto to : g[v]){
		if(to == pr)
			continue;
        dfs(to, v);
        pll A, B;
		A = B = {0, 0};
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int q = 0; q < 2; q++){
				    ll cur = dp[v][i].s * dp[to][j].f + dp[v][i].f * dp[to][j].s;
					if(i == 0 && j == 0 && q == 1){
						add(B.f, cur + dp[v][i].s * dp[to][j].s);
						add(B.s, dp[v][i].s * dp[to][j].s); 
					}else if(i == 0){
						add(A.f, cur);
						add(A.s, dp[v][i].s * dp[to][j].s); 
					}else{
						add(B.f, cur);
						add(B.s, dp[v][i].s * dp[to][j].s); 
					}
				
				}
		dp[v][0] = A;
		dp[v][1] = B; 
	}                                                           
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1);
	printf("%lld", 2 * (dp[1][0].f + dp[1][1].f) % mod);
	return 0;
}