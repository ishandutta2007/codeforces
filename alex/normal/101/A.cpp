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

int n, k, cnt[1000], remove1[1000];
pii q[1000];
char s[100010];

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	cin >> k;

	seta(cnt, 0);
	forn(i, n)
		cnt[s[i]]++;

	for (char ch = 'a'; ch <= 'z'; ++ch)
		q[ch - 'a'] = mp(cnt[ch], ch);
	sort(q, q + 26);

	seta(remove1, 0);
	int ans = 26;
	forn(i, 26)
		if (k < q[i].fs)
			break;
		else k -=q[i].fs, ans--, remove1[q[i].sc] = 1;
	cout << ans << endl;

	forn(i, n)
		if (!remove1[s[i]]) printf("%c", s[i]);
	cout << endl;

	return 0;
}