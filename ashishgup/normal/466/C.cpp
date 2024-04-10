#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, sum=0, lsum, rsum, ans=0, ct=0;
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
	int ans=0;
	if(sum%3==0)
	{
		lsum=sum/3;
		rsum=2*lsum;
		sum=0;
		for(int i=1;i<n;i++)
		{
			sum+=a[i];
			if(sum==rsum)
				ans+=ct;
			if(sum==lsum)
				ct++;
		}
	}
	cout<<ans;
}