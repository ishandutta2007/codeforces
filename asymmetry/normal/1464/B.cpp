#include <bits/stdc++.h>

using namespace std;

#define N 101 * 1000

int n;
int s0[N];
int s1[N];
int p0[N];
int p1[N];
long long zp0[N];
long long zp1[N];
long long zs0[N];
long long zs1[N];
char s[N];
long long x, y, odp;

void solve()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	scanf("%lld%lld", &x, &y);
	for(int i=1; i<=n; ++i)
	{
		p0[i]=p0[i-1]+(s[i]=='0');
		p1[i]=p1[i-1]+(s[i]=='1');
		if(s[i]=='0')
		{
			zp0[i]=zp0[i-1]+y*p1[i-1];
			zp1[i]=zp1[i-1]+y*(i-p0[i]);
		}
		else if(s[i]=='1')
		{
			zp0[i]=zp0[i-1]+x*(i-p1[i]);
			zp1[i]=zp1[i-1]+x*p0[i-1];
		}
		else
		{
			zp0[i]=zp0[i-1]+y*p1[i-1];
			zp1[i]=zp1[i-1]+x*p0[i-1];
		}
	}
	for(int i=n; i; --i)
	{
		s0[i]=s0[i+1]+(s[i]=='0');
		s1[i]=s1[i+1]+(s[i]=='1');
		if(s[i]=='0')
		{
			zs0[i]=zs0[i+1]+x*s1[i+1];
			zs1[i]=zs1[i+1]+x*(n-i-s0[i+1]);
		}
		else if(s[i]=='1')
		{
			zs0[i]=zs0[i+1]+y*(n-i-s1[i+1]);
			zs1[i]=zs1[i+1]+y*s0[i+1];
		}
		else
		{
			zs0[i]=zs0[i+1]+x*s1[i+1];
			zs1[i]=zs1[i+1]+y*s0[i+1];
		}
	}
	odp=1e18;
	for(int i=0; i<=n; ++i) // na itym ostatnia zamiana w 0-1
	{
		//~ printf("%d: (%d %d) (%d %d) (%lld %lld) (%lld %lld)\n", i, p0[i], p1[i], s0[i+1], s1[i+1], zp0[i], zp1[i], zs0[i+1], zs1[i+1]);
		odp=min({odp, zp0[i]+zs1[i+1]+x*(i-p1[i])*(n-i-s0[i+1])+y*p1[i]*s0[i+1], zp1[i]+zs0[i+1]+x*p0[i]*s1[i+1]+y*(i-p0[i])*(n-i-s1[i+1])});
	}
	printf("%lld\n", odp);
}

int main()
{
	int q=1;
	//~ scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}