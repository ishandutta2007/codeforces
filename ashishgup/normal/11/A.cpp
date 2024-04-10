#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, d, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		int diff=(a[i-1]-a[i]+1);
		diff=(diff+d-1)/d;
		diff=max(0LL, diff);
		ans+=diff;
		a[i]+=diff*d;
	}	
	cout<<ans;
	return 0;
}