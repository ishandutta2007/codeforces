#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}	
	b[n]=a[n]+1;
	for(int i=n-1;i>=1;i--)
	{
		b[i]=max(a[i]+1, b[i+1]-1);
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=max(b[i], b[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=max(0LL, (b[i] - 1 - a[i]));
	}
	cout<<ans;
	return 0;
}