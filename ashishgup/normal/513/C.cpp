#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=10;

int n;
double ans=0;
int L[N], R[N];

double get(double l, double r, double L, double R)
{
	l=max(l, L);
	r=min(r, R);
	if(l>r)
		return 0;
	return (r-l+1)/(R-L+1);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>L[i]>>R[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			for(int val=L[i];val<=R[i];val++)
			{
				double prob=1.0/(R[i]-L[i]+1);
				prob*=get(max(L[j], val+(j>i)), R[j], L[j], R[j]);
				for(int k=1;k<=n;k++)
				{
					if(k==i || k==j)
						continue;
					prob*=get(L[k], min(R[k], val-(k<i)), L[k], R[k]);
				}
				ans+=prob*val;
			}
		}
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}