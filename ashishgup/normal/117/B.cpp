#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a, b, mod;

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
	cin>>a>>b>>mod;
	for(int i=1;i<=min(a, mod);i++)
	{
		int curmod=(i*pow(10, 9, mod))%mod;
		int rem=(mod-curmod)%mod;
		if(rem>b)
		{
			printf("%d %09d", 1, i);
			return 0;
		}
	}	
	cout<<"2";
	return 0;
}