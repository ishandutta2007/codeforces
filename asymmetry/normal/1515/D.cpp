//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 201 * 1000

int n, l, r, a, odp, lf, rg;
int p[N];
int q[N];

void solve()
{
	scanf("%d%d%d", &n, &l, &r);
	for(int i=1; i<=n; ++i) p[i]=q[i]=0;
	for(int i=1; i<=l; ++i)
	{
		scanf("%d", &a);
		++p[a];
	}
	for(int i=1; i<=r; ++i)
	{
		scanf("%d", &a);
		++q[a];
	}
	odp=0;
	lf=rg=0;
	for(int i=1; i<=n; ++i)
	{
		if(p[i]>q[i])
		{
			lf+=p[i]-q[i];
			p[i]-=q[i];
			q[i]=0;
		}
		else
		{
			rg+=q[i]-p[i];
			q[i]-=p[i];
			p[i]=0;
		}
	}
	if(lf<rg)
	{
		swap(lf, rg);
		for(int i=1; i<=n; ++i) swap(p[i], q[i]);
	}
	for(int i=1; i<=n; ++i)
	{
		if(lf-rg>=p[i]/2*2)
		{
			lf-=p[i]/2*2;
			odp+=p[i]/2;
			p[i]&=1;
		}
		else
		{
			printf("%d\n", odp+(lf-rg)/2+rg);
			return;
		}
	}
	printf("%d\n", odp+lf);
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