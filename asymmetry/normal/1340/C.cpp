#include <bits/stdc++.h>

using namespace std;

int n, m, g, r, a, b, l, p, faz, siz1, siz2;
int t[10001];
bitset <1001> bt[10001];
pair <int, int> v[2][11000001];
long long odp=1e18;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", &t[i]);
	}
	sort(t+1, t+1+m);
	scanf("%d%d", &g, &r);
	l=0;
	p=1;
	siz1=1;
	siz2=0;
	v[0][1]={1, 0};
	while(siz1)
	{
		for(int i=1; i<=siz1; ++i)
		{
			a=v[l][i].first;
			b=v[l][i].second;
			bt[a][b]=1;
			if(a==m)
			{
				if(!b)
				{
					odp=min(odp, (long long)b+(long long)faz*(r+g)-r);
				}
				else
				{
					odp=min(odp, (long long)b+(long long)faz*(r+g));
				}
			}
			if(a!=1)
			{
				if(b+t[a]-t[a-1]<=g)
				{
					if(b+t[a]-t[a-1]==g)
					{
						if(!bt[a-1][0])
						{
							bt[a-1][0]=1;
							++siz2;
							v[p][siz2]={a-1, 0};
						}
					}
					else
					{
						if(!bt[a-1][b+t[a]-t[a-1]])
						{
							bt[a-1][b+t[a]-t[a-1]]=1;
							++siz1;
							v[l][siz1]={a-1, b+t[a]-t[a-1]};
						}
					}
				}
			}
			if(a!=m)
			{
				if(b+t[a+1]-t[a]<=g)
				{
					if(b+t[a+1]-t[a]==g)
					{
						if(!bt[a+1][0])
						{
							++siz2;
							bt[a+1][0]=1;
							v[p][siz2]={a+1, 0};
						}
					}
					else
					{
						if(!bt[a+1][b+t[a+1]-t[a]])
						{
							++siz1;
							bt[a+1][b+t[a+1]-t[a]]=1;
							v[l][siz1]={a+1, b+t[a+1]-t[a]};
						}
					}
				}
			}
		}
		++faz;
		siz1=0;
		swap(l, p);
		swap(siz1, siz2);
		if(odp!=1e18)
		{
			printf("%lld\n", odp);
			return 0;
		}
	}
	if(odp==1e18)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n", odp);
	}
	return 0;
}