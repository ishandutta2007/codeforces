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

const string name = "a";

int n, used[200010];
char s[200010];
vector <int> st;

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	scanf("%s", s);
	n = strlen(s);

	st.clear();
	seta(used, 0);
	forn(i, n)
	{
		if (st.size() > 0 && s[st[st.size() - 1]] == s[i])
		{
			used[i] = used[st[st.size() - 1]] = true;
			st.pop_back();
		}
		else st.push_back(i);
	}
	forn(i, n)
		if (!used[i]) printf("%c", s[i]);

	return 0;
}