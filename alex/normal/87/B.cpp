#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "b";

int n;
string a, b, s;
map <string, pii> M;

int main()
{
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);
	cin >> n;
	M["void"] = mp(0, 0);
	M["errtype"] = mp(-1, -1);
	forn(i, n)
	{
		cin >> s;
		if (s[4] == 'd')
		{
			cin >> a >> b;
			int x, y, xx = a.length(), yy = a.length();
			forn(i, a.length())
				if (a[i] != '&')
				{
					xx = i;
					break;
				}
			for (int i = a.length() - 1; i >= 0; --i)
				if (a[i] != '*')
				{
					yy = a.length() - i - 1;
					break;
				}
			if (!M.count(a.substr(xx, a.length() - xx - yy)))
			{
				M[b] = M[a.substr(xx, a.length() - xx - yy)] = mp(-1, -1);
				continue;
			}
			x = M[a.substr(xx, a.length() - xx - yy)].fs;
			y = M[a.substr(xx, a.length() - xx - yy)].sc;
			int d = min(x + xx, y + yy);
			if (x == -1 || y == -1 || x + xx > y + yy) M[b] = mp(-1, -1);
			else M[b] = mp(x + xx - d, y + yy - d);
		}
		else
		{
			cin >> a;
			int x, y, xx = a.length(), yy = a.length();
			forn(i, a.length())
				if (a[i] != '&')
				{
					xx = i;
					break;
				}
			for (int i = a.length() - 1; i >= 0; --i)
				if (a[i] != '*')
				{
					yy = a.length() - i - 1;
					break;
				}
			a = a.substr(xx, a.length() - xx - yy);
			if (!M.count(a) || M[a] == mp(-1, -1) || M[a].fs + xx > M[a].sc + yy)
				cout << "errtype" << endl;
			else
			{
				int x = M[a].fs + xx, y = M[a].sc + yy;
				int d = min(x, y);
				x -= d, y -= d;
				forn(i, x)
					printf("&");
				cout << "void";
				forn(i, y)
					printf("*");
				cout << endl;
			}
		}
	}

	return 0;
}