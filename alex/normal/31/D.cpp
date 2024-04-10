#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < n; i++)
#define fs first
#define sc second
#define pb push_back
#define y1 sdjfh

using namespace std;

struct rec
{
	int x1, y1, x2, y2;
	rec(int X1, int Y1, int X2, int Y2): x1(X1), y1(Y1), x2(X2), y2(Y2) {}
};

int const NMAX = 1000;
vector <rec> now;
int ans[NMAX], w, h, n;
int x1, y1, x2, y2;
int a[NMAX], b[NMAX], c[NMAX], d[NMAX];
bool used[NMAX];

bool prin2(int v, int x, int y)
{
	if ((now[v].x1 == x || now[v].x2 == x) && (now[v].y1 <= y) && (now[v].y2 >= y)) return true;
	if ((now[v].y1 == y || now[v].y2 == y) && (now[v].x1 <= x) && (now[v].x2 >= x)) return true;
	return false;
}

bool prin(int v)
{
	if (prin2(v, x1, y1) && prin2(v, x2, y2)) return true;
	else return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> w >> h >> n;
	now.pb(rec(0, 0, w, h));

	forn(i, n)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	memset(used, 0, sizeof(used));

	forn(it, n)
	{
		bool flag = false;
		forn(i, n)
			if (!used[i])
			{
				x1 = a[i], y1 = b[i], x2 = c[i], y2 = d[i];
				forn(j, now.size())
					if (prin(j))
					{
						now.pb(rec(now[j].x1, now[j].y1, max(x1, x2), max(y1, y2)));
						now[j].x1 = min(x1, x2);
						now[j].y1 = min(y1, y2);
						flag = true;
						used[i] = true;
						break;
					}
				if (flag) break;
			}
	}

	forn(i, n + 1)
		ans[i] = (now[i].x2 - now[i].x1) * (now[i].y2 - now[i].y1);
	sort(ans, ans + n + 1);
	forn(i, n + 1)
		cout << ans[i] << " ";

	return 0;
}