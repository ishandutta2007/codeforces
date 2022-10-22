#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

char g[505][505];
int s1[505][505], s2[505][505];

int main()
{
	int h, w;
	scanf("%d %d", &h, &w);
	
	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
			scanf(" %c", &g[x][y]);
		
	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
		{
			if (g[x][y] == '.' && g[x + 1][y] == '.')
				s1[x][y]++;
			if (g[x][y] == '.' && g[x][y + 1] == '.')
				s2[x][y]++;
			
			s1[x][y] += s1[x][y - 1] + s1[x - 1][y] - s1[x - 1][y - 1];
			s2[x][y] += s2[x][y - 1] + s2[x - 1][y] - s2[x - 1][y - 1];
		}
		
	int nq;
	scanf("%d", &nq);
	
	for (int i = 0; i < nq; i++)
	{
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		
		int ans = 0;
		{
			x1--;
			y1--;
			
			x2--;
			if (x2 >= x1)
			ans += s1[x2][y2] - s1[x2][y1] - s1[x1][y2] + s1[x1][y1];
			
			x2++;
			y2--;
			if (y2 >= y1)
			ans += s2[x2][y2] - s2[x2][y1] - s2[x1][y2] + s2[x1][y1];
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}