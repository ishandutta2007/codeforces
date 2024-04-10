#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int n, m;
int a[N][N], b[N][N];
vector<int> x[2*N], y[2*N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			x[i+j].push_back(a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
			y[i+j].push_back(b[i][j]);
		}
	}
	for(int i=1;i<=n+m;i++)
	{
		sort(x[i].begin(), x[i].end());
		sort(y[i].begin(), y[i].end());
		if(x[i] != y[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}