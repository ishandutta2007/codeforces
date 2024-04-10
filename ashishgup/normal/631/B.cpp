#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;
const int M=1e5+5;

int n, m, k;
int a[N][N];
int vis[5][N];
int type[M], idx[M], col[M];

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>type[i]>>idx[i]>>col[i];
	for(int i=k;i>=1;i--)
	{
		if(vis[type[i]][idx[i]])
			continue;
		vis[type[i]][idx[i]]=1;
		if(type[i]==1)
		{
			for(int j=1;j<=m;j++)
				if(a[idx[i]][j]==0)
					a[idx[i]][j]=col[i];
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j][idx[i]]==0)
					a[j][idx[i]]=col[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}