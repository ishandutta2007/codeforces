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
#define all(x) x.begin(),x.end()
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m;
set<int> S;
struct node{
	int u,v,w;
	bool operator<(const node&o) const{
		return w < o.w;
	}
}edge[N];
struct UF{
	int fa[N],siz[N];
	void init(){
		rep(i,1,n) fa[i] = i,siz[i] = 1;  
	}
	int find(int x){return x == fa[x]?x:fa[x] = find(fa[x]);}
	bool uni(int x,int y){
		x = find(x); y = find(y);
		if(x == y) return 0;
		if(siz[x] < siz[y]) swap(x,y);
		siz[x] += siz[y]; fa[y] = x;
		return 1;
	}
}zero,all;
VI e[N];
int tmp,ans,res;
bool vis[N];
void dfs(int u){
	// printf("%d\n",u);
	S.erase(u);
	for(int v = 0;;){
		auto it = S.lower_bound(v);
		if(it == S.end()) return;
		v = *it;
		if(!binary_search(all(e[u]),v)){
			zero.uni(u,v);
			tmp--;
			dfs(v);
		}
		v++;
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	zero.init(); all.init();
	rep(i,1,n) S.insert(i);
	tmp = n*(n-1)/2 - m;
	rep(i,1,m){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].pb(v); e[v].pb(u);
		res ^= w;
		edge[i] = (node){u,v,w};
	}
	sort(edge+1,edge+m+1);
	rep(i,1,n) sort(all(e[i]));
	rep(i,1,n){
		if(S.count(i)) dfs(i);
	}
	if(tmp > 0) res = 0;
	rep(i,1,m){
		int u = edge[i].u,v = edge[i].v,w = edge[i].w;
		if(zero.uni(u,v)){
			ans += w;
			all.uni(u,v);
		}else if(all.uni(u,v)){
			res = min(res,w);
		}
	}
	printf("%lld\n",ans+res);
	return 0;
}