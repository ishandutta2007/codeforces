#include <stdio.h>
#include <vector>
using namespace std;

char grid[2123][2123];
int hash[2123][2123];
bool been[2123][2123], cicle, blocked[2123][2123], flag;

int dfs(int i, int j)
{
	if(been[i][j] && hash[i][j] == 0)
		cicle = true;
	if(grid[i][j] == '#' || been[i][j])
		return hash[i][j];
	been[i][j] = true;
	if(grid[i][j] == '<')
		hash[i][j] = dfs(i, j-1) + 1;
	else if(grid[i][j] == '>')
		hash[i][j] = dfs(i, j+1) + 1;
	else if(grid[i][j] == 'v')
		hash[i][j] = dfs(i+1, j) + 1;
	else
		hash[i][j] = dfs(i-1, j) + 1;
	return hash[i][j];
}

void block(int i, int j)
{
	if(blocked[i][j]) return;
	blocked[i][j] = true;
	if(grid[i][j-1] == '>')
		block(i, j-1);
	if(grid[i][j+1] == '<')
		block(i, j+1);
	if(grid[i+1][j] == '^')
		block(i+1, j);
	if(grid[i-1][j] == 'v')
		block(i-1, j);
}

void dfs2(int i, int j)
{
	if(grid[i][j] == '#')
		return;
	block(i,j);
	if(grid[i][j] == '<')
		dfs2(i, j-1);
	else if(grid[i][j] == '>')
		dfs2(i, j+1);
	else if(grid[i][j] == 'v')
		dfs2(i+1, j);
	else
		dfs2(i-1, j);
}

int
main(void)
{
	int n, m, mx = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf(" %c", &grid[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(grid[i][j] != '#' && been[i][j] == 0)
				mx = max(dfs(i, j), mx);
	if(cicle){	printf("-1\n"); return 0; }
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(hash[i][j] == mx)
			{
				dfs2(i,j);
				mx++;
			}
	for(int i = 0; i < n && !flag; i++)
		for(int j = 0; j < m && !flag; j++)
			if(hash[i][j] == mx - 1 && !blocked[i][j])
				flag = true;
	printf("%d\n", flag ? (2*(mx-1)) : (2*(mx-1) - 1) );
}