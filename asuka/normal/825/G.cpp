#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
#define SZ(x) ((int)x.size())
using namespace std;
int n,q,rt,las,Min[N],ans;
VI e[N];
void dfs(int u,int fa){
	Min[u] = min(u,Min[fa]);
	for(auto v:e[u]) if(v != fa){
		dfs(v,u);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&q);
 	rep(i,2,n){
 		int u,v; scanf("%d%d",&u,&v);
 		e[u].pb(v); e[v].pb(u);
 	}
 	int opt,x;
 	scanf("%d%d",&opt,&x);
 	x = (x + las) % n + 1;
 	rt = x;
 	Min[0] = inf;
 	dfs(x,0);
 	ans = inf;
 	rep(i,2,q){
 		scanf("%d%d",&opt,&x);
 		x = (x + las) % n + 1;
 		if(opt == 1) ans = min(ans,Min[x]);
 		else printf("%d\n",las = min(ans,Min[x]));
 	}
	return 0;
}