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

int const NMAX = 100500;

int n, num, s;
map <int, int> M;
char op[NMAX];
int a[NMAX], zn[NMAX], l[NMAX], r[NMAX], used[NMAX];
int64 sum[NMAX][6];

int main()
{ 
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	s = (int) sqrt(n + 1e-5);
	num = 0;
	forn(i, n)
	{
		char tmp[5];
		scanf("%s", tmp);
		op[i] = tmp[0];
		if (op[i] != 's')
		{
			scanf("%d", &zn[i]);
			a[num++] = zn[i];
		}
	}
	sort(a, a + num);
	num = unique(a, a + num) - a;

	seta(sum, 0);

	forn(i, num)
	{
		M[a[i]] = i;
		l[i] = i * s;
		r[i] = (i + 1) * s - 1;
	}

	int ss = n / s + 1;
	seta(used, 0);
	forn(i, n)
	{
		if (op[i] == 's')
		{
			int now = 2;
			int64 res = 0;
			forn(j, ss)
			{
				res += sum[j][now];
				now -= (int) sum[j][5];
				now = (5 * n + now) % 5;
			}
			printf("%I64d\n", res);
		}
		if (op[i] == 'a')
		{
			int pos = M[zn[i]];
			int block = pos / s;
			sum[block][5]++;
			int st = 0;
			for (int j = l[block]; j < pos; ++j)
				if (used[j]) st++;
			st = st % 5;
			int tmp = st;
			for (int j = pos; j <= r[block]; ++j)
				if (used[j])
				{
					sum[block][tmp] -= a[j];
					tmp++;
					if (tmp == 5) tmp = 0;
					sum[block][tmp] += a[j];
				}
			used[pos] = 1;
			sum[block][st] += zn[i];
		}
		if (op[i] == 'd')
		{
			int pos = M[zn[i]];
			int block = pos / s;
			sum[block][5]--;
			int st = 0;
			for (int j = l[block]; j < pos; ++j)
				if (used[j]) st++;
			st = st % 5;
			int tmp = (st + 1) % 5;
			for (int j = pos + 1; j <= r[block]; ++j)
				if (used[j])
				{
					sum[block][tmp] -= a[j];
					sum[block][(tmp + 4) % 5] += a[j];
					tmp++;
					if (tmp == 5) tmp = 0;
				}
			used[pos] = 0;
			sum[block][st] -= zn[i];
		}
	}

	return 0;
}