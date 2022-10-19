#include<bits/stdc++.h>
#define int long long
#define N 2000015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,k,col[N];
bool fked[N];
map<pii,int> id;
vector<pii> e[N];
namespace dsu{
	int fa[N],siz[N],top,sta[N][3]; // fa,son,siz[fa] -= siz[son],fa[son] = son;
	void init(){ rep(i,1,n<<2) {fa[i] = i;siz[i] = 1;}}
	int find(int x){return x == fa[x]?x:find(fa[x]);}
	void merge(int u,int v){
		u = find(u);v = find(v);
		if(u == v) return;
		if(siz[u] > siz[v]) swap(u,v);
		top++;
		sta[top][0] = v; sta[top][1] = u;sta[top][2] = siz[u];
		siz[v] += siz[u]; fa[u] = v;
	}
	void rollback(){
		int v = sta[top][0],u = sta[top][1],sz = sta[top][2];
		fa[u] = u; siz[v] -= sz; top --;
	}
}
using namespace dsu;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	rep(i,1,n) scanf("%lld",&col[i]);
	init();
	int cnt = 0;
	rep(i,1,m){
		int u,v;
		scanf("%lld%lld",&u,&v);
		if(col[u] > col[v]) swap(u,v);
		int p;
		if(id.count(mp(col[u],col[v])) > 0) p = id[mp(col[u],col[v])];
		else p = ++cnt,id[mp(col[u],col[v])] = p;
		e[p].pb(mp(u,v));
	}
	int tot = k;
	rep(i,1,k){
		if(id.count(mp(i,i)) == 0) continue;
		int p = id[mp(i,i)];
		//cout <<"fvck" <<  i << ' ' << p << endl;
		for(auto x:e[p]){
			int u = x.fi,v = x.se;
			//printf("%d %d\n",u,v);
			merge(u,v+n);merge(u+n,v);
			if(find(u) == find(v) && !fked[i]) fked[i] = 1,tot--;
		}
		id.erase(mp(i,i));
	}
	//printf("%lld\n",tot);
	int ans = (tot*(tot-1))>>1;
	for(auto it = id.begin();it != id.end();it++){
		if(fked[it->fi.fi]||fked[it->fi.se]) continue;
		int p = it->se;
		int last = top;
		for(auto x:e[p]){
			int u = x.fi,v = x.se;
			merge(u,v+n); merge(u+n,v);
			if(find(u) == find(v)){
				ans --;
				break;
			}
		}
		while(top > last) rollback();
	}
	printf("%lld\n", ans);
	return 0;
}