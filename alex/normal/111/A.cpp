#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define next NEXT
#define prev PREV
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
#define y1 botva

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
int64 ans[100010];
int64 x, y;

int main ()
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	cin >> n >> x >> y;
	if (y < n)
	{
		cout << -1 << endl;
		return 0;
	}
	forn(i, n)
		ans[i] = 1;
	ans[0] = y - n + 1;

	int64 res = 0;
	forn(i, n)
		res += (long long) ans[i] * ans[i];
	if (res < x)
	{
		cout << -1 << endl;
		return 0;
	}
	forn(i, n)
		printf("%d ", ans[i]);

	return 0;
}