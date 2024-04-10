#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int lsum=0, rsum=0;
	int lsz=0, rsz=n-1;
	int lct=0, rct=0;
	for(int i=n;i>1;i-=m)
	{
		rsum+=a[i];
		rct++;
	}
	int ans=rsum - a[1] * rct;
	for(int i=2;i<=n;i++)
	{
		rsz--;
		if(rsz%m==0)
		{
			rsum-=a[i];
			rct--;
		}
		if(lsz%m==0)
		{
			lct++;
			lsum+=a[i-1];
		}
		lsz++;
		int cur=a[i] * lct - lsum + rsum - a[i] * rct;
		ans=min(ans, cur);
	}
	cout<<ans*2;
	return 0;
}