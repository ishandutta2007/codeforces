#include <bits/stdc++.h>

using namespace std;

int gh, n;
char s[211][211];
vector <pair <int, int> > odp, ab, ba, xd, dx;

void solve()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s[i]+1);
	}
	odp.clear();
	ab.clear();
	ba.clear();
	xd.clear();
	dx.clear();
	if(s[1][2]=='0')
	{
		ab.push_back({1, 2});
	}
	else
	{
		xd.push_back({1, 2});
	}
	if(s[2][1]=='0')
	{
		ab.push_back({2, 1});
	}
	else
	{
		xd.push_back({2, 1});
	}
	if(s[n][n-1]=='0')
	{
		ba.push_back({n, n-1});
	}
	else
	{
		dx.push_back({n, n-1});
	}
	if(s[n-1][n]=='0')
	{
		ba.push_back({n-1, n});
	}
	else
	{
		dx.push_back({n-1, n});
	}
	if(ab.size()==2)
	{
		printf("%d\n", ba.size());
		for(auto i:ba)
		{
			printf("%d %d\n", i.first, i.second);
		}
		return;
	}
	if(xd.size()==2)
	{
		printf("%d\n", dx.size());
		for(auto i:dx)
		{
			printf("%d %d\n", i.first, i.second);
		}
		return;
	}
	if(ba.size()==2)
	{
		printf("%d\n", ab.size());
		for(auto i:ab)
		{
			printf("%d %d\n", i.first, i.second);
		}
		return;
	}
	if(dx.size()==2)
	{
		printf("%d\n", xd.size());
		for(auto i:xd)
		{
			printf("%d %d\n", i.first, i.second);
		}
		return;
	}
	odp.clear();
	for(auto i:xd)
	{
		odp.push_back(i);
	}
	for(auto i:ba)
	{
		odp.push_back(i);
	}
	printf("%d\n", odp.size());
	for(auto i:odp)
	{
		printf("%d %d\n", i.first, i.second);
	}
}

int main()
{
	scanf("%d", &gh);
	while(gh--)
	{
		solve();
	}
	return 0;
}