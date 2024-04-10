	//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=4e5+9,mod=1e9+7;
int taxi,n,a[N],b[N],res,ans,vis[N],to[N];
inline void dfs(int u)
{
	if(vis[u])return ;
	vis[u]=1;dfs(to[u]);
}
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		res=0,ans=1;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)to[a[i]]=b[i];
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				dfs(i);res++;
			}
		for(int i=1;i<=res;i++)ans=ans*2%mod;
		printf("%lld\n",ans);
	}
	return 0;
}