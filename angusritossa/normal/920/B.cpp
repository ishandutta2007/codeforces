#include <bits/stdc++.h>
using namespace std;
int t;
vector<int> startsat[5010];
int endtime[5010];
int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		for (int i = 0; i <= 5000; i++)
		{
			startsat[i].clear();
		}
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			endtime[i] = b;
			startsat[a].push_back(i);
		}
		queue<int> q;
		for (int i = 1; i <= 5001; i++)
		{
			for (auto l : startsat[i])
			{
				q.push(l);
			}
			while (!q.empty() && endtime[q.front()] < i)
			{
				printf("0 ");
				q.pop();
			}
			if (!q.empty())
			{
				printf("%d ", i);
				q.pop();
			}
		}
		printf("\n");
	}
}