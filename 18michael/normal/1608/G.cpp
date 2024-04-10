#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 16
#define bs 19260817
#define LL long long
#define Mxl 200000
using namespace std;
int n,m,q,edge_t=0,t=0,M=200000,st_t;
char c;
char ch[200002];
int la[200002]={},dep[200002],s[200002],ed[200002],cnt[200002]={},rk[200002],sa[200002],id[200002],px[200002],
oldrk[200002],rt[200002],num[200002],siz[200002],son[200002],top[200002],st[200002],st1[200002],dep2[200002],cf[200002];
LL Hs[200002],pw[200002],Hs2[200002];
int fa[200002][18];
LL HsU[200002][18];
vector<int> vec[200002];
struct aaa
{
	int to,nx;
	char c;
}edge[200002];
struct SegTree
{
	int t;
	int lson[12000002],rson[12000002],sum[12000002];
	inline void build(int k,int l,int r)
	{
		if(l==r)return ;
		int mid=((l+r)>>1);
		build(lson[k]=(++t),l,mid),build(rson[k]=(++t),mid+1,r);
	}
	inline void modify(int k,int k1,int l,int r,int x)
	{
		sum[k]=sum[k1]+1;
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(x<=mid)modify(lson[k]=(++t),lson[k1],l,mid,x),rson[k]=rson[k1];
		else modify(rson[k]=(++t),rson[k1],mid+1,r,x),lson[k]=lson[k1];
	}
	inline int query(int k,int k1,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k]-sum[k1];
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],lson[k1],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],rson[k1],mid+1,r,l1,r1);
		return query(lson[k],lson[k1],l,mid,l1,mid)+query(rson[k],rson[k1],mid+1,r,mid+1,r1);
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,char c)
{
	edge[++edge_t]=(aaa){y,la[x],c},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],c},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d,siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			cf[v]=edge[i].c,dfs(v,x,d+1),HsU[v][0]=edge[i].c,siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	top[x]=t,vec[t].push_back(x);
	if(x==t)dep2[x]=0,Hs2[x]=cf[x];
	else dep2[x]=dep2[f]+1,Hs2[x]=Hs2[f]*bs+cf[x];
	if(son[x])dfs1(son[x],x,t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
inline void get_LCA()
{
	LL tmp=bs;
	for(int i=1;i<=Mx;++i)
	{
		for(int j=1;j<=n;++j)fa[j][i]=fa[fa[j][i-1]][i-1],HsU[j][i]=HsU[j][i-1]*tmp+HsU[fa[j][i-1]][i-1];
		tmp*=tmp;
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline LL get_Hs(int l,int r)
{
	return Hs[r]-Hs[l-1]*pw[r-l+1];
}
inline LL get_Hs2(int l,int r)
{
	return Hs2[r]-(dep2[l]? Hs2[fa[l][0]]:0)*pw[dep[r]-dep[fa[l][0]]];
}
inline bool cmp(int x,int y,int w)
{
	return oldrk[x]==oldrk[y] && oldrk[x+w]==oldrk[y+w];
}
inline void get_SA()
{
	for(int i=1;i<=t;++i)++cnt[rk[i]=s[i]];
	for(int i=1;i<=M;++i)cnt[i]+=cnt[i-1];
	for(int i=t;i;--i)sa[cnt[rk[i]]--]=i;
	for(int w=1,p=0;w<t && p<t;w<<=1,M=p)
	{
		p=0;
		for(int i=t;i>t-w;--i)id[++p]=i;
		for(int i=1;i<=t;++i)if(sa[i]>w)id[++p]=sa[i]-w;
		for(int i=0;i<=M;++i)cnt[i]=0;
		for(int i=1;i<=t;++i)++cnt[px[i]=rk[id[i]]];
		for(int i=1;i<=M;++i)cnt[i]+=cnt[i-1];
		for(int i=t;i;--i)sa[cnt[px[i]]--]=id[i];
		for(int i=1;i<=t;++i)oldrk[i]=rk[i];
		p=0;
		for(int i=1;i<=t;++i)rk[sa[i]]=cmp(sa[i],sa[i-1],w)? p:(++p);
	}
}
inline bool cmp2(int now,int w,int len)
{
	int l=0,r=len-1,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(get_Hs(now,now+mid)==get_Hs2(w,vec[top[w]][dep2[w]+mid]))l=mid+1;
		else r=mid-1;
	}
	return s[now+l]>cf[vec[top[w]][dep2[w]+l]];
}
inline bool cmp1(int u,int x,int y,int z,bool ok)
{
	int l0=t-sa[u]+1,l1=dep[x]+dep[y]-2*dep[z],l=0,r=min(l0,l1),mid,now=sa[u],wt,wb;
	for(int i=Mx;~i;--i)
	{
		if(dep[fa[x][i]]<dep[z] || now+(1<<i)-1>t)continue;
		if(get_Hs(now,now+(1<<i)-1)==HsU[x][i])now+=(1<<i),x=fa[x][i];
	}
	if(dep[x]>dep[z])
	{
		if(now>t)return 0;
		return s[now]>HsU[x][0];
	}
	st_t=0,x=y;
	for(int i=Mx;~i;--i)if(dep[fa[x][i]]>dep[z])x=fa[x][i];
	if(dep[x]>dep[z])
	{
		for(z=x,x=y;dep[x]>=dep[z];x=fa[top[x]][0])st[++st_t]=top[x],st1[st_t]=x;
		while(st_t)
		{
			wt=top[st[st_t]],wb=st1[st_t];
			if(dep[wt]<dep[z])wt=z;
			if(now+dep[wb]-dep[wt]>t || get_Hs(now,now+dep[wb]-dep[wt])!=get_Hs2(wt,wb))return cmp2(now,wt,dep[wb]-dep[wt]+1);
			now+=dep[wb]-dep[wt]+1,--st_t;
		}
	}
	return ok;
}
int main()
{
	read(n),read(m),read(q),pw[0]=1;
	for(int i=1;i<=Mxl;++i)pw[i]=pw[i-1]*bs;
	for(int i=1,x,y;i<n;++i)
	{
		read(x),read(y);
		do c=getchar();while(c<'a' || c>'z');
		add_edge(x,y,c);
	}
	dfs(1,0,1),dfs1(1,0,1),get_LCA();
	for(int i=1,l;i<=m;++i)
	{
		scanf("%s",ch),l=strlen(ch);
		for(int j=0;j<l;++j)s[++t]=ch[j],Hs[t]=Hs[t-1]*bs+s[t];
		s[++t]=i+200,Hs[t]=Hs[t-1]*bs+s[t],ed[i]=t;
	}
	get_SA(),S.build(rt[0]=(++S.t),1,m);
	for(int i=1,t1=0;i<=t;++i)
	{
		if(ed[t1]<i)++t1;
		num[rk[i]]=t1;
	}
	for(int i=1;i<=t;++i)S.modify(rt[i]=(++S.t),rt[i-1],1,m,num[i]);
	for(int x,y,z,l,r,L,R,Mid,St,Ed;q--;)
	{
		read(x),read(y),read(l),read(r),z=LCA(x,y);
		for(L=1,R=t;L<=R;)
		{
			Mid=((L+R)>>1);
			if(cmp1(Mid,x,y,z,1))R=Mid-1;
			else L=Mid+1;
		}
		St=L;
		for(L=1,R=t;L<=R;)
		{
			Mid=((L+R)>>1);
			if(cmp1(Mid,x,y,z,0))R=Mid-1;
			else L=Mid+1;
		}
		Ed=R,printf("%d\n",S.query(rt[Ed],rt[St-1],1,m,l,r));
	}
	return 0;
}