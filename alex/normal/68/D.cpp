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

const string name = "d";

int h, q;
map <int, int> num;

void update(int x, int zn)
{
	if (x < 1) return;
	if (num.count(x)) num[x] += zn;
	else num[x] = zn;
	update(x >> 1, zn);
}

double find(int v, int h, int _max)
{
	if (!num.count(v)) return 0;
	int l = 0, r = 0, now = num[v];
	if (num.count(2 * v)) l = num[2 * v];
	if (num.count(2 * v + 1)) r = num[2 * v + 1];

	if (_max >= max(l, r) + now - l - r) return (double) _max / (1 << (h - 1));
	if (l == 0 && r == 0) return (double) now / (1 << (h - 1));
	_max = max(_max, now - max(l, r));

	if (l < r) return (double) (now - l) / (1 << h) + find(2 * v + 1, h + 1, _max);
	else return (double) (now - r) / (1 << h) + find(2 * v, h + 1, _max);
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> h >> q;
	forn(i, q)
	{
		char tmp[10];
		scanf("%s", tmp);
		if (tmp[0] == 'd')
			printf("%.8lf\n", find(1, 1, 0));
		else
		{
			int x, z;
			scanf("%d%d", &x, &z);
			update(x, z);
		}
	}

	return 0;
}