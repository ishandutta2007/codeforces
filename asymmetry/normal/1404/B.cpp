#include <bits/stdc++.h>

using namespace std;

int n, p1, p2, d1, d2, a, b, c, l, gh;
int odw[100001];
vector <int> v[100001];

void dfs(int x, int dl)
{
	odw[x]=l;
	if(a<dl)
	{
		a=dl;
		b=x;
	}
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs(i, dl+1);
		}
	}
}

void dfs2(int x, int dl)
{
	odw[x]=l;
	if(x==p2)
	{
		a=dl;
		return;
	}
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs2(i, dl+1);
		}
	}
}

void solve()
{
	scanf("%d%d%d%d%d", &n, &p1, &p2, &d1, &d2);
	for(int i=1; i<=n; ++i)
	{
		v[i].clear();
	}
	for(int i=1; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	if(d1*2>=d2)
	{
		printf("Alice\n");
		return;
	}
	++l;
	dfs2(p1, 0);
	if(a<=d1)
	{
		printf("Alice\n");
		return;
	}
	++l;
	a=-1;
	dfs(1, 0);
	c=b;
	++l;
	a=-1;
	dfs(c, 0);
	if(a>=d1*2+1)
	{
		printf("Bob\n");
		return;
	}
	printf("Alice\n");
}

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		solve();
	}
	return 0;
}