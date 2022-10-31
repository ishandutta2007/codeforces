#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}


char f[2005][2005];
int used[2005][2005];
int dpLen[2005][2005];
pair < int, int > dpTo[2005][2005];
pair < int, pair < int, int > > a[2005 * 2005];

bool cycle()
{
	cout << -1;
	exit(0);
}

void dfs(int x, int y)
{
	used[x][y] = 1;
	
	int dx = 0, dy = 0;
	if (f[x][y] == '>')
		dy = 1;
	else if (f[x][y] == '<')
		dy = -1;
	else if (f[x][y] == 'v')
		dx = 1;
	else
		dx = -1;
		
		
	if (f[x + dx][y + dy] == '#')
	{
		dpLen[x][y] = 1;
		dpTo[x][y] = mp(x, y);
	}
	else
	{
		if (used[x + dx][y + dy] == 1)
			cycle();
			
		dfs(x + dx, y + dy);
		dpLen[x][y] = dpLen[x + dx][y + dy] + 1;
		dpTo[x][y] = dpTo[x + dx][y + dy];
	}
	
	used[x][y] = 2;
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &f[i][j]);
			cnt += f[i][j] != '#';
		}
		scanf("\n");
	}
	
	if (cnt < 2)
	{
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (f[i][j] != '#' && used[i][j] == 0)
				dfs(i, j);
		}
	}
	
	
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (f[i][j] == '#')
			{
				//cerr << 0 << " ";
				continue;
			}
			a[pos++] = mp(dpLen[i][j], mp(i, j));
			//cerr << dpTo[i][j].snd << " ";
		}
		//cerr << endl;
	}
	
	
	
	sort(a, a + pos);
	
	int ans = 0;
	
	for (int i = pos - 2; i >= 0; i--)
	{
		
		if (dpTo[a[i].snd.fst][a[i].snd.snd] == dpTo[a[pos-1].snd.fst][a[pos-1].snd.snd])
		{
			//cerr << a[n-1].fst << " " << a[i].fst << endl;
			if (a[pos-1].fst == a[i].fst)
				ans = max(ans, a[i].fst * 2 - 1);
			else
				ans = max(ans, a[pos-1].fst + a[i].fst);
		}
		else
		{
			ans = max(ans, a[pos-1].fst + a[i].fst);
		}
		//cerr << ans << endl;
	}
	
	
	cout << ans << endl;
	
	return 0;
}