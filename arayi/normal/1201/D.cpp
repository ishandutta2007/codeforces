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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
using namespace std;

lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
lli cg(lli n) {
	return n ^ (n >> 1);
}
lli SUM(lli a)
{
	return (a * (a + 1) / 2);
}
bool CAN(int x, int y, int n, int m)
{
	if (x >= 0 && y >= 0 && x < n && y < m) 
	{
		return true;
	}
	return false;
}
double her(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
string strsum(string a, string b)
{
	int p = 0;
	string c;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (b.length() < a.length())
	{
		for (int i = b.length(); i < a.length(); i++)
		{
			b += "0";
		}
	}
	else
	{
		for (int i = a.length(); i < b.length(); i++)
		{
			a += "0";
		}
	}
	
	a += "0", b += "0";
	for (int i = 0; i < a.length(); i++)
	{
		c += (a[i] - '0' + b[i] - '0' + p) % 10 + '0';
		p = (a[i] + b[i] - '0' - '0' + p) / 10;
	}
	if (c[c.length() - 1] == '0') c.erase(c.length() - 1, 1);
	reverse(c.begin(), c.end());
	return c;
}
string strmin(string a, string b)
{
	if (a.length() > b.length()) return b;
	if (b.length() > a.length()) return a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] > b[i]) return b;
		if (b[i] > a[i]) return a;
	}
	return a;
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };




const int N = 2e6 + 30;
const int mod = 1000000007;
lli max(lli a, lli b)
{
	if (a > b) return a;
	return b;
}
lli min(lli a, lli b)
{
	if (a < b) return a;
	return b;
}
int n, m, k, q;
lli a[N][2], dp[N][2], c[N][2], sm;
lli pat;
bool can[N], col[N];
int main()
{
	fastio;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		col[r] = true;
		if (a[r][0]) a[r][0] = min(a[r][0], c);
		else a[r][0] = c;
		if (a[r][1]) a[r][1] = max(a[r][1], c);
		else a[r][1] = c;
	}
	for (int i = 0; i < q; i++)
	{
		int b;
		cin >> b;
		can[b] = true;
	}
	sm = -3LL * m;
	for (int i = 1; i <= m; i++)
	{
		if (can[i]) sm = i;
		c[i][0] = sm;
	}
	sm = 3LL * m;
	for (int i = m; i > 0; i--)
	{
		if (can[i]) sm = i;
		c[i][1] = sm;
	}
	if (!col[1]) a[1][0] = 1, a[1][1] = 1;
	dp[1][1] = a[1][1] - 1;
	dp[1][0] = dp[1][1] + a[1][1] - a[1][0];
	//cout << dp[1][0] << " " << dp[1][1] << endl;
	sm = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!col[i]) {
			sm++;
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			a[i][0] = a[i - 1][0];
			a[i][1] = a[i - 1][1];
			continue;
		}
		else
		{
			dp[i][0] = dp[i - 1][0] + (a[i - 1][0] - c[a[i - 1][0]][0]) + 1 + sm + abs(a[i][1] - c[a[i - 1][0]][0]) + a[i][1] - a[i][0]; 
			dp[i][0] = min(dp[i][0], dp[i - 1][0] + (c[a[i - 1][0]][1] - a[i - 1][0]) + 1 + sm + abs(a[i][1] - c[a[i - 1][0]][1]) + a[i][1] - a[i][0]);
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + (a[i - 1][1] - c[a[i - 1][1]][0]) + 1 + sm + abs(a[i][1] - c[a[i - 1][1]][0]) + a[i][1] - a[i][0]);
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + (c[a[i - 1][1]][1] - a[i - 1][1]) + 1 + sm + abs(a[i][1] - c[a[i - 1][1]][1]) + a[i][1] - a[i][0]);
			dp[i][1] = dp[i - 1][0] + (a[i - 1][0] - c[a[i - 1][0]][0]) + 1 + sm + abs(a[i][0] - c[a[i - 1][0]][0]) + a[i][1] - a[i][0];
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + (c[a[i - 1][0]][1] - a[i - 1][0]) + 1 + sm + abs(a[i][0] - c[a[i - 1][0]][1]) + a[i][1] - a[i][0]);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + (a[i - 1][1] - c[a[i - 1][1]][0]) + 1 + sm + abs(a[i][0] - c[a[i - 1][1]][0]) + a[i][1] - a[i][0]);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + (c[a[i - 1][1]][1] - a[i - 1][1]) + 1 + sm + abs(a[i][0] - c[a[i - 1][1]][1]) + a[i][1] - a[i][0]);
			sm = 0;
		}
		//cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	pat = min(dp[n][0], dp[n][1]);
	cout << pat;
	return 0;
}