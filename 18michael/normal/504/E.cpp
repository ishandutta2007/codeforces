#include<cstdio>
#define Mx 18
#define bs 233
#define LL long long
const int mod=998244853,mod1=1000000009;
int n,m,edge_t=0,dfn_t=0,ans,toa,toc,l,r,mid;
int la[300002]={},dep[300002],siz[300002],son[300002]={},dfn[300002],top[300002],st_t[2];
LL pw[300002],pw1[300002];
char s[300002];
int fa[300002][22],st[300002][2];
LL Hs[300002][2],Hs1[300002][2];
struct aaa
{
	int to,nx;
}edge[600002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
template<class T>void write(T x)
{
	if(x>9)write(x/10);
	putchar((x%10)^48);
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d,siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	top[x]=t,dfn[x]=(++dfn_t),Hs[x][0]=Hs[x][1]=Hs1[x][0]=Hs1[x][1]=s[x];
	if(x!=t)(Hs[x][0]+=Hs[f][0]*bs)%=mod,(Hs1[x][0]+=Hs1[f][0]*bs)%=mod1;
	if(son[x])dfs1(son[x],x,t),(Hs[x][1]+=Hs[son[x]][1]*bs)%=mod,(Hs1[x][1]+=Hs1[son[x]][1]*bs)%=mod1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && v!=son[x])
			dfs1(v,x,v);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		y=fa[top[y]][0];
	}
	return dep[x]<dep[y]? x:y;
}
inline LL get_Hs(int x,int y,int z)
{
	LL res=(z? (Hs[y][1]-(son[x]? Hs[son[x]][1]*pw[dep[x]-dep[y]+1]:0)):(Hs[x][0]-(y==top[y]? 0:Hs[fa[y][0]][0]*pw[dep[x]-dep[y]+1])))%mod;
	return res<0? res+mod:res;
}
inline LL get_Hs1(int x,int y,int z)
{
	LL res=(z? (Hs1[y][1]-(son[x]? Hs1[son[x]][1]*pw1[dep[x]-dep[y]+1]:0)):(Hs1[x][0]-(y==top[y]? 0:Hs1[fa[y][0]][0]*pw1[dep[x]-dep[y]+1])))%mod1;
	return res<0? res+mod1:res;
}
inline bool check(int a,int b,int c,int d,int e,int f)
{
	return get_Hs(a,b,c)==get_Hs(d,e,f) && get_Hs1(a,b,c)==get_Hs1(d,e,f);
}
inline int getfa(int x,int y)
{
	for(int i=Mx;~i;--i)if((y>>i)&1)x=fa[x][i];
	return x;
}
inline bool cmp(int &a,int &c,int &l1,int &l2)
{
	while(dep[a]>=dep[l1] && dep[c]>=dep[l2])
	{
		toa=(dep[top[a]]>dep[l1]? top[a]:l1),toc=(dep[top[c]]>dep[l2]? top[c]:l2);
		if(dep[a]-dep[toa]>dep[c]-dep[toc])toa=getfa(a,dep[c]-dep[toc]);else toc=getfa(c,dep[a]-dep[toa]);
		if(check(a,toa,1,c,toc,1)){ans+=dep[a]-dep[toa]+1,a=fa[toa][0],c=fa[toc][0];continue;}
		for(l=0,r=dep[a]-dep[toa];l<=r;)
		{
			mid=((l+r)>>1);
			if(check(a,getfa(a,mid),1,c,getfa(c,mid),1))l=mid+1;else r=mid-1;
		}
		ans+=l;
		return 0;
	}
	return 1;
}
inline bool cmp1(int &a,int b,int &c,int &l2)
{
	while(st_t[0] && dep[c]>=dep[l2])
	{
		toa=st[st_t[0]][0],toc=(dep[top[c]]>dep[l2]? top[c]:l2);
		if(dep[toa]-dep[a]>dep[c]-dep[toc])toa=getfa(toa,dep[toa]-dep[a]-dep[c]+dep[toc]);else toc=getfa(c,dep[toa]-dep[a]);
		if(check(toa,a,0,c,toc,1))
		{
			ans+=dep[toa]-dep[a]+1;if(b==toa)return 0;
			a=getfa(b,dep[b]-dep[toa]-1),st_t[0]-=(dep[a]>dep[st[st_t[0]][0]]),c=fa[toc][0];
			continue;
		}
		for(l=0,r=dep[toa]-dep[a];l<=r;)
		{
			mid=((l+r)>>1);
			if(check(getfa(toa,dep[toa]-dep[a]-mid),a,0,c,getfa(c,mid),1))l=mid+1;else r=mid-1;
		}
		ans+=l;
		return 0;
	}
	return 1;
}
inline void cmp2(int &a,int b,int &c,int d)
{
	while(st_t[0] && st_t[1])
	{
		toa=st[st_t[0]][0],toc=st[st_t[1]][1];
		if(dep[toa]-dep[a]>dep[toc]-dep[c])toa=getfa(toa,dep[toa]-dep[a]-dep[toc]+dep[c]);else toc=getfa(toc,dep[toc]-dep[c]-dep[toa]+dep[a]);
		if(check(toa,a,0,toc,c,0))
		{
			ans+=dep[toa]-dep[a]+1;if(b==toa || d==toc)return ;
			a=getfa(b,dep[b]-dep[toa]-1),st_t[0]-=(dep[a]>dep[st[st_t[0]][0]]),c=getfa(d,dep[d]-dep[toc]-1),st_t[1]-=(dep[c]>dep[st[st_t[1]][1]]);
			continue;
		}
		for(l=0,r=dep[toa]-dep[a];l<=r;)
		{
			mid=((l+r)>>1);
			if(check(getfa(toa,dep[toa]-dep[a]-mid),a,0,getfa(toc,dep[toc]-dep[c]-mid),c,0))l=mid+1;else r=mid-1;
		}
		ans+=l;
		return ;
	}
}
int main()
{
	read(n),scanf("%s",s+1),pw[0]=pw1[0]=1;
	for(int i=1;i<=n;++i)pw[i]=(pw[i-1]*bs)%mod,pw1[i]=(pw1[i-1]*bs)%mod1;
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	dfs(1,0,1),dfs1(1,0,1),get_LCA(),read(m);
	for(int a,b,c,d,l1,l2;m--;)
	{
		read(a),read(b),read(c),read(d),l1=LCA(a,b),l2=LCA(c,d),ans=0;
		if(dep[a]-dep[l1]>dep[c]-dep[l2])swap(a,c),swap(b,d),swap(l1,l2);
		if(cmp(a,c,l1,l2) && b!=l1)
		{
			a=getfa(b,dep[b]-dep[l1]-1),st_t[0]=st_t[1]=0;
			for(int i=b;dep[i]>dep[l1];i=fa[top[i]][0])st[++st_t[0]][0]=i;
			for(int i=d;dep[i]>dep[l2];i=fa[top[i]][0])st[++st_t[1]][1]=i;
			if(cmp1(a,b,c,l2) && d!=l2)c=getfa(d,dep[d]-dep[l2]-1),cmp2(a,b,c,d);
		}
		write(ans),putchar('\n');
	}
	return 0;
}