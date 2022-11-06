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
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "b";

const int NMAX = 2010;
const int d = 237017;
#define I (int)

int l[NMAX], r[NMAX];
string s, begin, end;
vector <pair <int, int64> > ans;
int64 st[NMAX], h[NMAX];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> s;
	cin >> begin >> end;
	int zn = max(begin.length(), end.length());

	forn(i, max(0, I s.length() - I begin.length() + 1))
		l[i] = s.substr(i, begin.length()) == begin;
	forn(i, max(0, I s.length() - I end.length() + 1))
		r[i + end.length() - 1] = s.substr(i, end.length()) == end;

	h[0] = 0, st[0] = 1;
	forn(i, s.length())
	{
		h[i + 1] = h[i] * d + s[i];
		st[i + 1] = st[i] * d;
	}

	forn(j, s.length())
		forn(i, j + 1)
			if (j - i + 1 >= zn && l[i] && r[j])
				ans.pb(mp(j - i + 1, h[j + 1] - h[i] * st[j - i + 1]));
	sort(all(ans));
	cout << unique(all(ans)) - ans.begin() << endl;

	return 0;
}