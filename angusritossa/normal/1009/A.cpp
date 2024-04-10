#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int costs[1010], n, m, ans;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &costs[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		q.push(a);
	}
	for (int i = 0; i < n && q.size(); i++)
	{
		if (q.front() >= costs[i])
		{
			q.pop();
			ans++;
		}
	}
	printf("%d\n", ans);
}