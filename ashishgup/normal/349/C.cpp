#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, sum=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		ans=max(ans, a[i]);
	}
	ans=max(ans, (sum+n-2)/(n-1));
	cout<<ans;
	return 0;
}