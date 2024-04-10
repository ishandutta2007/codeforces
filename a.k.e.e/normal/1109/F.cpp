#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=1005,MAXM=200005,DIR[4][2]={0,1,1,0,0,-1,-1,0};

int n,m,a[MAXN][MAXN];
pii b[MAXM];
vector<int> G[MAXM];

namespace LCT
{
	int ch[MAXM][2],fa[MAXM];
	bool rev[MAXM];
	bool nroot(int u){return ch[fa[u]][0]==u || ch[fa[u]][1]==u;}
	bool sontype(int u){return ch[fa[u]][1]==u;}
	void reverse(int u){rev[u]^=1;swap(ch[u][0],ch[u][1]);}
	void pushdown(int u){if(rev[u])reverse(ch[u][0]),reverse(ch[u][1]),rev[u]=0;}
	void pushall(int u){if(nroot(u))pushall(fa[u]);pushdown(u);}
	void update(int u){}
	void rotate(int u)
	{
		int t=sontype(u),x=fa[u],y=fa[x],z=ch[u][t^1];
		fa[u]=y;if(nroot(x))ch[y][sontype(x)]=u;
		if(z)fa[z]=x;ch[x][t]=z;
		fa[x]=u;ch[u][t^1]=x;
		update(x);update(u);
	}
	void splay(int u)
	{
		pushall(u);
		while(nroot(u))
			if(!nroot(fa[u]))rotate(u);
			else if(sontype(u)==sontype(fa[u]))rotate(fa[u]),rotate(u);
			else rotate(u),rotate(u);
	}
	void access(int u){for(int v=0;u;u=fa[v=u])splay(u),ch[u][1]=v,update(u);}
	void makeroot(int u){access(u),splay(u),reverse(u);}
	void link(int u,int v){makeroot(u);makeroot(v);fa[u]=v;}
	void cut(int u,int v){makeroot(u);access(v);splay(u);ch[u][1]=fa[v]=0;update(u);}
};
namespace SEG
{
	pii f[MAXM<<2];
	int tag[MAXM<<2];
	void pushdown(int id)
	{
		if(!tag[id])return;
		tag[id<<1]+=tag[id],f[id<<1].x+=tag[id];
		tag[id<<1|1]+=tag[id],f[id<<1|1].x+=tag[id];
		tag[id]=0;
	}
	pii update(pii p,pii q){return p.x==q.x?mp(p.x,p.y+q.y):min(p,q);}
	void build(int id,int l,int r)
	{
		if(l==r){f[id]=mp(0,1);return;}
		int mid=(l+r)>>1;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		f[id]=update(f[id<<1],f[id<<1|1]);
	}
	void modify(int id,int l,int r,int ql,int qr,int c)
	{
		if(l==ql && r==qr){tag[id]+=c;f[id].x+=c;return;}
		pushdown(id);
		int mid=(l+r)>>1;
		if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
		else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
		else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
		f[id]=update(f[id<<1],f[id<<1|1]);
	}
	pii query(int id,int l,int r,int ql,int qr)
	{
		if(l==ql && r==qr)return f[id];
		pushdown(id);
		int mid=(l+r)>>1;
		if(qr<=mid)return query(id<<1,l,mid,ql,qr);
		if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
		return update(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			readint(a[i][j]);
			b[a[i][j]]=mp(i,j);
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int t=0;t<4;++t)
			{
				int x=i+DIR[t][0],y=j+DIR[t][1];
				if(x<=0 || y<=0 || x>n || y>m)continue;
				G[a[i][j]].pb(a[x][y]);
			}
	ll ans=0;
	int l=1;
	SEG::build(1,1,n*m);
	for(int r=1;r<=n*m;++r)
	{
		while(l<r)
		{
			for(auto v:G[r])if(v<r && v>=l)LCT::makeroot(v);
			bool flag=1;
			for(auto v:G[r])if(v<r && v>=l && LCT::fa[v]){flag=0;break;}
			if(flag)break;
			for(auto v:G[l])if(v>l)LCT::cut(l,v);
			++l;
		}
		for(auto v:G[r])if(v<r && v>=l)LCT::link(r,v);
		SEG::modify(1,1,n*m,1,r,1);
		for(auto v:G[r])if(v<r && v>=l)SEG::modify(1,1,n*m,1,v,-1);
		ans+=SEG::query(1,1,n*m,l,r).y;
	}
	printf("%lld\n",ans);
	return 0;
}