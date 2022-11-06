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
const int N=1e6+9;
int n,a[N];
int nxt[N*2],to[N*2],head[N],cnt,val[N],dis[N];	
inline void addedge(int u,int v,int w)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt,val[cnt]=w;
}
inline void dfs(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dis[to[i]]=dis[u]+val[i];
			dfs(to[i],u);
		}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int uu=read(),vv=read(),ww;
		if(a[uu]==a[vv])ww=0;else ww=1;
		addedge(uu,vv,ww);addedge(vv,uu,ww);
	//	cout<<uu<<" "<<vv<<" "<<ww<<endl;
	}
	dfs(1,0);
	int fath=0;
	for(int i=1;i<=n;i++)
		if(dis[i]>dis[fath])fath=i;
	dis[fath]=0;
	dfs(fath,0);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
	cout<<(ans+1)/2<<endl;
	return 0;
}