#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n;
int a[N], f[N], ans[N];

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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i=1e5;i>=1;i--)
	{
		int cur=f[i];
		for(int j=2*i;j<=1e5;j+=i)
			cur+=f[j];
		ans[i]=pow(2LL, cur, MOD)-1;
		for(int j=2*i;j<=1e5;j+=i)
			ans[i]=(ans[i]-ans[j]+MOD)%MOD;
	}
	cout<<ans[1];
	return 0;
}