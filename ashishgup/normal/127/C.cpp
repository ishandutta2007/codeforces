#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int lim=1e18;

int t1, t2, x1, x2, t, y2;
int ans1=-1, ans2=-1;

int check(int y1)
{
	int lhs=t1*y1  + t2*y2;
	int rhs=t*(y1+y2);
	return lhs>=rhs;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid))
		{
			lo=mid;
		}
		else
		{
			hi=mid-1;
		}
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>t1>>t2>>x1>>x2>>t;
	for(y2=0;y2<=x2;y2++)
	{
		int y1=binsearch(0, x1);
		if(check(y1))
		{	
			if(ans1==-1)
			{
				ans1=y1;
				ans2=y2;
				continue;
			}
			int origt=(t1*ans1 + t2*ans2)*(y1+y2);
			int curt=(t1*y1 + t2*y2)*(ans1+ans2);
			if(curt<origt)
			{
				ans1=y1;
				ans2=y2;
			}
			else if(origt==curt && y1+y2>ans1+ans2)
			{
				ans1=y1;
				ans2=y2;
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}