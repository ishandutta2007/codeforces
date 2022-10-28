#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], suf[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	for(int i=n;i>=1;i--)
		suf[i]=max(suf[i+1], a[i]);
	for(int i=1;i<=n;i++)
	{
		int cur=a[i];
		int needed=suf[i+1]+1;
		int ans=max(0LL, needed-cur);
		cout<<ans<<" ";
	}
	return 0;
}