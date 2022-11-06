//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=4e5+9;
map<int,bool> mp[N][2];
int n,a[N],ans[N];
int to[N],cnt,nxt[N],head[N];
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline int Gcd(int x,int y)
{
	if(y==0)return x;
	else return Gcd(y,x%y);
}
inline void dfs(int u,int f,int flag,int now)
{
	if(mp[u][flag][now])return ;
	mp[u][flag][now]=1;
	ans[u]=max(ans[u],Gcd(now,a[u]));
	if(!flag)ans[u]=max(ans[u],now);
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs(to[i],u,flag,Gcd(now,a[u]));
			if(!flag)dfs(to[i],u,1,now);
		}
	return ;
}
int main()
{
	n=read();for(int i=1;i<=n;i++)a[i]=read(),ans[i]=1;
	for(int i=2;i<=n;i++)
	{
		int uu=read(),vv=read();addedge(uu,vv);addedge(vv,uu);
	}
	dfs(1,0,0,0);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}