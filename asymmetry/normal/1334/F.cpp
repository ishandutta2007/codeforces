#include <bits/stdc++.h>

using namespace std;

int comp=524288;
int n, m;
int t[500001];
int p[500001];
int pz[500001];
int ns[500001];
int uz[500001];
int odp[500001];
long long st[1048576];

long long zap(int x)
{
	long long g=0;
	x+=comp;
	while(x)
	{
		g+=st[x];
		x>>=1;
	}
	return g;
}

void ins(int a, int b, long long x)
{
	a+=comp;
	b+=comp;
	while(a<b)
	{
		if(a&1)
		{
			st[a]+=x;
			a>>=1;
			++a;
		}
		else
		{
			a>>=1;
		}
		if(b&1)
		{
			b>>=1;
		}
		else
		{
			st[b]+=x;
			b>>=1;
			--b;
		}
	}
	if(a==b)
	{
		st[a]+=x;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
	}
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &p[i]);
	}
	scanf("%d", &m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", &pz[i]);
		ns[pz[i]]=pz[i-1];
	}
	for(int i=1; i<=n; ++i)
	{
		st[i+comp]=1e18;
	}
	odp[0]=1;
	for(int i=1; i<=n; ++i)
	{
		long long g=zap(t[i]);
		long long h=zap(ns[t[i]]);
		if(odp[ns[t[i]]])
		{
			odp[t[i]]=1;
		}
		if(g+min(0, p[i])>h)
		{
			ins(t[i], t[i], h-g);
		}
		else
		{
			if(p[i]<0)
			{
				ins(t[i], t[i], p[i]);
			}
		}
		ins(0, t[i]-1, p[i]);
		if(p[i]<0)
		{
			ins(t[i]+1, n, p[i]);
		}
	}
	if(odp[pz[m]])
	{
		printf("YES\n%lld", zap(pz[m]));
	}
	else
	{
		printf("NO");
	}
	return 0;
}