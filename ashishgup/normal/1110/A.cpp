#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, b, k, val=0;
int a[N];

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
	cin>>b>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		val+=(a[i]*pow(b, k-i, 2))%2;
		val%=2;
	}
	if(!val)
		cout<<"even";
	else
		cout<<"odd";
	return 0;
}