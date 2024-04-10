#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,edge_t,Test_num,p;
int la[1002],deg[1002],deg2[1002];
LL ans,mn;
LL a[1002],b[1002];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[1002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
}
inline bool check()
{
	for(int i=1;i<=n;++i)if(a[i])return 1;
	return 0;
}
inline void solve()
{
	read(n),read(m),edge_t=ans=0;
	for(int i=1;i<=n;++i)read(a[i]),la[i]=deg[i]=0;
	for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,y);
	for(int i=1;i<=n && check();++i,++ans)
	{
		for(int j=1;j<=n;++j)b[j]=a[j];
		for(int j=1;j<=n;++j)if(a[j])
		{
			--b[j];
			for(int k=la[j];k;k=edge[k].nx)++b[edge[k].to];
		}
		for(int j=1;j<=n;++j)a[j]=b[j];
	}
	for(;check();)
	{
		//printf("ans:%lld    ",ans);for(int j=1;j<=n;++j)printf("%lld%c",a[j],j==n? '\n':' ');
		for(int j=1;j<=n;++j)
		{
			deg2[j]=deg[j];
			if(!deg2[j] && !a[j])q.push(j);
		}
		for(;q.size();)
		{
			p=q.front(),q.pop();
			//printf("p:%d\n",p);
			for(int i=la[p],v;i;i=edge[i].nx)
			{
				--deg2[v=edge[i].to];
				//printf("  %d -> %d\n",p,v);
				if(!deg2[v] && !a[v])q.push(v);
			}
		}
		//printf("deg2:");for(int i=1;i<=n;++i)printf("%d%c",deg2[i],i==n? '\n':' ');
		mn=inf;
		for(int i=1;i<=n;++i)if(!deg2[i] && a[i])mn=min(mn,a[i])/*,printf("%d:%lld\n",i,a[i])*/;
		for(int j=1;j<=n;++j)b[j]=a[j];
		for(int j=1;j<=n;++j)if(a[j])
		{
			b[j]-=mn;
			for(int k=la[j];k;k=edge[k].nx)b[edge[k].to]+=mn;
		}
		for(int j=1;j<=n;++j)a[j]=(b[j]<=mod? b[j]:(mod+(b[j]%mod)));
		(ans+=mn)%=mod;
	}
	printf("%lld\n",ans);
}
int main()
{
	read(Test_num);
	while(Test_num--)solve();
	return 0;
}