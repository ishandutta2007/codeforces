#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int n, q;
char a[N];
int pref[N];

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
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + (a[i]=='1');
	}	
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		int x=pref[r] - pref[l-1];
		int y=(r-l+1 - x);
		int ans=pow(2LL, x, MOD) - 1;
		ans+=(ans*(pow(2LL, y, MOD) - 1))%MOD;
		ans%=MOD;
		cout<<ans<<endl;
	}
	return 0;
}