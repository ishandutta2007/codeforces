#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, tot, a, ans=0;
int t[N], l[N];

int32_t main()
{
	IOS;
	cin>>n>>tot>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>l[i];
		l[i]+=t[i];
	}
	t[n+1]=tot;
	for(int i=1;i<=n+1;i++)
		ans+=(t[i]-l[i-1])/a;
	cout<<ans;
	return 0;
}