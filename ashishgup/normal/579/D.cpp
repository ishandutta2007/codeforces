#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, x;
int a[N], pref[N], suf[N];

int32_t main()
{
	IOS;
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] | a[i];
	}
	for(int i=n;i>=1;i--)
		suf[i]|=suf[i+1] | a[i];
	int val=1;
	for(int i=1;i<=k;i++)
		val*=x;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans, pref[i-1] | a[i]*val | suf[i+1]);
	cout<<ans;
	return 0;
}