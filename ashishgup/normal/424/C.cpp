#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans^=a[i];
		pref[i]=pref[i-1]^i;
	}
	for(int i=1;i<=n;i++)
	{
		int parity=n/i;
		int remainder=n%i;
		if(parity&1)
			ans^=(pref[i-1]^pref[remainder]);
		else
			ans^=(pref[remainder]);
	}
	cout<<ans;
	return 0;
}