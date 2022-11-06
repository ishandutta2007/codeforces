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
int n,x; 
int to[N],cnt,nxt[N],head[N],len,nowx,ans;
int fa[N],dep[N],max_dep[N];
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline void dfs(int u,int f)
{
	fa[u]=f;
	max_dep[u]=dep[u]=dep[f]+1;
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs(to[i],u);
			max_dep[u]=max(max_dep[u],max_dep[to[i]]);
		}
}
int main()
{
	n=read(),x=read();nowx=x;
	for(int i=1;i<n;i++)
	{
		int uu=read(),vv=read();addedge(uu,vv);addedge(vv,uu);
	}
	dfs(1,0);
	len=dep[x]-1;
	for(int i=1;i<=(len-1)/2;i++)nowx=fa[nowx];
//	cout<<nowx<<endl;
	printf("%d\n",2*(max_dep[nowx]-1));
	return 0;
}