#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=15;

int n, m, x[N], y[N];
set<int> has;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
	{
		cin>>y[i];
		has.insert(y[i]);
	}
	for(int i=1;i<=n;i++)
		if(has.find(x[i])!=has.end())
			cout<<x[i]<<" ";
	return 0;
}