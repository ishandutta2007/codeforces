///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#define min(x,y) ((x)<(y)?(x):(y))

const int N = 100'010;

int cnt[N];
int ssp[N], sspw[N], sspc;
int dp[N];

void ssp_solve()
{
	Loop(x,0,N){
		vector<int> dard;
		for(int y = 1; y <= cnt[x]; y*=2){
			dard.push_back(y);
			cnt[x] -= y;
		}
		for(int y = 1; cnt[x]; y*=2){
			if(cnt[x]&y){
				dard.push_back(y);
				cnt[x] -= y;
			}
		}
		for(int y : dard) {
			ssp[sspc]=x*y;
			sspw[sspc]=y;
			sspc++;
		}
	}

	dp[0]=0; Loop(i,1,N) dp[i]=N;
	Loop(i,0,sspc){
		int x = ssp[i];
		int w = sspw[i];
		LoopR(i,x,N) dp[i] = min(dp[i],dp[i-x]+w);
	}
}

bool vis[N];
vector<int> A[N];
int dfs(int v)
{
	vis[v] = 1;
	int ans = 1;
	for(int u : A[v])
		if(!vis[u])
			ans += dfs(u);
	return ans;
}

bool lucky(int x)
{
	for(;x;x/=10)
		if(x%10 != 4 && x%10 != 7)
			return 0;
	return 1;
}

int n, m;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	while(m--){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	Loop(v,0,n) if(!vis[v]) cnt[dfs(v)]++;
	ssp_solve();
	int ans = N;
	Loop(i,1,N) if(lucky(i)) ans = min(ans, dp[i]);
	cout << (ans==N?-1:ans-1) << '\n';
}