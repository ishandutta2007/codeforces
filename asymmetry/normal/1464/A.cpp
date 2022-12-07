#include <bits/stdc++.h>

using namespace std;

int rep[100001];
int roz[100001];

int fin(int x)
{
	if(x!=rep[x]) rep[x]=fin(rep[x]);
	return rep[x];
}

bool uni(int a, int b)
{
	a=fin(a);
	b=fin(b);
	if(a==b) return false;
	if(roz[a]<roz[b]) swap(a, b);
	roz[a]+=roz[b];
	rep[b]=a;
	return true;
}

void solve()
{
	int n, m, odp=0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		rep[i]=i;
		roz[i]=1;
	}
	int a, b;
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		if(a!=b)
		{
			++odp;
			odp+=(!uni(a, b));
		}
	}
	printf("%d\n", odp);
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