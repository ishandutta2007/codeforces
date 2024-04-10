#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second
#define ld long double

int w[1005][1005];
int dist[1005][1005];
int sums[1000500];
int r, c;

const int dirs[4][2] = 
{
	1, 0,
	0, 1,
	-1, 0,
	0, -1,
};

bool valid(int x, int y)
{
	return 0 <= x && x < r && 0 <= y && y < c;
}

int main(int argc, char **argv)
{
	int sx, sy;
	int fx, fy;
	scanf("%d %d\n", &r, &c);
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char ch;
			scanf("%c", &ch);
			if (ch == 'T')
				w[i][j] = -1;
			else if (ch == 'S')
			{
				w[i][j] = 0;
				sx = i;
				sy = j;
			}
			else if (ch == 'E')
			{
				w[i][j] = 0;
				fx = i;
				fy = j;
			}
			else
			{
				w[i][j] = ch - '0';
			}
			
			dist[i][j] = -1;
		}
		scanf("\n");
	}
	
	queue < pair < pair < int, int >, int > > q;
	q.push(mp(mp(fx, fy), 0));
	
	while (!q.empty())
	{
		int x = q.front().fst.fst;
		int y = q.front().fst.snd;
		int d = q.front().snd;
		q.pop();
		
		if (dist[x][y] != -1)
			continue;
			
		dist[x][y] = d;
		
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dirs[i][0];
			int yy = y + dirs[i][1];
			
			if (valid(xx, yy) && w[xx][yy] != -1 && dist[xx][yy] == -1)
				q.push(mp(mp(xx, yy), d+1));
		}
	}
	
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (w[i][j] > 0)
			{
				sums[dist[i][j]] += w[i][j];
			}
		}
	}
	
	for (int i = 1; i <= r*c; i++)
		sums[i] += sums[i-1];	
	
	cout << sums[dist[sx][sy]];
	
	return 0;
}