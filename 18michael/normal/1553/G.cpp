#include<bits/stdc++.h>
#define Mx 1000001
using namespace std;
int n,q,p_t=0;
int a[150002],p[1000002],to[1000002],top[1000002],rt[150002];
bool u[1000002];
vector<int> vec[1000002];
set<int> s[150002];
inline void getroot(int x)
{
	if(rt[x]==x)return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
int main()
{
	init(),scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),rt[i]=to[a[i]]=i;
	for(int i=1;i<=p_t;++i)
		for(int j=p[i];j<=Mx;vec[j].push_back(i),j+=p[i])
			if(to[j])
			{
				if(top[i])getroot(top[i]),getroot(to[j]),rt[rt[top[i]]]=rt[to[j]];
				else top[i]=to[j];
			}
	for(int i=1;i<=n;++i)getroot(i);
	for(int i=1;i<=n;++i)
		for(int j=0;j<vec[a[i]+1].size();++j)
			if(top[vec[a[i]+1][j]])
			{
				s[rt[i]].insert(rt[top[vec[a[i]+1][j]]]);
				for(int k=j+1;k<vec[a[i]+1].size();++k)if(top[vec[a[i]+1][k]])s[rt[top[vec[a[i]+1][j]]]].insert(rt[top[vec[a[i]+1][k]]]);
			}
	for(int x,y;q--;)scanf("%d%d",&x,&y),puts(rt[x]==rt[y]? "0":((s[rt[x]].count(rt[y]) || s[rt[y]].count(rt[x]))? "1":"2"));
	return 0;
}