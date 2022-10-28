#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int ans=0;
	while(n>0)
	{
		ans++;
		n/=2;
	}
	cout<<ans;
	return 0;
}