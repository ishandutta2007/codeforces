#include <bits/stdc++.h>
using namespace std;
char g[10][10];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", g[i] + 1);
	int x = 1, y = 1, cnt = (g[1][1] == '*');
	while(x != n || y != m)
	{
		int xx = 0, yy = 0, dis = 114514;
		for(int i = x; i <= n; i++)
			for(int j = y; j <= m; j++)
				if((i != x || j != y) && g[i][j] == '*' && (i - x) + (j - y) < dis)
					xx = i, yy = j, dis = i - x + j - y;
		if(!xx)
			break;
		x = xx, y = yy;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}