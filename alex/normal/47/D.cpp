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
#define pii pair < long long, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int n, m;
char s[100];
set <pii> S;

void gen(long long mask, int num, int last)
{
	if (num == 0)
	{
		set <pii> :: iterator it = S.lower_bound(mp(mask, 0));
		if (it == S.end() || (*it).fs != mask) S.insert(mp(mask, 1));
		else
		{
			int num = (*it).sc;
			S.erase(it);
			S.insert(mp(mask, num + 1));
		}
		return;
	}
	if (last == n)
		return;
	gen(mask, num, last + 1);
	gen(mask ^ (1LL << last), num - 1, last + 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	S.clear();
	forn(i, m)
	{
		int num;
		cin >> s >> num;
		long long now = 0;
		forn(j, n)
			now = now * 2 + s[j] - '0';
		gen(now, num, 0);
	}

	int answer = 0;
	for (set <pii> :: iterator it = S.begin(); it != S.end(); it++)
		if ((*it).sc == m) answer++;
	cout << answer << endl;

	return 0;
}