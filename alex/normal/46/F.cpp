#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <cassert>
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
#define last(a) (a.size() - 1)

const string task = "";

int const NMAX = 2010;
int n, m, k, l[NMAX];
int x[NMAX], y[NMAX], num1[NMAX], num2[NMAX];
vector <int> keys1[NMAX], keys2[NMAX];
map <string, int> M;
bool open[NMAX], open1[NMAX];

int leader(int v)
{
	if (l[v] == v) return v;
	else return l[v] = leader(l[v]);
}

void unite(int v1, int v2)
{
	l[leader(v1)] = leader(v2);
}

void answer(const char *s)
{
	cout << s << endl;
	exit(0);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	forn(i, m)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i]--, y[i]--;
	}

	forn(i, k)
	{
		int q;
		char name[20];
		string tmp;
		scanf("%s%d%d", name, &num1[i], &q);
		tmp = name;
		num1[i]--;
		M[tmp] = i;
		forn(j, q)
		{
			int x;
			scanf("%d", &x);
			x--;
			keys1[i].pb(x);
		}
	}

	forn(i, k)
	{
		int q, W;
		char name[20];
		string tmp;
		scanf("%s%d%d", name, &W, &q);
		tmp = name;
		W--;
		forn(j, q)
		{
			int x;
			scanf("%d", &x);
			x--;
			keys2[M[tmp]].pb(x);
		}
		num2[M[tmp]] = W;
	}

	seta(open, 0);
	forn(i, n)
		l[i] = i;
	forn(i, NMAX)
	{
		bool flag = false;
		forn(j, k)
			forn(f, keys1[j].size())
				if (!open[keys1[j][f]] && leader(num1[j]) == leader(x[keys1[j][f]]) || leader(num1[j]) == leader(y[keys1[j][f]]))
				{
					flag = true;
					open[keys1[j][f]] = true;
					unite(x[keys1[j][f]], y[keys1[j][f]]);
				}
		if (!flag) break;
	}

	forn(i, m)
	{
		int v1 = -1, v2 = -1;
		forn(j, k)
			forn(f, keys1[j].size())
				if (keys1[j][f] == i) v1 = num1[j];
		forn(j, k)
			forn(f, keys2[j].size())
				if (keys2[j][f] == i) v2 = num2[j];
		assert(v1 != -1 && v2 != -1);
		if (leader(v1) != leader(v2))
			answer("NO");
	}
	forn(i, k)
		if (leader(num1[i]) != leader(num2[i])) answer("NO");
	forn(i, m)
		open1[i] = open[i];

	seta(open, 0);
	forn(i, n)
		l[i] = i;
	forn(i, NMAX)
	{
		bool flag = false;
		forn(j, k)
			forn(f, keys2[j].size())
				if (!open[keys2[j][f]] && leader(num2[j]) == leader(x[keys2[j][f]]) || leader(num2[j]) == leader(y[keys2[j][f]]))
				{
					flag = true;
					open[keys2[j][f]] = true;
					unite(x[keys2[j][f]], y[keys2[j][f]]);
				}
		if (!flag) break;
	}

	forn(i, m)
		if (open[i] != open1[i]) answer("NO");

	answer("YES");

	return 0;
}