#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
int n,Test_num,ans;
LL l[200002],r[200002];
vector<int> vec[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int x)
{
	if(!vec[x].size())return (void)(++ans);
	LL L=0,R=0;
	for(int i=0;i<vec[x].size();++i)dfs(vec[x][i]),L+=l[vec[x][i]],R+=r[vec[x][i]];
	if(l[x]>min(R,r[x]))++ans;
	else r[x]=min(R,r[x]);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ans=0;
		for(int i=1;i<=n;++i)vec[i].clear();
		for(int i=2,x;i<=n;++i)read(x),vec[x].push_back(i);
		for(int i=1;i<=n;++i)read(l[i]),read(r[i]);
		dfs(1),printf("%d\n",ans);
	}
	return 0;
}