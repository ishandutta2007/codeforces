#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;
const int MOD=1e9+7;

int n, m, k;

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
	cin>>n>>m>>k;	
	if(k==1 || k>n)
		cout<<pow(m, n, MOD);
	else if(k==n)
		cout<<pow(m, (n+1)/2, MOD);
	else if(k%2==0)
		cout<<m;
	else
		cout<<pow(m, 2LL, MOD);
	return 0;
}