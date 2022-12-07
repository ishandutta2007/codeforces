#include <bits/stdc++.h>

using namespace std;

int n, odp, l, p, s;
int a[10];
int t[100001];
int wys[100001];
pair <int, int> sr[600001];

int main()
{
	for(int i=1; i<=6; ++i)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		for(int j=1; j<=6; ++j)
		{
			if(a[j]<t[i])
			{
				++l;
				sr[l]={t[i]-a[j], i};
			}
		}
	}
	sort(sr+1, sr+1+l);
	p=0;
	s=0;
	odp=1e9+7;
	for(int i=1; i<=l; ++i)
	{
		while(p<l && s<n)
		{
			++p;
			if(!wys[sr[p].second])
			{
				++s;
			}
			++wys[sr[p].second];
		}
		if(s==n)
		{
			odp=min(odp, sr[p].first-sr[i].first);
		}
		--wys[sr[i].second];
		if(!wys[sr[i].second])
		{
			--s;
		}
	}
	printf("%d\n", odp);
	return 0;
}