#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, q;
int a[N], f[40], reqd[40];

int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<32;j++)
		{
			if(a[i] == (1LL<<j))
				f[j]++;
		}
	}
	while(q--)
	{
		memset(reqd, 0, sizeof(reqd));
		int k;
		cin>>k;
		for(int j=0;j<32;j++)
		{
			if((k>>j) & 1)
				reqd[j]++;
		}
		int ans=0;
		int cur=0;
		for(int j=31;j>=0;j--)
		{
			cur+=reqd[j];
			int have=min(f[j], cur);
			cur-=have;
			ans+=have;
			cur*=2;
		}
		if(cur>0)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}