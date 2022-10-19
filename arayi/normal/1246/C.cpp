#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 2020;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 150;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

int n, m;
int a[N][N];
vector <int> b[N], c[N];
lli dp[N][N][2];
int qan(int x1, int y1, int x2, int y2)
{
	int ret = 0;
	/*ret = pr[x2][y2];
	if (x1) ret -= pr[x1 - 1][y2];
	if (y1) ret -= pr[x2][y1 - 1];
	if (x1 && y1) ret += pr[x1 - 1][y1 - 1];*/
	return ret;
}
void tp()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dp[i][j][0] << dp[i][j][1] << " ";
		}
		cout << endl;
	}
}
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char A;
			cin >> A;
			if (A == 'R') a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (a[i][j]) b[i].PB(j);
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i][j]) c[j].PB(i);
		}
	}
	dp[0][0][0] = dp[0][0][1] = 1;
	for (int j = 1; j < m; j++)
	{
		if (b[0].size() < m - j) dp[0][j][0] = 1;
		//dp[0][j][0] += dp[0][j - 1][0];
		dp[0][j][1] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (c[0].size() < n - i) dp[i][0][1] = 1;
		//dp[i][0][1] += dp[i - 1][0][1];
		dp[i][0][0] = 1;
	}
	//tp();
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int sm = m - j - 1;
			if (b[i].size() <= sm) dp[i][j][0] += dp[i][j - 1][1], dp[i][j][0] %= mod;
			else if (b[i][sm] == j) dp[i][j][0] = 0;
			else if (b[i][sm] == 0) dp[i][j][0] += dp[i][j - 1][1];
			else
			{
				lli ss = dp[i][j - 1][1] - dp[i][b[i][sm] - 1][1];
				ss %= mod;
				if (ss < 0) ss += mod;
				dp[i][j][0] = ss;
			}
			dp[i][j][0] += dp[i - 1][j][0];
			dp[i][j][0] %= mod;
			sm = n - i - 1;
			if (c[j].size() <= sm) dp[i][j][1] += dp[i - 1][j][0];
			else if (c[j][sm] == i) dp[i][j][1] = 0;
			else if (c[j][sm] == 0) dp[i][j][1] = dp[i - 1][j][0];
			else
			{
				lli ss = dp[i - 1][j][0] - dp[c[j][sm] - 1][j][0];
				ss %= mod;
				if (ss < 0) ss += mod;
				dp[i][j][1] = ss;
			}
			dp[i][j][1] += dp[i][j - 1][1];
			dp[i][j][1] %= mod;
		}
	}
	//tp();
	if (n == 1 && m == 1) cout << 1;
	else if (n == 1) cout << (b[0].size() == 0);
	else if (m == 1) cout << (c[0].size() == 0);
	else
	{
		lli ans = (dp[n - 1][m - 1][0] - dp[n - 2][m - 1][0]) + (dp[n - 1][m - 1][1] - dp[n - 1][m - 2][1]);
		ans %= mod;
		if (ans < 0) ans += mod;
		cout << ans << endl;
	}
	return 0;
}