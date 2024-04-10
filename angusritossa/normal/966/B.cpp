#include <bits/stdc++.h>
using namespace std;
typedef double ld;
int n, x1, x2, ans;
pair<int, int> c[300010];
vector<int> ans1, ans2;
bool solve()
{
	int cando[300010];
	fill_n(cando, 300010, 1e9);
	for (int i = 0; i < n; i++)
	{
		int wouldneed = (x1 / (i+1)) + !!((x1 % (i+1)));
		if (c[i].first >= wouldneed) cando[i] = i;
		if (i) cando[i] = min(cando[i], cando[i-1]);
	}
	for (int i = 0; i < n; i++)
	{
		// if c[i].first was the lowest, how many would we need
		int wouldneed = (x2/c[i].first) + !!(x2%c[i].first);
		if (wouldneed >= i+1) continue;
		int pre = i-wouldneed;
		if (cando[pre] <= n)
		{
			// all good
			for (int j = 0; j <= cando[pre]; j++) ans1.push_back(c[j].second);
			for (int j = cando[pre]+1; j <= cando[pre]+wouldneed; j++) ans2.push_back(c[j].second);
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d%d", &n, &x1, &x2);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i].first);
		c[i].second = i+1;
	}
	sort(c, c+n);
	reverse(c, c+n);
	if (solve())
	{
		printf("Yes\n");
		printf("%d %d\n", ans1.size(), ans2.size());
		for (auto a : ans1) printf("%d ", a);
		printf("\n");
		for (auto a : ans2) printf("%d ", a);
		printf("\n");
		return 0;
	}
	swap(x1, x2);
	if (solve())
	{
		printf("Yes\n");
		printf("%d %d\n", ans2.size(), ans1.size());
		for (auto a : ans2) printf("%d ", a);
		printf("\n");
		for (auto a : ans1) printf("%d ", a);
		printf("\n");
		return 0;
	}
	printf("No\n");
}