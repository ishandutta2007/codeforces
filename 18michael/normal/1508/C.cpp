#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=0,sum=0,rt_t=0;
LL t,ans=0;
int rt[200002]={};
vector<int> vec[200002];
set<int> s;
struct aaa
{
	int x,y,val,u;
}e[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val<b.val? 1:0;
}
inline void add_edge(int x,int y,int z,int i)
{
	e[i]=(aaa){x,y,z,0},vec[x].push_back(y),vec[y].push_back(x);
}
inline void dfs(int x,int y)
{
	int i,j;s.erase(x),rt[x]=y;
	set<int>::iterator it;
	for(int i=1;;++i)
	{
		it=s.lower_bound(i);
		if(it==s.end())return ;
		i=(*it),j=lower_bound(vec[x].begin(),vec[x].end(),i)-vec[x].begin();
		if(j==vec[x].size() || vec[x][j]>i)dfs(i,y);
	}
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(n),read(m),t=(1LL*n*(n-1))/2-m;
	for(int i=1,x,y,z;i<=m;++i)read(x),read(y),read(z),sum^=z,add_edge(x,y,z,i);
	for(int i=1;i<=n;++i)s.insert(i),sort(vec[i].begin(),vec[i].end());
	for(int i=1;i<=n;++i)if(!rt[i])++rt_t,dfs(i,i);
	sort(e+1,e+m+1,cmp);
	for(int i=1,x,y;i<=m;++i)
	{
		x=e[i].x,y=e[i].y,getroot(x),getroot(y);
		if(rt[x]==rt[y])continue;
		rt[rt[x]]=rt[y],ans+=e[i].val,e[i].u=1;
	}
	if(n-rt_t==t)
	{
		for(int i=1;i<=n;++i)rt[i]=i;
		for(int i=1,x,y;i<=m;++i)if(e[i].u)x=e[i].x,y=e[i].y,getroot(x),getroot(y),rt[rt[x]]=rt[y];
		for(int i=1,x,y;i<=m;++i)
			if(!e[i].u)
			{
				x=e[i].x,y=e[i].y,getroot(x),getroot(y);
				if(rt[x]==rt[y])continue;
				sum=min(sum,e[i].val);break;
			}
	}
	else sum=0;
	printf("%lld",ans+sum);
	return 0;
}