#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5+5;
const int MOD = 998244353;

int n, m, cnt=0, ans=0;
char a[N], b[N];

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
	cin>>n>>m;
	for(int i=2e5-n+1;i<=2e5;i++)
		cin>>a[i];
	for(int i=2e5-m+1;i<=2e5;i++)
	{
		cin>>b[i];
		cnt+=(b[i]=='1');
	}
	for(int i=2e5;i>=1;i--)
	{
		if(a[i]=='1')
			ans+=(cnt*pow(2LL, (2e5-i), MOD));
		cnt-=(b[i]=='1');
		ans%=MOD;
	}	
	cout<<ans;
	return 0;
}