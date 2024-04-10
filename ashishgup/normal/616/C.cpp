#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m, cursz=0, col=0;
int comp[N][N], sz[N], vis[N][N], store[N];
char a[N][N];
int dx[4]={-1, +1, 0, 0};
int dy[4]={0, 0, +1, -1};

void dfs(int i, int j)
{
	if(i<1 || i>n || j<1 || j>m)
		return;
	if(a[i][j]=='*')
		return;
	if(vis[i][j])
		return;
	cursz++;
	vis[i][j]=1;
	comp[i][j]=col;
	for(int k=0;k<4;k++)
		dfs(i+dx[k], j+dy[k]);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				++col;
				cursz=0;
				dfs(i, j);
				store[col]=cursz;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.')
			{
				cout<<".";
				continue;
			}
			set<int> s;
			int ans=1;
			for(int k=0;k<4;k++)
				s.insert(comp[i+dx[k]][j+dy[k]]);
			for(auto &it:s)
				ans+=store[it];
			ans%=10;
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}