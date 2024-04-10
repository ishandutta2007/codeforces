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

const int maxn = 1005;

int a[maxn][maxn];
int s[maxn][maxn];

inline int gr(int x1, int y1, int x2, int y2)
{
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

pair < int, int > rows[maxn], cols[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	int cnt = 0;
	pair < int, int > lm = mp(1e9, 1e9);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			scanf("%c", &ch);
			a[i][j] = ch == 'X';
			cnt += ch == 'X';
			if (a[i][j])
			{
				lm = min(mp(i, j), lm);
			}
		}
		scanf("\n");
	}
	
	for (int i = 0; i < maxn; i++)
		rows[i] = mp(-1, -1);
		
	for (int i = 0; i < maxn; i++)
		cols[i] = mp(-1, -1);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	}
	
	int w = 1e9, h = 1e9;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 0)
				continue;
				
			int hh = j;
			while (hh <= m && a[i][hh] == 1) hh++;
			w = min(w, hh - j);
			
			if (rows[i].fst != -1)
			{
				cout << -1;
				return 0;
			}
			
			rows[i] = mp(j, hh - 1);
			j = hh - 1;
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[j][i] == 0)
				continue;
			int hh = j;
			while (hh <= n && a[hh][i] == 1) hh++;
			h = min(h, hh - j);
			if (cols[i].fst != -1)
			{
				cout << -1;
				return 0;
			}
			cols[i] = mp(j, hh - 1);
			j = hh - 1;
		}
	}
	
	for (int i = 1; i + 1 <= n; i++)
	{
		if (rows[i].fst == -1 || rows[i + 1].fst == -1)
			continue;
		int l = max(rows[i].fst, rows[i + 1].fst);
		int r = min(rows[i].snd, rows[i + 1].snd);
		w = min(w, max(0, r - l + 1));
	}
	
	for (int i = 1; i + 1 <= m; i++)
	{
		if (cols[i].fst == -1 || cols[i + 1].fst == -1)
			continue;
		int l = max(cols[i].fst, cols[i + 1].fst);
		int r = min(cols[i].snd, cols[i + 1].snd);
		h = min(h, max(0, r - l + 1));
	}
	
	if (!h || !w)
	{
		cout << -1;
		return 0;
	}
	
	int vis = 0;
	
	for (int i = lm.fst; i <= min(n, lm.fst + h - 1); i++)
		for (int j = lm.snd; j <= min(m, lm.snd + w - 1); j++)
			vis += a[i][j];
			
	if (vis == cnt && vis == h * w)
	{
		cout << min(h, w);
		return 0;
	}
	
	int ho = h, wo = w;
	int ans = 1e9;
	for (int h = ho; h > 0; h--)
	for (int w = wo; w > 0; w--)
	{
		vis = h * w;
		
		int x = lm.fst, y = lm.snd;
		while (true)
		{
			if (gr(x, y, x + h - 1, y + w - 1) != h * w)
			{
				break;
			}
			
			bool b1 = x + h <= n && gr(x + 1, y, x + h, y + w - 1) == h * w;
			bool b2 = y + w <= m && gr(x, y + 1, x + h - 1, y + w) == h * w;
			
			if (b1 && b2)
				break;
			else if (b1)
			{
				x++;
				vis += w;
			}
			else if (b2)
			{
				y++;
				vis += h;
			}
			else
				break;
		}
		
		if (vis != cnt)
		{
			//cout << -1 << endl;
			continue;
		}
		
		ans = min(ans, h * w);
	}
	int inf = 1e9;
	if (inf == ans)
		cout << -1;
	else
		cout << ans;
	
	return 0;
}