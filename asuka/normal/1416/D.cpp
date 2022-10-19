#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define pii pair<int,int>
#define fi first
#define se second
#define VI vector<int>
using namespace std;
int n,m,q,val[N],fa[N],dfn[N],siz[N],tot,clk;
bool gkp[N];
VI e[N];
pii qu[N],v[N];
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void ad(int u,int v){
	e[u].pb(v);e[v].pb(u);
}
void add(int u,int v){
	u = find(u),v = find(v);
	if(u == v) return;
	++tot;
	//cout << u << ' ' << tot << ' ' << v << endl;
	ad(u,tot);ad(v,tot);
	fa[u] = fa[v] = tot;
}
void dfs(int u,int f){
	dfn[u] = ++clk;siz[u] = 1;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		siz[u] += siz[v];
	}
}
namespace seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	pii Max[N<<2];
	pii query(int p,int l,int r,int x,int y){
		//cout << l <<  ' ' << r << endl;
		if(l>r) return mp(0,0);
		if(x <= l&&r <= y) return Max[p];
		int mid = (l+r)>>1;pii res = mp(0,0);
		if(x <= mid) res = max(res,query(ls,l,mid,x,y));
		if(y > mid) res = max(res,query(rs,mid+1,r,x,y));
		return res;
	}
	void update(int p,int l,int r,int pos,pii val){
		if(l == r) {
			Max[p] = val;
			return;
		}
		int mid = (l+r)>>1;
		if(pos <= mid) update(ls,l,mid,pos,val);
		else update(rs,mid+1,r,pos,val);
		Max[p] = max(Max[ls],Max[rs]);
	}
}
using namespace seg;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d%d",&n,&m,&q); tot = n;
 	rep(i,1,n) scanf("%d",&val[i]);
 	rep(i,1,m) scanf("%d%d",&v[i].fi,&v[i].se);
 	rep(i,1,q){
 		scanf("%d%d",&qu[i].fi,&qu[i].se);
 		if(qu[i].fi == 2) gkp[qu[i].se] = 1;
 	}
 	rep(i,1,n*2) fa[i] = i;
 	rep(i,1,m)
 		if(!gkp[i]) add(v[i].fi,v[i].se);
 	per(i,1,q){
 		//cout << i << ":\n";
 		//rep(j,1,tot) cout << j << '#' << find(j) << endl;
 		if(qu[i].fi == 2) add(v[qu[i].se].fi,v[qu[i].se].se);
 		else qu[i].se = find(qu[i].se);//,cout << "fuck:" << qu[i].se << endl;
 	}
 	rep(i,1,tot){
 		if(find(i) == i){
 			dfs(i,0);
 			//printf("### %d\n",i);
 		}
 	}
 //	rep(i,1,tot) printf("i: %d dfn: %d size: %d\n",i,dfn[i],siz[i]);
 	rep(i,1,n)  update(1,1,tot,dfn[i],mp(val[i],dfn[i]));
 	// rep(j,1,n){
 	// 	pii tmp = query(1,1,tot,dfn[j],dfn[j]);
 	// 	printf("%d %d\n",j,tmp.se);
 	// }
 	rep(i,1,q){
 		if(qu[i].fi == 2) continue;
 		int x = qu[i].se;
 		
 		//printf("%d %d %d\n", dfn[x],dfn[x]+siz[x]-1,x);
 		pii temp = query(1,1,tot,dfn[x],dfn[x]+siz[x]-1);
 		if(temp.fi == 0) puts("0");
 		else{
 			printf("%d\n",temp.fi);
 		//	cout << "fuck: " << temp.se << endl;
 			update(1,1,tot,temp.se,mp(0,0));
 		}
 	}
	return 0;
}