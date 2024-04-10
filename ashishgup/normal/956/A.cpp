#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=55;

int n, m;
int vis[N][N];
char a[N][N];
set<int> rows, cols;

void dfs(int index, int type)
{
	if(type==0)
	{
		rows.insert(index);
		for(int j=1;j<=m;j++)
		{
			if(a[index][j]=='#'&&!vis[index][j])
			{	
				vis[index][j]=1;
				dfs(j, 1);
			}
		}
	}
	else
	{
		cols.insert(index);
		for(int i=1;i<=n;i++)
		{
			if(a[i][index]=='#'&&!vis[i][index])
			{	
				vis[i][index]=1;
				dfs(i, 0);
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#'&&!vis[i][j])
			{
				rows.clear();
				cols.clear();
				dfs(i, 0);
				for(auto u:rows)
				{
					for(auto v:cols)
					{
						if(a[u][v]!='#')
						{
							cout<<"No";
							return 0;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#'&&!vis[i][j])
			{
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
	return 0;
}