#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,Test_num;
int p[200002];
LL s[200002];
LL ans[200002][2];
vector<LL> Vec;
vector<int> vec[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(LL x,LL y)
{
	return x>y;
}
inline void dfs(int x,int k)//k ~ k+1
{
	//printf("DFS %d %d\n",x,k);
	ans[x][0]=ans[x][1]=0;
	if(vec[x].size())
	{
		for(int i=0,v;i<vec[x].size();++i)
		{
			v=vec[x][i];
			dfs(v,k/vec[x].size());
			ans[x][0]+=ans[v][0];
			ans[x][1]+=ans[v][0];
		}
		Vec.clear();
		for(int i=0,v;i<vec[x].size();++i)
		{
			v=vec[x][i];
			Vec.push_back(ans[v][1]-ans[v][0]);
		}
		sort(Vec.begin(),Vec.end(),cmp);
		for(int i=(int)(k%vec[x].size())-1;~i;--i)ans[x][0]+=Vec[i];
		for(int i=(int)(k%vec[x].size());~i;--i)ans[x][1]+=Vec[i];
	}
	ans[x][0]+=s[x]*k,ans[x][1]+=s[x]*(k+1);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k);
		for(int i=1;i<=n;++i)vec[i].clear();
		for(int i=2;i<=n;++i)read(p[i]),vec[p[i]].push_back(i);
		for(int i=1;i<=n;++i)read(s[i]);
		dfs(1,k),printf("%lld\n",ans[1][0]);
	}
	return 0;
}