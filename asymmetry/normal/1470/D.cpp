#include <bits/stdc++.h>

using namespace std;

#define N 301 * 1000

int n, m, a, b, sum, l;
int odw[N];
int pos[N];
vector <int> v[N];
vector <int> ans;

void zli(int x)
{
	odw[x]=l;
	++sum;
	for(int i:v[x])
	{
		if(odw[i]<l) zli(i);
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		pos[i]=0;
		v[i].clear();
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	sum=0;
	++l;
	zli(1);
	if(sum<n)
	{
		printf("NO\n");
		return;
	}
	queue <int> que;
	que.push(1);
	++l;
	ans.clear();
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		if(odw[x]==l) continue;
		odw[x]=l;
		ans.push_back(x);
		for(int i:v[x])
		{
			if(odw[i]==l) continue;
			odw[i]=l;
			for(int j:v[i])
			{
				if(odw[j]<l) que.push(j);
			}
		}
	}
	printf("YES\n%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for(int i:ans) printf("%d ", i);
	printf("\n");
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