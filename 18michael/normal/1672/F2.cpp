#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,mx,Test_num,edge_t;
int a[1000002],cnt[1000002],b[1000002],id[1000002],c[1000002],la[1000002],deg[1000002];
queue<int> q,ept;
struct aaa
{
	int to,nx;
}edge[2000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	if(a[x]==a[y])return 0;
	if(a[x]==mx)return 1;
	if(a[y]==mx)return 0;
	return a[x]<a[y];
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
}
inline bool Topo()
{
	q=ept;
	for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
	int p;
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
		{
			--deg[v=edge[i].to];
			if(!deg[v])q.push(v);
		}
	}
	for(int i=1;i<=n;++i)if(deg[i])return 0;
	return 1;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),mx=1,edge_t=0;
		for(int i=1;i<=n;++i)la[i]=cnt[i]=deg[i]=0;
		for(int i=1;i<=n;++i)
		{
			read(a[i]),++cnt[a[i]],id[i]=i;
			if(cnt[a[i]]>cnt[mx])mx=a[i];
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;++i)b[id[i]]=a[id[(i+cnt[mx]-1)%n+1]];
		for(int i=1;i<=n;++i)
		{
			read(c[i]);
			if(a[i]!=mx)add_edge(a[i],c[i]);
		}
		puts(Topo()? "AC":"WA");
	}
	return 0;
}