#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;

int n, m, kk;
char a[N][N];
int cache[N][N], store[N][N];
vector<int> g[N];

int dp(int i, int k)
{
	if(k>kk)
		return 1000000;
	if(i>n)
		return 0;
	if(cache[i][k]!=-1)
		return cache[i][k];
	int &ans=cache[i][k];
	int first=0, last=-1;
	if(g[i].size())
	{
		first=g[i][0];
		last=g[i].back();
	}
	ans=last-first+1+dp(i+1, k);
	int sz=g[i].size();
	for(int j=0;j<=sz;j++)
	{
		ans=min(ans, store[i][j] + dp(i+1, k + (g[i].size() - j)));
	}
	return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
   	cin>>n>>m>>kk;
   	for(int i=1;i<=n;i++)
   	{
   		for(int j=1;j<=m;j++)
   		{
   			cin>>a[i][j];
   			if(a[i][j]=='1')
   			{
   				g[i].push_back(j);
   			}
   			store[i][j]=10000000;
   		}
   	}
   	for(int i=1;i<=n;i++)
   	{
   		for(int j=0;j<=g[i].size();j++)
		{
			if(j==0)
			{
				store[i][j]=0;
			}
			for(int p=0;p+j-1<g[i].size();p++)
			{
				int curfirst=g[i][p];
				int curlast=g[i][p+j-1];
				store[i][j]=min(store[i][j], curlast-curfirst+1);
			}
		}
   	}
   	int ans=dp(1, 0);
   	cout<<ans;
    return 0;
}