#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, l, r, ql, qr, ans=LLONG_MAX;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n>>l>>r>>ql>>qr;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=a[i]+pref[i-1];
	}	
	for(int i=0;i<=n;i++)
	{
		int left=i;
		int right=n-i;
		int sumleft=pref[left];
		int sumright=pref[n]-pref[n-right];
		int curans=sumleft*l+sumright*r;
		int diff=abs(right-left)-1;
		if(left<right)
			curans+=diff*qr;
		else if(left>right)
			curans+=diff*ql;
		ans=min(ans, curans);
	}
	cout<<ans;
	return 0;
}