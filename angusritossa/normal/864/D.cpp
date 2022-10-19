#include <bits/stdc++.h>
using namespace std;
int c[200010], n, a[200010], ans;
bool missed[200010];
priority_queue<int> pq;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
		{
			pq.push(-i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (c[a[i]] != 1)
		{
			if (-pq.top() < a[i] || missed[a[i]])
			{
				c[a[i]]--;
				a[i] = -pq.top();
				pq.pop();
				ans++;
			}
			else
			{
				missed[a[i]] = true;
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
}