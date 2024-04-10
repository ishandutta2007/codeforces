#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, x, ans=0;

int32_t main()
{
	IOS;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		if(x%i==0 && x/i<=n)
			ans++;
	}
	cout<<ans;
	return 0;
}