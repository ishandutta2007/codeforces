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

const int N = 1e6+10;
int p[N];
int n, k;

bool vis[N]={};
int dfs(int v)
{
	vis[v] = 1;
	if(vis[p[v]]) return 1;
	return 1+dfs(p[v]);
}

vector<int> CrazyNoisyBizarreTown;
int DirtyDeedsDoneDirtCheap[N];

bool ssp()
{
	Loop(i,1,N/2){
		int x = (DirtyDeedsDoneDirtCheap[i]-1)/2;
		DirtyDeedsDoneDirtCheap[2*i] += x;
		DirtyDeedsDoneDirtCheap[i] -= 2*x;
	}
	bitset<N> ans; ans[0]=1;
	Loop(i,1,N)
		while(DirtyDeedsDoneDirtCheap[i]--)
			ans = ans|(ans<<i);
	return ans[k];
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,0,n) cin >> p[i], --p[i];
	Loop(i,0,n) if(!vis[i]) {
		int x = dfs(i);
		CrazyNoisyBizarreTown.push_back(x);
		DirtyDeedsDoneDirtCheap[x]++;
	}
	cout << k+!ssp() << ' ';
	int sum=0;
	for(auto x : CrazyNoisyBizarreTown) sum+=x/2;
	cout << min(n,k+min(sum,k)) << '\n';
}