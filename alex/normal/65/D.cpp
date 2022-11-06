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
#define fs first
#define sc second
#define x first
#define y second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

struct rec
{
	int a, b, c, d;
	rec() {}
	rec(int A, int B, int C, int D): a(A), b(B), c(C), d(D) {}
};

int n;
char s[10001];
set <rec> ans[2];
bool www[4];

bool operator <(const rec &a, const rec &b)
{
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	if (a.c != b.c) return a.c < b.c;
	if (a.d != b.d) return a.d < b.d;
	return 0;
}

void get_min(rec now)
{
	seta(www, 0);
	int q = min(min(now.a, now.b), min(now.c, now.d));
	if (now.a == q) www[0] = true;
	if (now.b == q) www[1] = true;
	if (now.c == q) www[2] = true;
	if (now.d == q) www[3] = true;
}

void calc(char c, rec now, int ind)
{
	if (c != '?')
	{
		if (c == 'G') now.a++;
		if (c == 'H') now.b++;
		if (c == 'R') now.c++;
		if (c == 'S') now.d++;
		ans[ind].insert(now);
		return;
	}

	get_min(now);
	rec tmp;
	forn(i, 4)
		if (www[i])
		{
			tmp = now;
			if (i == 0) tmp.a++;
			if (i == 1) tmp.b++;
			if (i == 2) tmp.c++;
			if (i == 3) tmp.d++;
			ans[ind].insert(tmp);
		}
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> s;
	ans[0].insert(rec(0, 0, 0, 0));
	forn(i, n)
	{
		int nxt = (i + 1) & 1, now = i & 1;
		ans[nxt].clear();
		for (set <rec> :: iterator it = ans[now].begin(); it != ans[now].end(); ++it)
			calc(s[i], *it, nxt);
	}

	bool may[4];
	seta(may, 0);
	for (set <rec> :: iterator it = ans[n & 1].begin(); it != ans[n & 1].end(); ++it)
	{
		get_min(*it);
		forn(i, 4)
			if (www[i]) may[i] = true;
	}
	if (may[0]) cout << "Gryffindor" << endl;
	if (may[1]) cout << "Hufflepuff" << endl;
	if (may[2]) cout << "Ravenclaw" << endl;
	if (may[3]) cout << "Slytherin" << endl;

	return 0;
}