#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n;
int x[N], y[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	int ans=n*(n-1)*(n-2)/6;
	int coll=0;
	for(int i=1;i<=n;i++)
	{
		map<pair<int, int>, int> slope;
		for(int j=i+1;j<=n;j++)
		{
			int ydiff=y[j]-y[i];
			int xdiff=x[j]-x[i];
			if(ydiff==0)
				xdiff=1;
			else if(xdiff==0)
				ydiff=0;
			else
			{
				int gcd1=__gcd(xdiff, ydiff);
				xdiff/=gcd1;
				ydiff/=gcd1;
				if(ydiff<0 && xdiff>0)
				{
					ydiff*=-1;
					xdiff*=-1;
				}
			}
			slope[{xdiff, ydiff}]++;
		}
		for(auto it:slope)
			coll+=((it.second)*(it.second-1)/2);
	}
	cout<<ans-coll;
	return 0;
}