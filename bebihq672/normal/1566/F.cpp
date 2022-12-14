#include<bits/stdc++.h>
using namespace std;

long long a[202020];


long long dp[202020][2];


struct Segment{
	long long l, r;
}s[202020];

bool cmp(const Segment &x, const Segment &y)
{
	if(x.l != y.l)
		return x.l < y.l;
	return x.r > y.r;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for(int i = 1; i <= m; i++)
			scanf("%lld%lld", &s[i].l, &s[i].r);
		sort(a + 1, a + n + 1);
		sort(s + 1, s + m + 1, cmp);
		int mm = 0;
		for(int i = 1, j = 1; i <= m; i++)
		{
			while(j <= n && a[j] < s[i].l)
				j++;
			if(j <= n && s[i].l <= a[j] && a[j] <= s[i].r)
				continue;
			while(mm > 0 && s[mm].r >= s[i].r)
				mm--;
			mm++;
			s[mm] = s[i];
		}
		m = mm;
		dp[0][0] = dp[0][1] = 0;
		a[n + 1] = 1e9 + 100;
		for(int i = 1, j = 1; i <= n + 1; i++)
		{
			dp[i][0] = dp[i][1] = 1e18;
			vector<Segment> V;
			while(j <= m && s[j].r <= a[i])
			{
				V.push_back(s[j]);
				j++;
			}
			/*
			cerr << i << " =================== " << a[i] << endl;
			for(Segment seg: V)
				cerr << seg.l << " " << seg.r << endl;
			*/
			if(V.empty())
			{
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
				continue;
			}
			if(i == 1)
			{
				dp[i][0] = 2 * (a[i] - V[0].r);
				dp[i][1] = a[i] - V[0].r;
				continue;
			}
			if(i == n + 1)
			{
				dp[i][0] = dp[i - 1][0] + (V[V.size() - 1].l - a[i - 1]);
				dp[i][1] = dp[i - 1][1] + 2 * (V[V.size() - 1].l - a[i - 1]);
				continue;
			}
			for(int k = 0; k <= V.size(); k++)
			{
				int ll, rr;
				if(k == 0)
					ll = a[i - 1];
				else
					ll = V[k - 1].l;
				if(k == V.size())
					rr = a[i];
				else
					rr = V[k].r;
				dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + (ll - a[i - 1]) + (a[i] - rr) * 2, dp[i - 1][1] + (ll - a[i - 1]) * 2 + (a[i] - rr) * 2));
				dp[i][1] = min(dp[i][1], min(dp[i - 1][0] + (ll - a[i - 1]) + (a[i] - rr), dp[i - 1][1] + (ll - a[i - 1]) * 2 + (a[i] - rr)));
			}
			// cerr << i << " " << dp[i][0] << " " << dp[i][1] << endl;
		}
		printf("%lld\n", min(dp[n + 1][0], dp[n + 1][1]));
	}
    return 0;
}