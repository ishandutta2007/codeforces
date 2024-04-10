#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 100005;

const int dirs[3][2]
{
	0, -1,
	0, 1,
	-1, 0,
};

int a[maxn][15];
int nice[maxn][15];
pair < int, int > en[maxn][15];

int used[maxn][15];

void dfs(int x, int y)
{
	used[x][y] = 1;	
	if (nice[x][y])
	{
		en[x][y] = mp(x, y);
		used[x][y] = 2;
		return;
	}
	int cx = x + dirs[a[x][y]][0];
	int cy = y + dirs[a[x][y]][1];
	if (used[cx][cy] == 1)
	{
		en[x][y] = mp(-1, -1);
		used[x][y] = 2;
		return;
	}
	if (used[cx][cy] == 2)
	{
		en[x][y] = en[cx][cy];
		used[x][y] = 2;
		return;
	}
	dfs(cx, cy);
	en[x][y] = en[cx][cy];
	used[x][y] = 2;
}

int n, m;

void rebuild()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 12; j++)
			used[i][j] = 0;
			
	for (int i = 0; i <= n + 1; i++)
	{
		nice[i][0] = nice[i][m + 1] = 1;
	}
	
	for (int i = 0; i < m + 2; i++)
		nice[0][i] = nice[n + 1][i] = 1;
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!used[i][j])
				dfs(i, j);
}

int used2[maxn][15];
int currUsed = 1;

pair < int, int > get(int x, int y)
{
	currUsed++;
	//cout << 111 << endl;
	while (true)
	{
		if (en[x][y].fst == -1)
			return mp(-1, -1);
			
		if (x == n + 1)
			return mp(x, y);
			
		if (y == m + 1 || y == 0)
			return mp(x, y);
			
		if (x == 0)
			return mp(x, y);
			
		int cx = en[x][y].fst;
		int cy = en[x][y].snd;
		
		//cout << cx << " " << cy << endl;
		
		if (cx == n + 1)
			return mp(cx, cy);
			
		if (cy == m + 1 || cy == 0)
			return mp(cx, cy);
			
		if (cx == 0)
			return mp(cx, cy);
			
		if (used2[cx][cy] == currUsed)
			return mp(-1, -1);
			
		used2[cx][cy] = currUsed;
			
		int dx = cx + dirs[a[cx][cy]][0];
		int dy = cy + dirs[a[cx][cy]][1];
		//cout << dx << " " << dy << endl;
		
		
		x = dx, y = dy;
	}
}

struct qq
{
	int type;
	int x, y, c;
	qq()
	{
	}
	qq(int _type, int _x, int _y, int _c)
	{
		type = _type;
		x = _x;
		y = _y;
		c = _c;
	}
};

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int q;
	scanf("%d %d %d\n", &n, &m, &q);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			scanf("%c", &c);
			if (c == '^')
				a[i][j] = 2;
			else if (c == '<')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
		scanf("\n");
	}
	
	const int sz = 300;
	
	vector < qq > qe;
	
	while (q)
	{
		qe.clear();
		
		for (int i = 0; i < n + 1; i++)
			for (int j = 0; j < m + 1; j++)
				nice[i][j] = 0;
				
		int modCnt = 0;
				
		while (q && modCnt < sz)
		{
			char t;
			scanf("%c", &t);
			int x, y;
			char c;
			
			if (t == 'A')
			{
				scanf("%d %d\n", &x, &y);
				qe.pb(qq(1, x, y, 1));
			}
			else
			{
				scanf("%d %d %c\n", &x, &y, &c);
				
				int dir;
				if (c == '^')
					dir = 2;
				else if (c == '<')
					dir = 0;
				else
					dir = 1;
					
				nice[x][y] = 1;
					
				qe.pb(qq(2, x, y, dir));
				modCnt++;
			}
			q--;
		}
		
		rebuild();
		
		for (auto x : qe)
		{
			if (x.type == 1)
			{
				auto res = get(x.x, x.y);
				printf("%d %d\n", res.fst, res.snd);
			}
			else
			{
				a[x.x][x.y] = x.c;
			}
		}
	}
	
	

	return 0;
}