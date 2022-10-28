#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

int x, k;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>x>>k;
	if(x==0)
	{
		cout<<0;
		return 0;
	}
	k%=(MOD-1);
	int t=pow(2LL, k, MOD);
	x%=MOD;
	int ans=2*t*x - (t-1);
	ans%=MOD;
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}