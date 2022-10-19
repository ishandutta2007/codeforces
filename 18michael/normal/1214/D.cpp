#include<bits/stdc++.h>
using namespace std;
int n,m,ans=2;char ch;int cnt[1000002]={};
vector<int> vec[1000002],u[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void dfs(int x,int y)
{
	u[x][y]=1;if(x==n-1 && y==m-1)return ;
	if(x+1<n && !u[x+1][y] && !vec[x+1][y])dfs(x+1,y);
	if(y+1<m && !u[x][y+1] && !vec[x][y+1])dfs(x,y+1);
}
inline void dfs1(int x,int y)
{
	u[x][y]=0,++cnt[x+y];if(!x && !y)return ;
	if(x && u[x-1][y] && !vec[x-1][y])dfs1(x-1,y);
	if(y && u[x][y-1] && !vec[x][y-1])dfs1(x,y-1);
}
int main()
{
	read(n),read(m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			do ch=getchar();while(ch!='.' && ch!='#');
			vec[i].push_back(ch=='#'),u[i].push_back(0);
		}
	dfs(0,0),dfs1(n-1,m-1);
	for(int i=1;i<n+m-2;++i)ans=min(ans,cnt[i]);
	return 0&printf("%d",ans);
}