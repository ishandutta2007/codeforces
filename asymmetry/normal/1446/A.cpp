#include <bits/stdc++.h>

using namespace std;

int n;
long long w;
pair <int, int> t[200001];

void solve()
{
	scanf("%d%lld", &n, &w);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i].first);
		t[i].second=i;
	}
	sort(t+1, t+1+n);
	reverse(t+1, t+1+n);
	vector <int> odp;
	long long s=0;
	for(int i=1; i<=n; ++i)
	{
		if(s+t[i].first<=w)
		{
			s+=t[i].first;
			odp.push_back(t[i].second);
		}
	}
	if(s<(w+1)/2)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", (int)odp.size());
		for(int i:odp)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
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