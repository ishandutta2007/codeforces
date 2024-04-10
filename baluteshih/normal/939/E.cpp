#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <iomanip>
#include <utility>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second

ll num[500005],sum[500005];

int main()
{
	ll n,k,x,l,r,top=-1,m;
	double ans=0;
	cin >> n;
	while(n--)
	{
		cin >> k;
		if(k==1)
		{
			cin >> x;
			num[++top]=x;
			if(top) sum[top]=x+sum[top-1];
			else
			{
				sum[0]=x;
				continue;
			}
			for(l=0,r=top-1;l<r;)
			{
				m=(l+r)/2+1;
				if((double)(x+sum[m-1])/(double)(m+1)<(double)(num[m])) r=m-1;
				else l=m;
			}
			if(ans<(double)(x)-(double)(x+sum[l])/(double)(l+2)) ans=(double)(x)-(double)(x+sum[l])/(double)(l+2);
		}
		else
			cout << fixed << setprecision(10) << ans << "\n";
	}
}