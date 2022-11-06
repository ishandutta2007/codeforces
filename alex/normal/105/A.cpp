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

const string name = "a";

int n, m;
map<string, int> M;
double k;

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> m >> k;
	forn(i, n)
	{
		string s;
		int x;
		cin >> s >> x;
		x = (int) (k * x + 1e-7);
		if (x >= 100) M[s] = x;
	}

	forn(i, m)
	{
		string s;
		cin >> s;
		if (!M.count(s)) M[s] = 0;
	}

	cout << M.size() << endl;
	for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it)
		cout << it->fs << " " << it->sc << endl;

	return 0;
}