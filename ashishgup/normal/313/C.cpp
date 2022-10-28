#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e6+5;

int n, cur=1, ans=0;
int a[N], pref[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	for(int i=1;i<=n;i++)
		pref[i]=pref[i-1]+a[i];
	while(cur<=n)
	{
		ans+=pref[cur];
		cur*=4;
	}
	cout<<ans;
	return 0;
}