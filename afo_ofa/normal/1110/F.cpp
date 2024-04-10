#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
#define int long long
typedef pair<int,int> pii;
#define fi first
#define se second
const int maxn=500005;
int n,k,dfn[maxn],ed[maxn],clk,fa[maxn],lef[maxn],tot,dt[maxn];
ll len[maxn],ans[maxn],dep[maxn];
vector<pii>G[maxn];
struct Node {
	int l,r,id;
};
vector<Node>F[maxn];
namespace Segment {
#define ls o<<1
#define rs ls|1
#define mid ((l+r)>>1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define Def int o,int l,int r
#define Upd tr[o]=min(tr[ls],tr[rs])
	ll tr[maxn<<2],lz[maxn<<2];
	inline void Build(Def) {
		if(l==r) {
			tr[o]=len[l];
			return;
		}
		Build(lson),Build(rson),Upd;
	}
	inline void Add(int o,int d) {
		tr[o]+=d,lz[o]+=d; 
	}
	inline void Pushdown(int o) {
		if(lz[o])
			Add(ls,lz[o]),Add(rs,lz[o]),lz[o]=0;
	}
	inline void Modify(Def,int ql,int qr,int d) {
		if(ql<=l&&r<=qr) {
			Add(o,d);
			return;
		}
		Pushdown(o);
		if(ql<=mid)
			Modify(lson,ql,qr,d);
		if(qr>mid)
			Modify(rson,ql,qr,d);
		Upd;
	}
	inline ll Query(Def,int ql,int qr) {
		if(ql<=l&&r<=qr)
			return tr[o];
		Pushdown(o);
		ll res=1e18;
		if(ql<=mid)
			res=min(res,Query(lson,ql,qr));
		if(qr>mid)
			res=min(res,Query(rson,ql,qr)); 
		return res;
	}
}
inline void Prework(int u=1) {
//	cerr<<"Now :"<<u<<endl;
//	for(auto t:G[u])
//		cerr<<t.fi<<' '<<t.se<<endl;
//	cerr<<"End."<<endl;
	dfn[u]=++clk;
	if(!G[u].size())
		lef[++tot]=u,len[tot]=dep[u],dt[tot]=dfn[u];
	sort(G[u].begin(),G[u].end());
	for(auto t:G[u])
		if(t.fi!=fa[u])
			fa[t.fi]=u,dep[t.fi]=dep[u]+t.se,Prework(t.fi);
	ed[u]=clk;
}
inline void Dfs(int u=1) {
	for(auto t:F[u]) {
		int ql=lower_bound(dt+1,dt+tot+1,t.l)-dt,qr=upper_bound(dt+1,dt+tot+1,t.r)-dt-1;
//		cerr<<ql<<" "<<qr<<endl;
		ans[t.id]=Segment::Query(1,1,tot,ql,qr); 
	}
	for(auto t:G[u]) {
		if(t.fi==fa[u])
			continue;
		int v=t.fi,ql=lower_bound(dt+1,dt+tot+1,dfn[v])-dt,qr=upper_bound(dt+1,dt+tot+1,ed[v])-dt-1,x=t.se;
//		cerr<<"Now in "<<v<<":"<<ql<<" "<<qr<<endl;
		Segment::Modify(1,1,tot,1,tot,x);
		Segment::Modify(1,1,tot,ql,qr,-2*x);
		Dfs(v);
		Segment::Modify(1,1,tot,1,tot,-x);
		Segment::Modify(1,1,tot,ql,qr,2*x);
	}
}
signed main() {
	read(n),read(k);
	for(int i=2,u,v;i<=n;++i)
		read(u),read(v),G[u].push_back(pii(i,v));
	Prework();
	for(int i=1,u,l,r;i<=k;++i)
		read(u),read(l),read(r),F[u].push_back((Node){l,r,i});
//	for(int i=1;i<=n;++i)
//		cerr<<dfn[i]<<" ";
//	for(int i=1;i<=tot;++i)
//		cerr<<lef[i]<<" "<<len[i]<<" "<<dfn[lef[i]]<<endl;
//	cerr<<endl;
	Segment::Build(1,1,tot),Dfs();
	for(int i=1;i<=k;++i)
		printf("%lld\n",ans[i]);
}