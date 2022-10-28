#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=55;

int n;
int deg[N];
int win[N][N];
vector<int> missing;

int32_t main()
{
	IOS;
	cin>>n;
	int m=n*(n-1)/2 - 1;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		win[u][v]=1;
		deg[u]++, deg[v]++;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				win[i][j]|=(win[i][k] && win[k][j]);
	for(int i=1;i<=n;i++)
		if(deg[i]<n-1)
			missing.push_back(i);
	if(!win[missing[0]][missing[1]])
		swap(missing[0], missing[1]);
	cout<<missing[0]<<" "<<missing[1];
	return 0;
}