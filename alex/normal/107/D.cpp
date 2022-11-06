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

#include <ctime>
#include <cassert>

using namespace std;

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;

#define div sdfjh
#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1];
#define mp make_pair
#define fs first
#define sc second
#define I (int)

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9 + 1;
int64 const inf64 = (int64) 4e18 + 1;
const string name = "d";

const int NMAX = 128;
const int P = 12345;

int64 n;
int m, K, k[256], zn[NMAX], used[NMAX];
char ch[NMAX];
vector <int> div[NMAX];
vector < pair <char, int> > value[NMAX];
map <vector < pair <char, int> >, int> num;
int res[NMAX][NMAX], a[NMAX][NMAX];
int64 q[NMAX][NMAX];

int gcd(int a, int b)
{
	if (a * b == 0) return a + b;
	else return gcd(b % a, a);
}

vector < pair <char, int> > now;

void rec(int x)
{
	if (x == 256)
	{
		num[now] = K;
		value[K] = now;
		K++;
		return;
	}
	if (!used[x])
		rec(x + 1);
	else
	{
		forn(i, k[x])
		{
			now.pb(mp((char) x, i));
			rec(x + 1);
			now.pop_back();
		}
	}	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen((name + ".in").data(), "r", stdin);
	freopen((name + ".out").data(), "w", stdout);
#endif

	forn(i, 256)
	{
		used[i] = 0;
		k[i] = 1;
	}
	cin >> n >> m;
	if (n == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	if (m == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	forn(i, m)
	{
		scanf(" %c%d", &ch[i], &zn[i]);
		div[ch[i]].pb(zn[i]);
		k[ch[i]] = k[ch[i]] * zn[i] / gcd(k[ch[i]], zn[i]);
		used[ch[i]] = 1;
	}

	K = 0;
	now.clear();
	rec(0);
	m = value[0].size();

	seta(a, 0);
	forn(i, K)
		forn(j, m)
		{
			vector <pair <char, int> > tmp = value[i];
			tmp[j].sc= (tmp[j].sc+ 1) % k[tmp[j].fs];
			a[i][num[tmp]]++;
		}

	seta(res, 0);
	forn(i, K)
		res[i][i] = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			seta(q, 0);
			forn(i, K)
				forn(j, K)
					forn(f, K)
						q[i][j] += res[i][f] * a[f][j];
			forn(i, K)
				forn(j, K)
					res[i][j] = q[i][j] % P;
		}
		seta(q, 0);
		forn(i, K)
			forn(j, K)
				forn(f, K)
					q[i][j] += a[i][f] * a[f][j];
		forn(i, K)
			forn(j, K)
				a[i][j] = q[i][j] % P;
		n >>= 1;
	}

	int ans = 0;
	forn(i, K)
	{
		int ok = 1;
		forn(j, m)
		{
			int tmp = 0;
			char c = value[0][j].fs;
			forn(f, div[c].size())
				if (value[i][j].sc % div[c][f] == 0) tmp = 1;
			ok &= tmp;
		}
		ans = (ans + ok * res[0][i]) % P;
	}
	cout << ans << endl;

	return 0;
}