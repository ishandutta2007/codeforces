#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
int n,a[N],b[N],cnt[N],cur[N],dfin[N],dfot[N],D[N],clk;
VI e[N];
void dfs(int u,int fa){
	dfin[u] = ++clk;
	int now = cur[a[u]]++;
	for(auto v:e[u]){
		if(v == fa) continue;
		int tmp = cur[a[u]];
		dfs(v,u);
		if(cur[a[u]] > tmp) D[1]++,D[dfin[v]]--,D[dfot[v]+1]++;
	}
	dfot[u] = clk;
	if(cur[a[u]]-now != cnt[a[u]]){
		D[dfin[u]]++; D[dfot[u]+1]--;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) b[i] = a[i];
	sort(b+1,b+n+1);
	int tot = unique(b+1,b+n+1)-b-1;
	rep(i,1,n) a[i] = lower_bound(b+1,b+tot+1,a[i])-b;
	rep(i,1,n) cnt[a[i]]++;
	rep(i,2,n){
		int u,v; scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	int ans = 0,res = 0;
	rep(i,1,n) {
		ans += D[i];
		if(ans == 0) res++;
	}
	printf("%d\n",res);
	return 0;
}