#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cur=a[i];
		int idx=i;
		while(upper_bound(a+1, a+n+1, cur*2) - a - 1 != idx)
		{
			idx=upper_bound(a+1, a+n+1, cur*2) - a - 1;
			if(idx==n)
				break;
			cur=a[idx];
		}
		ans=max(ans, idx-i+1);
		i=idx;
	}
	cout<<ans;
	return 0;
}