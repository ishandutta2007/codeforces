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
int n,m,taxi,ind[N],outd[N],x,y,vis[N],ans;
vector<int> G[N];
inline void work(int col)
{
	for(int i=1;i<=n;i++)
		if(ind[i]==0&&vis[i]==0)vis[i]=col;
	for(int i=1;i<=n;i++)
		if(vis[i]==col)
		{
			for(int j=0;j<G[i].size();j++)
				ind[G[i][j]]--;
		}
//	cout<<endl;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
	//	cout<<ttt<<"---------"<<endl;
		n=read(),m=read();
		for(int i=1;i<=n;i++)G[i].clear(),ind[i]=0,vis[i]=1;
		for(int i=1;i<=m;i++)
		{
			x=read(),y=read();ind[y]++;
			G[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<G[i].size();j++)
			{
				if(vis[G[i][j]]==2)vis[i]=3;
				else if(vis[i]!=3&&vis[G[i][j]]==1)vis[i]=2;
			}
	//	for(int i=1;i<=n;i++)cout<<vis[i]<<" ";cout<<endl;
		ans=0;
		for(int i=1;i<=n;i++)
			if(vis[i]==3)ans++;
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			if(vis[i]==3)printf("%d ",i);puts("");
		
	}
	return 0;
}
/*
1
5 7
2 3
1 5
4 5
2 4
3 4
1 2
3 5
*/