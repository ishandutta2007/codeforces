#include <bits/stdc++.h>

using namespace std;

typedef long double ftype;

const int maxN = 1005;
char g[maxN][maxN];

int nRows, nColumns;

const int INF = 1e9 / 2;

vector<vector<int>> bfs(char from)
{
	vector<vector<int>> d(nColumns, vector<int>(nRows, INF));
	
	deque<pair<int, int>> bfsQueue;
	
	for (int x = 0; x < nColumns; x++)
		for (int y = 0; y < nRows; y++)
			if (g[x][y] == from)
			{
				d[x][y] = 0;
				bfsQueue.push_back(make_pair(x, y));
			}
			
	while (!bfsQueue.empty())
	{
		pair<int, int> u = bfsQueue.front();
		bfsQueue.pop_front();
		
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
			{
				if (abs(dx) + abs(dy) != 1) continue;
				
				int tx = u.first + dx, ty = u.second + dy;
				if (tx < 0 || ty < 0 || tx >= nColumns || ty >= nRows) continue;
				
				if (d[tx][ty] != INF || g[tx][ty] == '#') continue;
				
				d[tx][ty] = d[u.first][u.second] + 1;
				bfsQueue.push_back(make_pair(tx, ty));
			}
	}
	
	return d;
}

int main()
{
	scanf("%d %d", &nRows, &nColumns);
	
	for (int y = 0; y < nRows; y++)
		for (int x = 0; x < nColumns; x++)
			scanf(" %c", &g[x][y]);
		
	vector<vector<int>> da = bfs('1'), db = bfs('2'), dc = bfs('3');
	
	int dAB = INF, dBC = INF, dAC = INF;
	
	for (int y = 0; y < nRows; y++)
		for (int x = 0; x < nColumns; x++)
			if (g[x][y] == '1')
			{
				dAB = min(dAB, db[x][y]);
				dAC = min(dAC, dc[x][y]);
			}
			else if (g[x][y] == '2')
			{
				dAB = min(dAB, da[x][y]);
				dBC = min(dBC, dc[x][y]);
			}
			else if (g[x][y] == '3')
			{
				dAC = min(dAC, da[x][y]);
				dBC = min(dBC, db[x][y]);
			}
			
	assert(dAB > 0 && dBC > 0 && dAC > 0);
			
	if (dAB == INF || dBC == INF || dAC == INF)
	{
		printf("-1\n");
		return 0;
	}
	
	dAB--; dAC--; dBC--;
	
	//printf("%d %d %d\n", dAB, dBC, dAC);
	
	int answer = min(dAB + dBC, min(dAB + dAC, dBC + dAC));
	
	for (int y = 0; y < nRows; y++)
		for (int x = 0; x < nColumns; x++)
		{
			if (g[x][y] == '#') continue;
			int can = (da[x][y] - (g[x][y] != '1')) + (db[x][y] - (g[x][y] != '2')) + (dc[x][y] - (g[x][y] != '3')) + (g[x][y] == '.');
				//printf("can %d at %d %d (dists %d %d %d)\n", can, x, y, da[x][y], db[x][y], dc[x][y]);
			if (can < answer)
			{
				answer = can;
			}
		}
		
	printf("%d\n", answer);
	
	return 0;
}