#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, seive[1000010], am[1000010];
ll rangetree[1500000];
int rangetree2[1500000];
int init[1000010];
void maketree(int curr = 1, int cstart = 0, int cend = 300000)
{
	if (cstart == cend)
	{
		rangetree[curr] = init[cstart];
		if (!rangetree[curr]) rangetree[curr] = 1;
		if (rangetree[curr] != 1 && rangetree[curr] != 2) rangetree2[curr]++;
		return;
	}
	int mid = (cstart+cend)/2;
	maketree(2*curr, cstart, mid);
	maketree(2*curr+1, mid+1, cend);
	rangetree[curr] = rangetree[2*curr] + rangetree[2*curr+1];
	rangetree2[curr] = rangetree2[2*curr] + rangetree2[2*curr+1];
}
void update(int s, int e, int curr = 1, int cstart = 0, int cend = 300000)
{
	if (!rangetree2[curr]) { return; }
	if (cstart == cend)
	{
		rangetree[curr] = am[rangetree[curr]];
		if (rangetree[curr] != 1 && rangetree[curr] != 2) rangetree2[curr] = 1;
		else rangetree2[curr] = 0;
		return;
	}
	int mid = (cstart+cend)/2;
	if (e <= mid)
	{
		update(s, e, 2*curr, cstart, mid);
	}
	else if (s > mid)
	{
		update(s, e, 2*curr+1, mid+1, cend);
	}
	else
	{
		update(s, e, 2*curr, cstart, mid);
		update(s, e, 2*curr+1, mid+1, cend);
	}
	rangetree[curr] = rangetree[2*curr] + rangetree[2*curr+1];
	rangetree2[curr] = rangetree2[2*curr] + rangetree2[2*curr+1];
}
ll query(int s, int e, int curr = 1, int cstart = 0, int cend = 300000)
{
	if (s <= cstart && cend <= e) return rangetree[curr];
	int mid = (cstart+cend)/2;
	if (e <= mid) return query(s, e, 2*curr, cstart, mid);
	else if (s > mid) return query(s, e, 2*curr+1, mid+1, cend);
	else return query(s, e, 2*curr, cstart, mid) + query(s, e, 2*curr+1, mid+1, cend);
}
int main()
{
	fill_n(am, 1000010, 1);
	scanf("%d", &n);
	int mx = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!seive[i])
		{
			for (int j = i; j <= 1000000; j += i)
			{
				seive[j] = true;
				int a = i;
				int c = 0;
				while (j % a == 0)
				{
					c++;
					a *= i;
				}
				am[j]*=c+1;
				mx = max(mx, am[j]);
			}
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &init[i]);
	}
	maketree();
	for (int i = 0; i < m; i++)
	{
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l--;
		r--;
		if (t == 1)
		{
			update(l, r);
		}
		else
		{
			printf("%I64d\n", query(l, r));
		}
	}
}