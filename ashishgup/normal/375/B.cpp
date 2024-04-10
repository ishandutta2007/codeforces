#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n, m;
int len[N];
char a[N][N];
vector<int> v[N];

int32_t main()
{
    IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='1')
				len[j]=len[j-1]+1;
			else
				len[j]=0;
			v[j].push_back(len[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		sort(v[i].rbegin(), v[i].rend());
		for(int j=0;j<v[i].size();j++)
		{
			ans=max(ans, (j+1)*v[i][j]);
		}
	}
	cout<<ans;
    return 0;
}