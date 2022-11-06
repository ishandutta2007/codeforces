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

const string name = "d";

const int NMAX = 300010;
const int k = 300;

int n, m, w[NMAX];
int64 answer[NMAX], get[NMAX];
pair <pii, int> q[NMAX];

void pre_calc(int zn)
{
	for (int i = n - 1; i >= 0; --i)
	{
		get[i] = w[i];
		if (i + zn < n) get[i] += get[i + zn];
	}
}

int64 calc(int a, int b)
{
	int64 res = 0;
	while (a < n)
	{
		res += w[a];
		a += b;
	}
	return res;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

/*	cout << 300000 << endl;
	forn(i, 300000)
		cout << 1000000000 << " ";
	cout << endl;
	cout << 300000 << endl;
	forn(i, 300000)
		cout << 1 << " " << 1 << endl;
	return 0;*/

	cin >> n;
	forn(i, n)
		scanf("%d", &w[i]);

	cin >> m;
	forn(i, m)
	{
		scanf("%d%d", &q[i].fs.sc, &q[i].fs.fs);
		q[i].fs.sc--;
		q[i].sc = i;
	}
	sort(q, q + m);

	int now = 0;
	forn(i, k)
	{
		pre_calc(i + 1);
		while (now < m && q[now].fs.fs == i + 1)
		{
			answer[q[now].sc] = get[q[now].fs.sc];
			now++;
		}
	}
	while (now < m)
	{
		answer[q[now].sc] = calc(q[now].fs.sc, q[now].fs.fs);
		now++;
	}

	forn(i, m)
		printf("%I64d\n", answer[i]);
	//cerr << clock() << endl;

	return 0;
}