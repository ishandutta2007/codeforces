#include <bits/stdc++.h>

using namespace std;

#define N 301 * 1000

int t[N];
int c[N];

void solve()
{
	int n, m, a;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i) t[i]=0;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
	}
	for(int i=1; i<=m; ++i) scanf("%d", &c[i]);
	sort(t+1, t+1+n);
	a=1;
	long long odp=0;
	for(int i=n; i; --i)
	{
		if(a>t[i])
		{
			odp+=c[t[i]];
		}
		else
		{
			odp+=c[a];
			++a;
		}
	}
	printf("%lld\n", odp);
}

int main()
{
	int q=1;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}