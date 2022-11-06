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

const string name = "c";

map <string, int> M;
string a, b, c;
int aa, bb, cc;

int dist(int x, int y)
{
	return (y - x + 12) % 12;
}

void solve(int a, int b, int c)
{
	if (dist(a, b) == 3 && dist(b, c) == 4)
	{
		cout << "minor" << endl;
		exit(0);
	}
	if (dist(a, b) == 4 && dist(b, c) == 3)
	{
		cout << "major" << endl;
		exit(0);
	}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	M["C"] = 0;
	M["C#"] = 1;
	M["D"] = 2;
	M["D#"] = 3;
	M["E"] = 4;
	M["F"] = 5;
	M["F#"] = 6;
	M["G"] = 7;
	M["G#"] = 8;
	M["A"] = 9;
	M["B"] = 10;
	M["H"] = 11;
	cin >> a >> b >> c;
	aa = M[a];
	bb = M[b];
	cc = M[c];
	solve(aa, bb, cc);
	solve(aa, cc, bb);
	solve(bb, aa, cc);
	solve(bb, cc, aa);
	solve(cc, aa, bb);
	solve(cc, bb, aa);
	cout << "strange" << endl;

	return 0;
}