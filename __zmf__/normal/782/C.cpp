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
int n,cnt,col[N];
int to[N],nxt[N],head[N],ans;
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline void dfs(int u,int f)
{
	int now=0;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			now++;
			while(now==col[u]||now==col[f])now++;
			col[to[i]]=now;dfs(to[i],u);
		}
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int uu=read(),vv=read();addedge(uu,vv);addedge(vv,uu);
	}
	col[1]=1;
	dfs(1,0);//for(int i=1;i<=n;i++)cout<<col[i]<<" ";
	for(int i=1;i<=n;i++)ans=max(ans,col[i]);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)cout<<col[i]<<" ";
	return 0;
}