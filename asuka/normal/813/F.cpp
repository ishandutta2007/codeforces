#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int n,q,cnt,flag,ans[N];
vector<pii> stk,tr[N<<2];
map<pii,int> M;
namespace UF{
	int fa[N],siz[N],tag[N];
	void init(){
		rep(i,1,n) fa[i] = i,siz[i] = 1,tag[i] = 0;
	}
	int find(int x){return x == fa[x] ? x : find(fa[x]);}
	int gettag(int x){
		int res = 0;
		while(x != fa[x]){
			res ^= tag[x];
			x = fa[x];
		}
		return res;
	}
	int uni(int u,int v){
		// printf("%d -> %d\n",u,v);
		int tu = gettag(u),tv = gettag(v);
		u = find(u); v = find(v);
		if(u == v){
			if(tu == tv) cnt++,flag++;// odd circle
			return 0;
		}
		if(siz[u] < siz[v]) swap(u,v);
		stk.pb(mp(u,v));
		siz[u] += siz[v]; fa[v] = u; tag[v] = tu^tv^1;
		return 1;
	}
	void del(int u,int v){
		fa[v] = v; siz[u] -= siz[v]; tag[v] = 0;
	}
}
using namespace UF;
#define ls (p<<1)
#define rs (p<<1|1)
void add(int p,int l,int r,int x,int y,pii val){
	// if(l == 1 && r == q){
	// 	printf("[%d,%d]  %d -> %d\n",x,y,val.fi,val.se);
	// }
	if(x <= l && r <= y){
		tr[p].pb(val);
		return ;
	}
	int mid = (l+r)>>1;
	if(x <= mid) add(ls,l,mid,x,y,val);
	if(y > mid) add(rs,mid+1,r,x,y,val);
}
void dfs(int p,int l,int r){
	cnt = 0;
	int uuu = 0;
	// printf("CUR: %d %d\n",l,r);
	for(auto x:tr[p]) uuu += uni(x.fi,x.se);
	int tmp = cnt;
	if(l == r) ans[l] = flag==0;
	else{
		int mid = (l+r)>>1;
		dfs(ls,l,mid); dfs(rs,mid+1,r);
	}
	flag -= tmp;
	rep(i,1,uuu) {
		pii cur = stk.back(); stk.pop_back();
		del(cur.fi,cur.se);
	}
}
#undef ls
#undef rs
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&q);
 	init();
 	rep(_,1,q){
 		int x,y; scanf("%d%d",&x,&y);
 		if(M.count(mp(x,y)) > 0 && M[mp(x,y)] != -1){
 			add(1,1,q,M[mp(x,y)],_-1,mp(x,y));
 			M[mp(x,y)] = -1;
 		}else M[mp(x,y)] = _;
 	}
 	for(auto x:M){
 		if(x.se == -1) continue;
 		add(1,1,q,x.se,q,x.fi);
 	}
 	dfs(1,1,q);
 	rep(i,1,q) puts(ans[i]?"YES":"NO");
	return 0;
}