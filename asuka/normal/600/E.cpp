#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,c[N],u,v,size[N],son[N],Mx,Son,cnt[N],sum,ans[N];
VI e[N];
void dfs(int u,int fa){
	int Max = 0;
	size[u] = 1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		size[u] += size[v];
		if(size[v] > Max){
			Max = size[v];
			son[u] = v;
		}
	}
}
void add(int u,int fa,int val){
	cnt[c[u]] += val;
	if(cnt[c[u]] > Mx){
		Mx = cnt[c[u]];
		sum = c[u];
	}else if(cnt[c[u]] == Mx){
		sum += c[u];
	}
	for(auto v:e[u]){
		if(v==fa||v==Son) continue;
		add(v,u,val);
	}
}
void dfs2(int u,int fa,int opt){
	for(auto v:e[u]){
		if(v==fa) continue;
		if(v != son[u]) dfs2(v,u,0);
	}
	if(son[u]) dfs2(son[u],u,1),Son = son[u];
	add(u,fa,1);Son = 0;
	ans[u] = sum;
	if(!opt) add(u,fa,-1),sum = Mx = 0;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",&c[i]);
	rep(i,2,n){
		scanf("%lld%lld",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1,0);
//	puts("YES");
	// for(auto v:e[1]) cout << v << ' ';
	// cout << endl;
	dfs2(1,0,0);
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0;
}