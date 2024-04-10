#include<bits/stdc++.h>
#define int long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int n,a[N],siz[N],lef[N],ans;
VI e[N];
void dfs(int u){
	if(e[u].size() == 0){
		lef[u] = 1;
		siz[u] = a[u];
		ans = max(ans,a[u]);
		return;
	}
	siz[u] = a[u];
	for(auto v:e[u]){
		dfs(v);
		siz[u] += siz[v];
		lef[u] += lef[v];
	}
	ans = max(ans,(siz[u]+lef[u]-1)/lef[u]);
}

signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,2,n){
 		int f;
 		scanf("%lld",&f);
 		e[f].pb(i);
 	}
 	rep(i,1,n) scanf("%lld",&a[i]);
 	dfs(1);
 	printf("%lld\n",ans);
	return 0;
}