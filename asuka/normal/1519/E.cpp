#include<bits/stdc++.h>
#define int long long
#define N 400015
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
void hj(pii &p){
	int g = __gcd(p.fi,p.se);
	p.fi /= g;p.se /= g;
}
int n,a,b,c,d,dep[N];
map<pii,int> M;
int tot;
int I(pii p){
	if(M.count(p) > 0) return M[p];
	return M[p] = ++tot;
}
vector<pii> e[N],ans;
int dfs(int u,int cur){
	VI son;
	for(auto V:e[u]){
		int v = V.fi,id = V.se;
		if(dep[v]){
			if(dep[v] > dep[u]) son.pb(id);
		}else{
			dep[v] = dep[u]+1;
			if(dfs(v,id)) son.pb(id);
		}
	}
	for(int i = 0;i+1 < SZ(son);i += 2){
		ans.pb(mp(son[i],son[i+1]));
	}
	if(cur&&(SZ(son)&1)){
		ans.pb(mp(son.back(),cur));
		return 0;
	}else return 1;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		pii u = mp(b*(c+d),a*d),v = mp(b*c,(a+b)*d);
		hj(u); hj(v);
		
		e[I(u)].pb(mp(I(v),i)); e[I(v)].pb(mp(I(u),i));
	}
	rep(i,1,tot) if(!dep[i]){
		dep[i] = 1;
		dfs(i,0);
	}
	printf("%lld\n",ans.size());
	for(auto x:ans){
		printf("%lld %lld\n",x.fi,x.se);
	}
	return 0;
}