#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
#define iop(i,a,n) for(int i=a;i<n;i++)
using namespace std;

ll pow(ll a,ll n,ll MOD)
{
	ll re=1;
	for(;n;n/=2,a=a*a%MOD)
		if(n&1) re=re*a%MOD;
	return re;
}

ll num[1000003];

int main()
{
	ll a,b,p,x,inv,y,ans=0,i,l,r,m,cyc,inc;
	cin >> a >> b >> p >> x;
	for(i=1,num[0]=1,cyc=1;i<p;i++,cyc++)
	{
		num[i]=num[i-1]*a%p;
		if(num[i]==1) break;
	}
	//cout << cyc << "\n";
	inc=pow(cyc,p-2,p);
	for(i=1;i<=cyc;i++)
	{
		inv=num[(cyc-i)%cyc];
		y=(b*inv-i+p)*inc%p; // i+cyc*(y+pa)<=x,a>=0
		//cout << num[i]*(i+cyc*y)%p << " " << b << "\n";
		if(i+cyc*y<=x)
		{
			for(l=0,r=(((x-i)/cyc+1)-y)/p+1;l<r;)
			{
				m=(l+r)/2; 
				if(i+cyc*(y+p*m)>x) r=m;
				else l=m+1;
			}
			ans+=l;
			//cout << i << " " << y << " " << l << "\n";
		}
	}
	cout << ans << "\n";
}