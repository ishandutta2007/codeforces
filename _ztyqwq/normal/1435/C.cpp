#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
struct Number
{
	int i, j, x;
	bool operator<(const Number &b) const
	{
		return x < b.x;
	}
	bool operator > (const Number & b) const
	{
		return x > b.x;
	}
}c[600001];
int a[7], b[100001][7];
priority_queue <Number, vector<Number>, greater<Number> > pq;
bool vis[100001][7];
signed main()
{
	for(int i = 1; i <= 6; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 7);
	for(int i = 1; i <= 3; i++)
		swap(a[i], a[7 - i]);
	int n;
	scanf("%lld", &n);
	int m = 0, mn, mx = 0, ans = 1145141919810ll;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i][0]);
		for(int j = 1; j <= 6; j++)
		{
			b[i][j] = b[i][0] - a[j];
			c[++m] = {i, j, b[i][j]};
		}
		pq.push({i, 1, b[i][1]});
		mx = max(mx, b[i][1]);
	}
	auto u = pq.top();
	mn = u.x;
	sort(c + 1, c + m + 1);
	for(int i = 1; i <= m; i++)
	{
		auto u = pq.top();
		while(u.x < c[i].x)
		{
			if(u.j == 6)
				goto end;
			pq.pop();
			pq.push({u.i, u.j + 1, b[u.i][u.j + 1]});
			mx = max(mx, b[u.i][u.j + 1]);
			u = pq.top();
		}
		mn = pq.top().x;
		ans = min(ans, mx - mn);
	}
	end:
	printf("%lld\n", ans);
	return 0;
}