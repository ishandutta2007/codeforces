#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n;
double stx[N], sty[N];

bool check(double y)
{
	double lx=-2e18;
	double rx=2e18;
	for(int i=1;i<=n;i++)
	{
		double curx=(y*y - ((y-sty[i])*(y-sty[i])));
		if(curx<0)
			return 0;
		curx=sqrtl(curx);
		lx=max(lx, -curx+stx[i]);
		rx=min(rx, curx+stx[i]);
		if(lx-rx>0)
			return 0;
	}
	return 1;
}

double binary_search(double lo, double hi)
{
	while((double)clock()/CLOCKS_PER_SEC<1.80)
	{
		double mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid;
	}
	return lo;
}  

int32_t main()
{
	IOS;
	cin>>n;
	int posy=0, negy=0;
	for(int i=1;i<=n;i++)
	{
		cin>>stx[i]>>sty[i];
		posy|=(sty[i]>0);
		negy|=(sty[i]<0);
	}
	if(posy && negy)
	{
		cout<<"-1";
		return 0;
	}
	double storey=0;
	for(int i=1;i<=n;i++)
	{
		if(sty[i]<0)
			sty[i]*=-1;
		storey=max(storey, (double)sty[i]);
	}
	double r=binary_search(storey/2, 1e18);
	cout<<fixed<<setprecision(12)<<r<<endl;
	return 0;
}