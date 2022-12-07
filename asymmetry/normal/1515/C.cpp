//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

int n, m, x, a;
pair <int, int> t[1000000];
int odp[1000000];
int g[1000000];
priority_queue <pair <int, int> > pq;

void solve()
{
	scanf("%d%d%d", &n, &m, &x);
	for(int i=1; i<=m; ++i) pq.push({0, i});
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i].first);
		t[i].second=i;
	}
	sort(t+1, t+1+n);
	reverse(t+1, t+1+n);
	for(int i=1; i<=n; ++i)
	{
		pair <int, int> w=pq.top();
		pq.pop();
		odp[t[i].second]=w.second;
		pq.push({w.first-t[i].first, w.second});
	}
	for(int i=1; i<=m; ++i)
	{
		t[i].first=-pq.top().first;
		pq.pop();
	}
	if(t[m].first-t[1].first>x)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%d ", odp[i]);
	printf("\n");
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