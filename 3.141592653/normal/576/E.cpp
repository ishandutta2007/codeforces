#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n,m,k,q;
int fa[52][500005];
bool len[52][500005];
int stkx[52][500005],stky[52][500005],top[52];
int siz[52][500005];
int rt(int*f,int x)
{return(f[x])?rt(f,f[x]):x;}
int dis(int*f,bool*l,int x)
{return(f[x])?dis(f,l,f[x])+(int)l[x]:0;}
int uni(int*f,bool*l,int*sx,int*sy,int*sz,int&tp,int x,int y)
{
	int u=dis(f,l,x),v=dis(f,l,y),s=u+v;
	x=rt(f,x),y=rt(f,y);
	if(x==y)return s&1;
	if(siz[x]<siz[y])x^=y^=x^=y,u^=v^=u^=v;
	f[y]=x,sx[++tp]=x,sy[tp]=y,sz[x]+=sz[y],l[y]=(1+s)&1;
	return 2;
}
void del(int*f,bool*l,int*sx,int*sy,int*sz,int&tp)
{int x=sx[tp],y=sy[tp--];f[y]=0,sz[x]-=sz[y];}
#include<vector>
struct pii
{int p,c;};
std::vector<pii>v[2222222];
int x[1111111],y[1111111],c[1111111];
int rv[1111111],e[1111111],g[1111111],ls[1111111];
void modify(int l,int r,pii d,int p=1,int pl=1,int pr=q)
{
	if(pl>r||l>pr)return;
	if(l<=pl&&pr<=r)return v[p].push_back(d);
	int mid=(pl+pr)>>1;
	modify(l,r,d,p<<1,pl,mid),modify(l,r,d,p<<1|1,mid+1,pr);
}
void solve(int l=1,int r=q,int p=1)
{
	register int i;
	int vg[55];
	for(i=1;i<=k;i++)vg[i]=top[i];
	for(auto rm:v[p])
		uni(fa[rm.c],len[rm.c],stkx[rm.c],stky[rm.c],siz[rm.c],top[rm.c],x[rm.p],y[rm.p]);
	v[p].clear();
	if(l==r)
	{
		int o=e[l],cc=g[l],ts=uni(fa[cc],len[cc],stkx[cc],stky[cc],siz[cc],top[cc],x[o],y[o]);
		if(ts)
		{
			puts("YES"),c[o]=cc;
			if(ts==2)del(fa[cc],len[cc],stkx[cc],stky[cc],siz[cc],top[cc]);
		}else puts("NO");
		if(c[o])modify(l+1,rv[l]-1,pii{o,c[o]});return;
	}int mid=(l+r)>>1;
	solve(l,mid,p<<1),solve(mid+1,r,p<<1|1);
	for(i=1;i<=k;i++)
		while(top[i]>vg[i])
			del(fa[i],len[i],stkx[i],stky[i],siz[i],top[i]);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	register int i,ii;
	for(i=1;i<=m;i++)
		scanf("%d%d",x+i,y+i);
	for(i=1;i<=k;i++)
		for(ii=1;ii<=n;ii++)
			siz[i][ii]=1;
	for(i=1;i<=q;i++)
		scanf("%d%d",e+i,g+i),ls[e[i]]=rv[ls[e[i]]]=i;
	for(i=1;i<=q;i++)if(!rv[i])rv[i]=q+1;
	solve();
}
/*
Just go for it.
*/