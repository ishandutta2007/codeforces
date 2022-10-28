#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int a[N][N];
int vis[N], ans[N];
vector<pair<int, int> > v;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	return a[p1.first][p1.second] > a[p2.first][p2.second];
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=2;i<=2*n;i++)
	{
		for(int j=1;j<i;j++)
		{
			cin>>a[i][j];
			a[j][i]=a[i][j];
			v.push_back({i, j});
		}
	}	
	sort(v.begin(), v.end(), comp);
	for(auto &it:v)
	{
		if(vis[it.first] || vis[it.second])
			continue;
		int p=it.first;
		int q=it.second;
		ans[p]=q;
		ans[q]=p;
		vis[p]=1;
		vis[q]=1;
	}
	for(int i=1;i<=2*n;i++)
		cout<<ans[i]<<" ";
	return 0;
}