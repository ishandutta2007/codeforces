#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, even=0, odd=0, ans=0;
int a[N], pref[2][N], suf[2][N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[0][i]=pref[0][i-1];
		pref[1][i]=pref[1][i-1];
		pref[i%2][i]+=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		suf[0][i]=suf[0][i+1];
		suf[1][i]=suf[1][i+1];
		suf[i%2][i]+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int odd=pref[(i-1)%2][i-1];
		int even=pref[i%2][i]-a[i];
		even+=suf[(i+1)%2][i+1];
		odd+=suf[i%2][i+2];
		ans+=(even==odd);
	}
	cout<<ans;
	return 0;
}