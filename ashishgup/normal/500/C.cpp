#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, m, ans=0;
int w[N], b[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		set<int> vis;
		for(int j=i-1;j>=1;j--)
		{
			if(b[i]==b[j])
				break;
			if(vis.find(b[j])!=vis.end())
				continue;
			vis.insert(b[j]);
			ans+=w[b[j]];
		}
	}
	cout<<ans;
	return 0;
}