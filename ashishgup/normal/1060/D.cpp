#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int l[N], r[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ans++;
		cin>>l[i]>>r[i];
	}
	sort(l+1, l+n+1);
	sort(r+1, r+n+1);
	for(int i=1;i<=n;i++)
		ans+=max(l[i], r[i]);
	cout<<ans;
	return 0;
}