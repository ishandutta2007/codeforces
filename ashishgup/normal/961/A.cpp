#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int f[N];

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		f[k]++;
	}
	int ans=m;
	for(int i=1;i<=n;i++)
		ans=min(ans, f[i]);
	cout<<ans;
	return 0;
}