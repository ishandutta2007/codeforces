#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "c";

template <class T> T sqr (T x) {return x * x;}

int n, m, x, y;
int64 ans;

pii calc(int r, int p)
{
	if (r == 0) return mp(10, -10);
	int now = max(0, r - p);
	int L = abs(p - r) + 1;
	int R = min(r + p - 1, n);
/*	int per = R - L + 1;

	if (per == 0) ans++;
	if (now > 0)
		ans += 2 * per + 1;
	else
		ans += 2 * per;*/
	return mp(L, R);
}

int main ()
{
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);

	cin >> n >> x;
	cin >> m >> y;

	if (n < m)
	{
		swap(n, m);
		swap(x, y);
	}
	ans = n + 1;
	forn(i, m)
	{
		pii tmp = calc(i, abs(x - y));
		int l1 = tmp.fs, r1 = tmp.sc;
		r1++;
		tmp = calc(i + 1, abs(x - y));
		int l2 = tmp.fs, r2 = tmp.sc;
//		cerr << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
		if (l2 <= r2) ans += r2 - l2 + 1;
		l2 = max(l1, l2);
		r2 = min(r1, r2);
		if (l2 <= r2) ans += r2 - l2 + 1;
		ans++;
	}

	cout << ans << endl;

	return 0;
}