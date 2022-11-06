//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9;
vector<long long> G[N];
int n,taxi,id[N],s[N];
long long ans[N];
inline bool cmp(int xxx,int yyy)
{
	return xxx>yyy;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		for(int i=1;i<=n;i++)G[i].clear(),ans[i]=0;
		for(int i=1;i<=n;i++)id[i]=read();
		for(int i=1;i<=n;i++)s[i]=read();
		for(int i=1;i<=n;i++)G[id[i]].push_back(s[i]);
		for(int i=1;i<=n;i++)
			if(G[i].size()!=0)
			{
				sort(G[i].begin(),G[i].end(),cmp);
				for(int j=1;j<G[i].size();j++)G[i][j]+=G[i][j-1];
			}
		for(int i=1;i<=n;i++)
			if(G[i].size()!=0)
			{
				int len=G[i].size();
				for(int k=1;k<=len;k++)
					ans[k]+=G[i][len/k*k-1];	
			}
		for(int i=1;i<=n;i++)printf("%lld ",ans[i]);puts("");
	}
	return 0;
}