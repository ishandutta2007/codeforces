#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 55;

int n, m;
int k[MAXN];
int a[MAXN][MAXN];
int x[MAXN * MAXN], y[MAXN * MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &k[i]);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
		{
			scanf("%d", &a[i][j]);
			x[a[i][j]] = i;
			y[a[i][j]] = j;
		}
	}
	
	
	vector < pair < pair <int, int>, pair <int, int> > > v;
	
	
	int ind = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k[i]; j++)
		{
			ind++;
			if (a[i][j] != ind)
			{
				int x1 = i, y1 = j, x2 = x[ind], y2 = y[ind];
				swap(a[x1][y1], a[x2][y2]);
				x[a[x1][y1]] = x1;
				y[a[x1][y1]] = y1;
				x[a[x2][y2]] = x2;
				y[a[x2][y2]] = y2;
				v.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
			}
		}
	printf("%d\n", (int)v.size());
	for (int i = 0; i < (int)v.size(); i++)
		printf("%d %d %d %d\n", v[i].first.first + 1, v[i].first.second + 1, v[i].second.first + 1, v[i].second.second + 1);
	return 0;
}