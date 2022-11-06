#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define seta(a, b) memset(a, b, sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define int64 long long

//int a, b, n, m, x, y, d;

int h, n, used[300];
vector < pair < pair<int, int>, int> > ans;
vector <int> now;
map <int, char> zn;

void answer()
{
	cout << ans.size() << endl;
	zn[1] = 'a';
	char ch = 'a';
	forn(i, ans.size())
	{
		zn[now[i + 1]] = ++ch;
		if (ans[i].sc == -1)
			cout << "lea e" << zn[now[i + 1]] << "x, [" << ans[i].fs.sc
			<< "*e" << zn[ans[i].fs.fs] << "x]" << endl;
		else
			cout << "lea e" << zn[now[i + 1]] << "x, [" 
			"e" << zn[ans[i].sc] << "x + " << ans[i].fs.sc
			<< "*e" << zn[ans[i].fs.fs] << "x]" << endl;
	}
	exit(0);
}

void calc(int hh)
{
	if (hh == h)
	{
		if (used[n]) answer();
		return;
	}

	int v;
forn(i, hh + 1)
	forn(j, 4)
	{
		v = now[i] * (1 << j);
		if (v <= n && !used[v])
		{
			used[v] = 1;
			now.pb(v);
			ans.pb(mp(mp(now[i], 1 << j), -1));
			calc(hh + 1);
			now.pop_back();
			ans.pop_back();
			used[v] = 0;
		}
	}

forn(i, hh + 1)
forn(f, hh + 1)
	forn(j, 4)
	{
		v = now[f] + now[i] * (1 << j);
		if (v <= n && !used[v])
		{
			used[v] = 1;
			now.pb(v);
			ans.pb(mp(mp(now[i], 1 << j), now[f]));
			calc(hh + 1);
			now.pop_back();
			ans.pop_back();
			used[v] = 0;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	now.pb(1);
	forn(i, n)
	{
		seta(used, 0);
		ans.clear();
		h = i + 1;
		calc(0);
	}

/*	cin >> n >> m >> a >> b;
	a--;
	x = a % m;
	y = b % m;
	d = b / m - a / m - 1;
	if (x == 0) d++;

	if (a / m == b / m)
	{
		cout << 1 << endl;
		return 0;
	}

	if (x == 0 && y == 0) cout << 1 << endl;
	else if (d == 0 || x == y || x == 0 || y == 0) cout << 2 << endl;
	else cout << 3 << endl;
*/
	return 0;
}