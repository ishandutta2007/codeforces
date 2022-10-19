#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,vec_t=0,t=1,tmp;
bool ok=0;
int a[1002];
bool vis[1002];
vector<int> vec[1002];
char s[1002][1002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int x)
{
	vis[x]=1,vec[vec_t].push_back(x);
	if(!vis[a[x]])dfs(a[x]);
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		for(int j=1;j<=n;++j)s[i][j]='.';
	}
	for(int i=1;i<=n;++i)if(!vis[i])++vec_t,dfs(i);
	for(int i=1,x;i<=vec_t;++i)
		if(vec[i].size()>1)
		{
			x=t,t+=ok;
			for(int j=1;j<vec[i].size();++j)s[t][vec[i][j]]=s[t][a[vec[i][j]]]=(vec[i][j]<a[vec[i][j]]? '/':'\\'),++t;
			if(ok)s[t-1][tmp]='\\',s[x][tmp]=s[x][a[vec[i][0]]]='/';
			else tmp=vec[i][0],ok=1;
		}
	printf("%d\n",n-(t>1));
	for(int i=1;i<=n;++i)printf("%s\n",s[i]+1);
	return 0;
}