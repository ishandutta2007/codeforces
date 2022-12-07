//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 101 * 1000

int n, a;
vector <int> zl[2];

void solve()
{
	long long odp=0;
	zl[0].clear();
	zl[1].clear();
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		zl[a&1].push_back(i);
	}
	if(zl[0].size()<zl[1].size()) swap(zl[0], zl[1]);
	if(zl[0].size()-zl[1].size()>1)
	{
		printf("-1\n");
		return;
	}
	if(zl[0].size()-zl[1].size()==1)
	{
		a=1;
		for(int i:zl[0])
		{
			odp+=abs(a-i);
			a+=2;
		}
		a=2;
		for(int i:zl[1])
		{
			odp+=abs(a-i);
			a+=2;
		}
		printf("%lld\n", odp/2);
		return;
	}
	odp=1e18;
	long long wyn=0;
	a=1;
	for(int i:zl[0])
	{
		wyn+=abs(a-i);
		a+=2;
	}
	a=2;
	for(int i:zl[1])
	{
		wyn+=abs(a-i);
		a+=2;
	}
	odp=wyn;
	wyn=0;
	a=1;
	for(int i:zl[1])
	{
		wyn+=abs(a-i);
		a+=2;
	}
	a=2;
	for(int i:zl[0])
	{
		wyn+=abs(a-i);
		a+=2;
	}
	odp=min(odp, wyn);
	printf("%lld\n", odp/2);
}

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie(NULL);
	int q=1;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}