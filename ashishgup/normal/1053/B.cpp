#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, ans=0;
int a[N], pref[N], cnt[2];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=__builtin_popcountll(a[i]);
		pref[i]=pref[i-1] + a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i-100>=0)
			cnt[pref[i-100]%2]++;
		ans+=cnt[pref[i]%2];
		int curmax=a[i];
		for(int j=i-1;j>=max(1LL, i-98);j--)
		{
			int cursum=pref[i]-pref[j-1];
			curmax=max(curmax, a[j]);
			if(cursum%2)
				continue;
			if(curmax*2<=cursum)
				ans++;
		}
	}
	cout<<ans;
	return 0;
}