#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, m;
int a[N], last[N];
map<int, int> index;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		index[a[i]]=i;
		last[i]=n;
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		int p=index[u];
		int q=index[v];
		if(p>q)
			swap(p, q);
		last[p]=min(last[p], q-1);
	}
	int r=n;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		r=min(r, last[i]);
		if(r>=i)
			ans+=(r-i+1);
	}
	cout<<ans;
 	return 0;
}