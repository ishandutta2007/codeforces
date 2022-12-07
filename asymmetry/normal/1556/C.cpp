//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 2010

int n;
long long t[N];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%lld", &t[i]);
	}
	long long odp=0;
	for(int i=1; i<=n; i+=2)
	{
		long long akt=0, mn=1e9;
		for(int j=i; j<=n; ++j)
		{
			if(j&1)
			{
				akt+=t[j];
			}
			else
			{
				odp+=max(0ll, min(t[j], t[j]+mn-akt)-max(0ll, t[j]-akt)+1);
				akt-=t[j];
				if(akt<0) break;
			}
			mn=min(mn, akt);
		}
	}
	printf("%lld\n", odp-n/2);
	return 0;
}