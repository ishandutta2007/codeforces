#include <bits/stdc++.h>
 
using namespace std;

long long n, l, wyn, a;
long long odw[200001];
long long roz[200001];
long long zl[200001];
long long odp1[200001];
long long odp2[200001];
long long wys[200001];
vector <long long> od;
 
long long pot(long long a, long long b)
{
	long long k=1;
	while(b)
	{
		if(b&1)
		{
			k*=a;
		}
		b>>=1;
		a*=a;
	}
	return k;
}
 
int main()
{
	for(long long i=2; i<=200000; ++i)
	{
		odp1[i]=1e9;
		odp2[i]=1e9;
		if(!roz[i])
		{
			for(long long j=i; j<=200000; j+=i)
			{
				roz[j]=i;
			}
		}
	}
	scanf("%lld", &n);
	for(long long i=1; i<=n; ++i)
	{
		scanf("%lld", &a);
		od.clear();
		++l;
		while(a>1)
		{
			if(odw[roz[a]]<l)
			{
				od.push_back(roz[a]);
				odw[roz[a]]=l;
			}
			++zl[roz[a]];
			a/=roz[a];
		}
		for(long long j:od)
		{
			++wys[j];
			if(zl[j]<=odp1[j])
			{
				odp2[j]=odp1[j];
				odp1[j]=zl[j];
			}
			else
			{
				odp2[j]=min(odp2[j], zl[j]);
			}
			zl[j]=0;
		}
	}
	wyn=1;
	for(long long i=1; i<=200000; ++i)
	{
		if(wys[i]==n)
		{
			wyn*=pot(i, odp2[i]);
		}
		else if(wys[i]==n-1)
		{
			wyn*=pot(i, odp1[i]);
		}
	}
	printf("%lld\n", wyn);
	return 0;
}