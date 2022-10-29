#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
using namespace std;
#define XY pair<int,int>
#define X first
#define Y second

XY p[(int)10e2 +1];
int hash[(int)10e2 + 1];
int rec[(int)10e2 + 1];
int r, n;

bool dfs(int a, int e)
{
	e += rec[a];
	hash[a] = e;
	if(a == n-1)
		return true;
	bool retv = false;
	for(int i = 0; i < n; i++)
	{
		int d = r * (abs(p[a].X - p[i].X) + abs(p[a].Y - p[i].Y));
		if(d <= e && a != i && (hash[i] == 0 || hash[i] < (e - d + rec[i])))
			retv = (retv || dfs(i, (e - d)));
		if(retv) return retv;
	}
	return retv;
}

main(void)
{
	int i;
	scanf("%d %d", &n, &r);
	for(i = 1; i < n-1; i++)
		scanf("%d", &rec[i]);
	for(i = 0; i < n; i++)
		scanf("%d %d", &p[i].X, &p[i].Y);
	int top = 10e8, bot = 0, mid, ans = 10e8;
	while(top >= bot)
	{
		mid = (top+bot) / 2;
		memset(hash,0,sizeof(hash));
		if(dfs(0, mid))
			top = (ans = mid) - 1;
		else
			bot = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}