#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define X first.first
#define Y first.second
#define I second

const int MAXN = 2000;

typedef pair < pair <int, int>, int > mpair;

int last[MAXN], dest[MAXN << 1], next[MAXN << 1];
int c[MAXN];
int n, m;
vector < mpair > a;
mpair o;
int ans[MAXN];

void dfs(int x, int p)
{
	c[x] = 1;
	for (int i = last[x]; i; i = next[i])
	{
		int y = dest[i];
		if (p == y) continue;
		dfs(y, x);
		c[x] += c[y];
	}
}


bool opr_sort(const mpair &a, const mpair &b)
{
	return (a.X - o.X) * (long long)(b.Y - o.Y) - (a.Y - o.Y) * (long long)(b.X - o.X) > 0;
}

int rec(int x, int p, vector < pair < pair < int, int >, int > > &a)
{
	int t = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i].Y > a[t].Y)
			t = i;
	swap(a[t], a[0]);
	t = a[0].I;
	o = a[0];
	sort(a.begin() + 1, a.end(), opr_sort);

	int l = 1;
	for (int i = last[x]; i; i = next[i])
	{
		int y = dest[i];
		if (y == p) continue;
		vector < pair < pair < int, int >, int > > s;
		s.resize(c[y]);
		for (int j = 0; j < c[y]; j++, l++)
			s[j] = a[l];
		ans[rec(y, x, s)] = y;
	}
	return t;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		dest[i] = y;
		next[i] = last[x];
		last[x] = i;

		dest[i + n] = x;
		next[i + n] = last[y];
		last[y] = i + n;
	}
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].X, &a[i].Y);
		a[i].I = i;
	}
	dfs(1, 0);

	sort(a.begin(), a.end());

    ans[rec(1, 0, a)] = 1;
    for (int i = 0; i < n; i++)
    {
    	if (i) printf(" ");
    	printf("%d", ans[i]);
    }
    printf("\n");
	return 0;	
}