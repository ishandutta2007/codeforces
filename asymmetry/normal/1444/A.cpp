#include <bits/stdc++.h>

using namespace std;

long long p, q;

long long pot(long long a, long long b)
{
	long long k=1;
	while(b)
	{
		if(b&1)
		{
			k*=a;
		}
		a*=a;
		b>>=1;
	}
	return k;
}

void solve()
{
	scanf("%lld%lld", &p, &q);
	long long pp=p;
	if(p%q)
	{
		printf("%lld\n", p);
		return;
	}
	else
	{
		long long odp=1;
		vector <pair <int, int> > roz1, roz2;
		for(int i=2; i*i<=q; ++i)
		{
			if(!(q%i))
			{
				roz1.push_back({i, 1});
				q/=i;
				roz2.push_back({i, 1});
				p/=i;
				while(!(q%i))
				{
					q/=i;
					++roz1.back().second;
				}
				while(!(p%i))
				{
					p/=i;
					++roz2.back().second;
				}
			}
		}
		if(q>1)
		{
			roz1.push_back({q, 1});
			roz2.push_back({q, 1});
			p/=q;
			while(!(p%q))
			{
				++roz2.back().second;
				p/=q;
			}
		}
		int x=0;
		for(unsigned int i=0; i<roz1.size(); ++i)
		{
			while(roz2[x].first!=roz1[i].first)
			{
				++x;
			}
			odp=max(odp, pp/pot(roz1[i].first, roz2[x].second-roz1[i].second+1));
		}
		printf("%lld\n", odp);
	}
}

int main()
{
	int gh;
	scanf("%d", &gh);
	while(gh--)
	{
		solve();
	}
	return 0;
}