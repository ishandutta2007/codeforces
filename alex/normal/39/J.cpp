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

char s1[1000010], s2[1000010];
int n;
bool s[1000010], p[1000010];
vector <int> ans;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s%s", s1, s2);
	n = strlen(s2);

	seta(p, 0);
	int now = 0;
	while (now < n && s1[now] == s2[now])
		p[now++] = true;

	seta(s, 0);
	now = n;
	while (now > 0 && s1[now] == s2[now - 1])
		s[now--] = true;

	forn(i, n + 1)
		if ((i == 0 || p[i - 1]) && (i == n || s[i + 1])) ans.pb(i + 1);
	cout << ans.size() << endl;
	forn(i, ans.size())
		cout << ans[i] << " ";

	return 0;
}