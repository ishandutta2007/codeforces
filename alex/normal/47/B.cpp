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

int cnt[1000];
char s[100];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	seta(cnt, 0);
	forn(it, 3)
	{
		cin >> s;
		if (s[1] == '<')
			cnt[s[2]]++;
		else
			cnt[s[0]]++;
	}
	if (cnt['A'] == 1 && cnt['B'] == 1 && cnt['C'] == 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	forn(i, 3)
		forn(ch, 3)
			if (cnt['A' + ch] == i) cout << (char) ('A' + ch);
	cout << endl;

	return 0;
}