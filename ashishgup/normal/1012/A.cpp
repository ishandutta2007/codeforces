#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=2*n;i++)
		cin>>a[i];
	sort(a+1, a+2*n+1);
	int ans=(a[n]-a[1])*(a[2*n]-a[n+1]);
	for(int i=2;i<=n;i++)
	{
		int cur=a[n+i-1]-a[i];
		int other=a[2*n]-a[1];
		ans=min(ans, cur*other);
	}
	cout<<ans;
	return 0;
}