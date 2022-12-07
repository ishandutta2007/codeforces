#include <bits/stdc++.h>

using namespace std;

int zl[300001];
int t[300001];
priority_queue <pair <int, int> > pq1, pq2;

void solve()
{
	int n, k1=0;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) zl[i]=0;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		pq1.push({-t[i], i});
		pq2.push({-t[i], -i});
		++zl[t[i]];
	}
	for(int i=1; i<=n; ++i)
	{
		k1+=(zl[i]>0);
	}
	int l=1, r=n, ak=1, k=n+1;
	while(!pq1.empty())
	{
		int a, b, c;
		a=-pq1.top().first;
		b=pq1.top().second;
		c=-pq2.top().second;
		//~ printf("%d %d %d\n", a, b, c);
		pq1.pop();
		pq2.pop();
		if(a!=ak)
		{
			//~ printf("a\n");
			break;
		}
		if(b==l || c==l)
		{
			//~ printf("b\n");
			--k;
			++ak;
			++l;
			continue;
		}
		if(b==r || c==r)
		{
			//~ printf("c\n");
			--k;
			++ak;
			--r;
			continue;
		}
		//~ printf("d\n");
		--k;
		break;
	}
	while(!pq1.empty())
	{
		pq1.pop();
		pq2.pop();
	}
	if(k1==n) printf("1");
	else printf("0");
	for(int i=2; i<k; ++i)
	{
		printf("0");
	}
	for(int i=max(2, k); i<=n; ++i)
	{
		printf("1");
	}
	printf("\n");
}

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}