#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, sum=0, min1=2e4, max1=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	min1=sum/n;
	max1=(sum+n-1)/n;
	int less=0, more=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<min1)
			less+=min1-a[i];
		else if(a[i]>max1)
			more+=a[i]-max1;
	}
	int ans=max(less, more);
	cout<<ans; 
	return 0;
}