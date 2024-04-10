#include<bits/stdc++.h>
#define int long long
#define ll long long
#define N 300015
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
int n,m,x,a[N];
vector<pii> ans;
set<pii> S;
namespace UF{
	vector<pii> edge[N];
	int fa[N];
	void init(){rep(i,1,n) fa[i] = i;}
	int find(int u){return fa[u] == u?u:fa[u] = find(fa[u]);}
	int uni(int u,int v){
		u = find(u); v = find(v);
		if(u == v) return 0;
		if(edge[u].size() < edge[v].size()) swap(u,v);
		fa[v] = u; a[u] = a[u]+a[v]-x;
		for(auto a:edge[v]) edge[u].pb(a);
		edge[v].clear();
		return u; 
	}
}
using namespace UF;
map<pii,int> M;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&x);
	rep(i,1,n) scanf("%lld",&a[i]);
	ll sum = 0;
	rep(i,1,n) sum += a[i];
	if(sum < 1ll*(n-1)*x){
		puts("NO");
		return 0;
	}
	init();
	rep(i,1,m){
		int u,v;
		scanf("%lld%lld",&u,&v);
		M[mp(u,v)] = M[mp(v,u)] = i;
		edge[u].pb(mp(u,v));
		edge[v].pb(mp(v,u));
	}
	rep(i,1,n) S.insert(mp(a[i],i));
	while(S.size() > 1){
		int u = (*S.rbegin()).se; S.erase(S.find(*S.rbegin()));
		while(u == find(edge[u].back().se)) edge[u].pop_back();
		int v = edge[u].back().se;
		// printf("%lld %lld\n",u,v);
		v = find(v);
		ans.pb(edge[u].back());
		S.erase(S.find(mp(a[v],v)));
		int uu = uni(u,v);
		S.insert(mp(a[uu],uu));
	}
	puts("YES");
	for(auto a:ans) printf("%lld\n",M[a]);
	return 0;
}