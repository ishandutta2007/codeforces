#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + a[i];
	}
	for(int i=1;i<=n;i++)	
		if(pref[i-1]<=pref[n]-pref[i])
			ans=i;
	cout<<ans<<" "<<n-ans;
	return 0;
}