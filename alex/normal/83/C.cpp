#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _MY_OPT_MODE_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

typedef long long int64;

#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define all(a) a.begin(), a.end()

template <class T> class Tqueue {
public:
	Tqueue() { h = 0; t = 0; sz = 0; }
	Tqueue(int n) { Tqueue(); resize(n); }
	void resize(int n)
	{
		if (sz > 0) free(data);
		data = (T *) malloc(sizeof(T) * (n + 1));
		sz = n + 1; h = t = 0;
	}
	T front()
	{
#ifndef _MY_OPT_MODE_
		if (h == t) cerr << "ERROR! Tqueue:front() for empty queue!" << endl;
#endif
		return data[h];
	}
	T back()
	{
#ifndef _MY_OPT_MODE_
		if (h == t) cerr << "ERROR! Tqueue:back() for empty queue!" << endl;
#endif
		return data[t - 1];
	}
	int size() { int res = t - h; if (res < 0) res += sz; return res; }
	int empty() { return h == t; }
	void pop()
	{
#ifndef _MY_OPT_MODE_
		if (h == t) cerr << "ERROR! Tqueue:pop() for empty queue!" << endl;
#endif
		h++; if (h == sz) h = 0;
	}
	void push(T x)
	{
		data[t++] = x; if (t == sz) t = 0;
#ifndef _MY_OPT_MODE_
		if (h == t) cerr << "ERROR! Tqueue:push() for full queue!" << endl;
#endif
	}
	~Tqueue() { if (sz > 0) { free(data); sz = 0; } }
private:
	T *data;
	int h, t, sz;
};

const string name = "c";

const int NMAX = 52;
const int KMAX = 5;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, k;
int sx, sy, tx, ty, dist[NMAX][NMAX];
char s[NMAX][NMAX], num[KMAX];
bool may[256];
string ans;

bool good(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m && may[s[x][y]]);
}

vector <pii> tmp, now;
int used[NMAX][NMAX];
Tqueue <pii> q(NMAX * NMAX);

void solve()
{
	seta(may, 0);
	may['S'] = may['T'] = true;
	forn(i, k)
		may[num[i]] = true;

	q.push(mp(tx, ty));
	seta(dist, 255);
	dist[tx][ty] = 0;
	while (!q.empty())
	{
		int x = q.front().fs, y = q.front().sc;
		q.pop();
		forn(i, 4)
			if (dist[x + dx[i]][y + dy[i]] == -1 && good(x + dx[i], y + dy[i]))
			{
				dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
				q.push(mp(x + dx[i], y + dy[i]));
			}
	}

	if (dist[sx][sy] == -1) return;
	now.clear();
	now.pb(mp(sx, sy));
	string res = "";
	seta(used, 0);
	for (int i = dist[sx][sy] - 1; i >= 0; --i)
	{
		tmp.clear();
		char min_c = num[k - 1];
		forn(j, now.size())
		{
			int xx, yy, x = now[j].fs, y = now[j].sc;
			forn(f, 4)
			{
				xx = x + dx[f], yy = y + dy[f];
				if (good(xx, yy) && dist[xx][yy] == dist[x][y] - 1)
					min_c = min(min_c, s[xx][yy]);
			}
		}

		forn(j, now.size())
		{
			int xx, yy, x = now[j].fs, y = now[j].sc;
			forn(f, 4)
			{
				xx = x + dx[f], yy = y + dy[f];
				if (good(xx, yy) && dist[xx][yy] == dist[x][y] - 1 && !used[xx][yy] && s[xx][yy] == min_c)
				{
					tmp.pb(mp(xx, yy));
					used[xx][yy] = true;
				}
			}
		}
		now = tmp;
		if (i) res += min_c;
	}
	if (ans.length() > res.length()) ans = res;
	if (ans.length() == res.length()) ans = min(ans, res);
}

void gen(int pos, char ch)
{
	if (pos == k)
	{
		solve();
		return;
	}
	if (ch > 'z') return;
	gen(pos, ch + 1);
	num[pos] = ch;
	gen(pos + 1, ch + 1);
}

char c[NMAX][NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m >> k;
	forn(i, n)
		cin >> s[i];
	forn(i, n)
		forn(j, m)
		{
			if (s[i][j] == 'S') sx = i, sy = j;
			if (s[i][j] == 'T') tx = i, ty = j;
		}

	ans = "";
	forn(i, n * m + 1)
		ans += "@";
	gen(0, 'a');
	if (ans[0] == '@') cout << -1 << endl;
	else cout << ans.data() << endl;

	cerr << clock() << endl;

	return 0;
}