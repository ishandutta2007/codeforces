#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=500005,MAXV=1100005,MAXK=51;
typedef pair<int,int> ppi;

int n,E,k,m;
int u[MAXN],v[MAXN],e[MAXN],col[MAXN],las[MAXN],nxt[MAXN];
vector<pii> cg[MAXV];
stack<int> gar[MAXK];
int fa[MAXK][MAXN<<1|1],size[MAXK][MAXN<<1|1];
void init(int w){for(int i=1;i<=2*n;++i)fa[w][i]=i,size[w][i]=1;}
bool merge(int w,int u,int v,int id)
{
	for(;u!=fa[w][u];u=fa[w][u]);
	for(;v!=fa[w][v];v=fa[w][v]);
	if(u==v)return 0;
	if(size[w][u]>size[w][v])swap(u,v);
	fa[w][u]=v;size[w][v]+=size[w][u];
	gar[w].push(u);
	return 1;
}
bool query(int w,int u,int v)
{
	for(;u!=fa[w][u];u=fa[w][u]);
	for(;v!=fa[w][v];v=fa[w][v]);
	return u==v;
}
void undo(int w)
{
	int t=gar[w].top();gar[w].pop();
	size[w][fa[w][t]]-=size[w][t];
	fa[w][t]=t;
}

void modify(int id,int l,int r,int ql,int qr,pii p)
{
	if(l==ql && r==qr)return cg[id].pb(p);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,p);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,p);
	else modify(id<<1,l,mid,ql,mid,p),modify(id<<1|1,mid+1,r,mid+1,qr,p);
}
void dfs(int id,int l,int r)
{
	int cnt[MAXK]={0};
	for(auto p:cg[id])
	{
		cnt[p.y]+=merge(p.y,u[p.x],v[p.x]+n,id);
		cnt[p.y]+=merge(p.y,u[p.x]+n,v[p.x],id);
	}
	cg[id].clear();
	if(l==r)
	{
		cnt[col[l]]+=merge(col[l],u[e[l]],v[e[l]]+n,id);
		cnt[col[l]]+=merge(col[l],u[e[l]]+n,v[e[l]],id);
		if(!query(col[l],u[e[l]],u[e[l]]+n))
		{
			las[e[l]]=col[l];
			printf("YES\n");
		}
		else printf("NO\n");
		for(int i=1;i<=k;++i)while(cnt[i]--)undo(i);
		if(nxt[l]-l>=2)modify(1,1,m,l+1,nxt[l]-1,mp(e[l],las[e[l]]));
		return;
	}
	int mid=(l+r)>>1;
	dfs(id<<1,l,mid);
	dfs(id<<1|1,mid+1,r);
	for(int i=1;i<=k;++i)while(cnt[i]--)undo(i);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);readint(E);readint(k);readint(m);
	for(int i=1;i<=k;++i)init(i);
	for(int i=1;i<=E;++i)readint(u[i]),readint(v[i]);
	for(int i=1;i<=m;++i)readint(e[i]),readint(col[i]);
	for(int i=1;i<=E;++i)las[i]=m+1;
	for(int i=m;i;--i)nxt[i]=las[e[i]],las[e[i]]=i;
	memset(las,0,sizeof(las));
	dfs(1,1,m);
	return 0;
}