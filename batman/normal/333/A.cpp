#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)


ll n;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	ll x=3;
	while(1)
	{
		if(n%x)return cout<<(n+x-1)/x,0;
		x*=3;
	}
	return 0;
}