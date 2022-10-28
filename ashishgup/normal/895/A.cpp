#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=500;

int n, sum=0, ans=360;
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
	for(int l=1;l<=n;l++)
	{
		int cur=0;
		for(int r=l;r<=n;r++)
		{
			cur+=a[r];
			ans=min(ans, abs(sum-2*cur));
		}
	}
	cout<<ans;
	return 0;
}