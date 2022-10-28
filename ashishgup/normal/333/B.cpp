#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, m;
set<int> row, col;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=2;i<=n-1;i++)
	{
		row.insert(i);
		col.insert(i);
	}
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		if(row.find(x)!=row.end())
			row.erase(x);
		if(col.find(y)!=col.end())
			col.erase(y);
	}
	int ans=row.size() + col.size();
	if(n%2 && row.find((n+1)/2)!=row.end() && col.find((n+1)/2)!=col.end())
		ans--;
	cout<<ans;
	return 0;
}