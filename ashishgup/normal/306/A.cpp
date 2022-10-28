#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n, m, i;
	cin>>n>>m;
	for(i=1;i<=n%m;i++)
		cout<<(n/m + 1)<<" ";
	while(i<=m)
	{
		cout<<(n/m)<<" ";
		i++;
	}
	return 0;
}