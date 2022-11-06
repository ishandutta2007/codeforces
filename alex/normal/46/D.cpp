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

const string task = "";

int const NMAX = 100010;
int L, l, r, n, cnt;
int used[NMAX];

void solve()
{
	cnt++;
	int tp, dl;
	scanf("%d%d", &tp, &dl);
	if (tp == 2)
	{
		forn(i, L)
			if (used[i] == dl) used[i] = 0;
		return;
	}

	int p = 0;
	while (p < L)
	{
		while (p < L && used[p] != 0)
			p++;
		if (p == L) break;
		int st = p;
		while (p < L && used[p] == 0)
			p++;

		int tmp = l + dl + r;
		if (st == 0) tmp -= l;
		if (p == L) tmp -= r;
		if (p - st >= tmp)
		{
			if (st != 0) st += l;
			cout << st << endl;
			forn(i, dl)
				used[st++] = cnt;
			return;
		}
	}
	cout << -1 << endl;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cnt = 0;
	cin >> L >> l >> r >> n;
	seta(used, 0);
	forn(i, n)
		solve();

	return 0;
}