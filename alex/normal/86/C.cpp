#pragma comment(linker, "/STACK:60000000")
//#define _MY_OPT_MODE_
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <deque>

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int64 const inf64 = (int64) 4e18;
const string name = "c";

const int NMAX = 1024;
const int PMAX = 555;
const int P = 1000000009;
const string ZN[5] = {"A", "C", "G", "T", "@"};

int n, m, d[NMAX][PMAX][11];
vector <string> pre, s;
int l[PMAX][5], r[PMAX][5], nxt[PMAX][5], used[13];

void calc(int i, int c)
{
	string now = pre[i] + ZN[c];
	ford(j, now.length() + 1)
		forn(f, pre.size())
			if (now.substr(now.length() - j, j) == pre[f])
			{
				nxt[i][c] = f;
				seta(used, 0);
				forn(p, now.length() - j)
					forn(t, m)
						if (now.substr(p, s[t].length()) == s[t])
							forn(w, s[t].length())
								used[p + w] = 1;
				l[i][c] = r[i][c] = -1;
				ford(p, 12)
					if (used[p])
					{
						r[i][c] = p;
						while (p > 0 && used[p - 1]) p--;
						l[i][c] = p;
						break;
					}
				return;
			}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	cin >> n >> m;
	pre.pb("");
	forn(i, m)
	{
		char buf[11];
		scanf("%s", buf);
		s.pb((string) buf);
		forn(j, s[i].length())
			pre.pb(s[i].substr(0, j + 1));
	}
	sort(all(pre));
	pre.resize(unique(all(pre)) - pre.begin());

	forn(i, pre.size())
		forn(c, 5)
			calc(i, c);

	seta(d, 0);
	d[0][0][0] = 1;
	forn(i, n + 1)
		forn(j, pre.size())
			forn(f, pre[j].size() + 1)
				if (d[i][j][f] > 0)
					forn(c, 5)
						if ((c < 4 && i < n) || (c == 4 && i == n))
						{
							int jj = nxt[j][c], ff = f + 1;
							if ((int) pre[j].size() - f >= l[j][c])
								ff = min(ff, (int) pre[j].length() - r[j][c]);
							if (ff <= (int) pre[jj].size() || i == n)
								d[i + 1][jj][ff] = (d[i + 1][jj][ff] + d[i][j][f]) % P;
						}
	cout << d[n + 1][0][1] << endl;

	return 0;
}