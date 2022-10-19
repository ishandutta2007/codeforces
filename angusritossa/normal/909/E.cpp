#include <bits/stdc++.h>
using namespace std;
int ans, n, m;
queue<int> q1, q2;
vector<int> dependson[100010], dependsonme[100010];
int workingparents[100010];
int cantgoonmain[100010];
void check(int a, bool isnew)
{
	if (isnew) workingparents[a]++;
	if (workingparents[a] == dependson[a].size())
	{
		if (cantgoonmain[a]) q2.push(a);
		else q1.push(a);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &cantgoonmain[i]);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		dependson[a].push_back(b);
		dependsonme[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		check(i, false);
	}
	for (int i = 0; i <= n; i++)
	{
		while (!q1.empty())
		{
			int a = q1.front();
			q1.pop();
			for (auto b : dependsonme[a]) check(b, true);
		}
		if (q1.size() + q2.size() == 0)
		{
			printf("%d\n", i);
			return 0;
		}
		while (!q2.empty())
		{
			int a = q2.front();
			q2.pop();
			for (auto b : dependsonme[a]) check(b, true);
		}

	}
}