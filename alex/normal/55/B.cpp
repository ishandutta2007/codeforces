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

int const n = 4;
vector <int64> a;
char op[n];
int64 best;

void rec(int p, vector <int64> a)
{
	if (p == 3)
	{
		best = min(best, a[0]);
		return;
	}

	vector <int64> b;
	forn(i, a.size())
		forn(j, i)
		{
			b.clear();
			forn(f, a.size())
				if (f != i && f != j) b.pb(a[f]);
			if (op[p] == '+') b.pb(a[i] + a[j]);
			else b.pb(a[i] * a[j]);
			rec(p + 1, b);
		}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	forn(i, 4)
	{
		int x;
		cin >> x;
		a.pb(x);
	}
	forn(i, 3)
		cin >> op[i];

	best = (int64) 1e18;
	rec(0, a);
	cout << best << endl;

	return 0;
}