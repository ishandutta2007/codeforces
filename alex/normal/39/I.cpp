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

int const NMAX = 200010;
bool used[NMAX];
int n, m, H[NMAX], ans;
vector <int> g[NMAX], answer;

int gcd(int a, int b)
{
	if (a == 0 || b == 0) return a + b;
	else return gcd(b, a % b);
}

void dfs(int v, int h)
{
	used[v] = true;
	H[v] = h;
	if (g[v].size() == 0) ans = 1;
	forn(i, g[v].size())
		if (!used[g[v][i]])
			dfs(g[v][i], h + 1);
		else
		{
			if (ans == -1) ans = abs(h - H[g[v][i]] + 1);
			else ans = gcd(ans, abs(h - H[g[v][i]] + 1));
		}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].pb(y);
	}

	ans = -1;
	seta(used, 0);
	dfs(0, 0);

	cout << ans << endl;
	forn(i, n)
		if (used[i] && H[i] % ans == 0)
			answer.pb(i);
	cout << answer.size() << endl;
	sort(all(answer));
	forn(i, answer.size())
		printf("%d ", answer[i] + 1);

	return 0;
}