#include <bits/stdc++.h>
using namespace std;
int actions[200], n, mapping[200], ans;
char grid[200][200];
bool dfs(int x, int y, int a)
{
//	printf("%d %d %d %d\n", a, x, y, mapping[actions[a]]);
	if (grid[x][y] == 'E') return true;
	if (a == n) return false;
	if (grid[x][y] == '#') return false;
	if (mapping[actions[a]] == 0) return dfs(x+1, y, a+1);
	else if (mapping[actions[a]] == 1) return dfs(x, y-1, a+1);
	else if (mapping[actions[a]] == 2) return dfs(x-1, y, a+1);
	else if (mapping[actions[a]] == 3) return dfs(x, y+1, a+1);
	else assert(false);
}
char inp[200];
int x, y;
int main()
{
	for (int i = 0; i < 4; i++) mapping[i] = i;
	int r, c;
	scanf("%d%d", &r, &c);
	for (int i = 0; i < 200; i++) fill_n(grid[i], 200, '#');
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) { scanf(" %c", &grid[i][j]); if (grid[i][j] == 'S') { x = i; y = j; } }
	}
	scanf(" %s", inp);
	n = strlen(inp);
	for (int i = 0; i < n; i++)
	{
		actions[i] = inp[i]-'0';
	}
	for (int i = 0; i < 24; i++)
	{
	//	printf("%d %d\n", x, y);
	//	for (int j = 0; j < 4; j++) printf("%d ", mapping[j]);
	//	printf("\n");
		if (dfs(x, y, 0)) ans++;
		next_permutation(mapping, mapping+4);
	//	break;
	}
	printf("%d\n", ans);
}