#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a%b);
}
int n, m;
vector<pair<int, int> > edges;
int coun = 0;
int edgescount;
int main()
{
	scanf("%d%d", &n, &m);
	if (m < n-1)
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i = 1; i <= n && coun <= 2000000; i++)
	{
		for (int j = i+1; j <= n && edgescount < m; j++)
		{
			coun++;
			if (gcd(i, j) == 1)
			{
				edgescount++;
				edges.push_back({ i, j });
			}
		}
	}
	if (edgescount != m)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");
		for (auto a : edges) printf("%d %d\n", a.first, a.second);
	}
}