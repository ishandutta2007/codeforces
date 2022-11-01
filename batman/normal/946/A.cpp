#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)

ll n,ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x;cin>>x;
		ans+=abs(x);
	}
	cout<<ans<<"\n";
	return 0;
}