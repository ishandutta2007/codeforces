#include<cstdio>
#include<algorithm>
#include<vector>
#define Mx 16
#define Mx1 10000000
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,m3,t=1,t1,t2,edge_t=0,dfn_t=0,p_t=0;
int la[100002]={},a[100002],dep[100002],dfn[100002],p[664582],ip[664582],to[10000002],mnp[10000002];
bool u[10000002]={};
LL ans[100002];
int fa[100002][18];
vector<int> pw[664582],ipw[664582];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int x,w,id;
	bool p;
}qry[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(bbb a,bbb b)
{
	return dfn[a.x]<dfn[b.x]? 1:0;
}
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void init()
{
	for(int i=2;i<=Mx1;++i)
	{
		if(!u[i])
		{
			p[++p_t]=mnp[i]=i,ip[p_t]=Pow(i,mod-2),to[i]=p_t,pw[p_t].push_back(1),ipw[p_t].push_back(1);
			for(t=1;t<=Mx1/i;t*=i)pw[p_t].push_back(1),ipw[p_t].push_back(1);
		}
		for(int j=1,k;j<=p_t && p[j]<=Mx1/i;++j)
		{
			u[k=i*p[j]]=1,mnp[k]=p[j];
			if(!(i%p[j]))break;
		}
	}
}
inline void dfs(int x,int f,int d)
{
	dep[x]=d,fa[x][0]=f,dfn[x]=(++dfn_t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
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
inline void dfs1(int x,int f)
{
	int tmp=a[x];
	while(tmp>1)
	{
		t1=0,t2=mnp[tmp];
		do tmp/=t2,++t1;while(!(tmp%t2));
		pw[to[t2]][t1]=(1LL*pw[to[t2]][t1]*t2)%mod,ipw[to[t2]][t1]=(1LL*ipw[to[t2]][t1]*ip[to[t2]])%mod;
	}
	while(t<=m3 && qry[t].x==x)
	{
		tmp=qry[t].w;
		while(tmp>1)
		{
			t1=0,t2=mnp[tmp];
			do tmp/=t2,++t1;while(!(tmp%t2));
			for(int j=1;j<=t1;++j)
			{
				if(qry[t].p)ans[qry[t].id]=(ans[qry[t].id]*Pow(pw[to[t2]][j],j))%mod;
				else ans[qry[t].id]=(ans[qry[t].id]*Pow(ipw[to[t2]][j],2*j))%mod;
			}
			for(int j=t1+1;j<pw[to[t2]].size();++j)
			{
				if(qry[t].p)ans[qry[t].id]=(ans[qry[t].id]*Pow(pw[to[t2]][j],t1))%mod;
				else ans[qry[t].id]=(ans[qry[t].id]*Pow(ipw[to[t2]][j],2*t1))%mod;
			}
		}
		++t;
	}
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs1(v,x);
	tmp=a[x];
	while(tmp>1)
	{
		t1=0,t2=mnp[tmp];
		do tmp/=t2,++t1;while(!(tmp%t2));
		pw[to[t2]][t1]=(1LL*pw[to[t2]][t1]*ip[to[t2]])%mod,ipw[to[t2]][t1]=(1LL*ipw[to[t2]][t1]*t2)%mod;
	}
}
int main()
{
	init(),read(n);
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	for(int i=1;i<=n;++i)read(a[i]);
	dfs(1,0,1),get_LCA(),read(m),m3=m*3;
	for(int i=1,x,y,z,w;i<=m;++i)read(x),read(y),read(w),qry[3*i-2]=(bbb){x,w,i,1},qry[3*i-1]=(bbb){y,w,i,1},qry[3*i]=(bbb){z=LCA(x,y),w,i,0},ans[i]=gcd(w,a[z]);
	sort(qry+1,qry+m3+1,cmp),t=1,dfs1(1,0);
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}