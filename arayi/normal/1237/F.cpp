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
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
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



const int N = 4000;
const lli mod = 998244353;

lli fa[N], a[N][N], c[N][N];
int w, h, n;
bool colx[N], coly[N];
lli dp1[N][N], dp2[N][N], pat;
int az1, az2;
int main() {
	fastio;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		colx[x] = true;
		coly[y] = true;
		cin >> x >> y;
		colx[x] = true;
		coly[y] = true;
	}
	dp1[0][0] = 1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			if (i < h - 1 && !colx[i + 1] && !colx[i + 2])
			{
				dp1[i + 2][j + 1] += dp1[i][j];
				dp1[i + 2][j + 1] %= mod;
			}
			dp1[i + 1][j] += dp1[i][j];
			dp1[i + 1][j] %= mod;
		}
	}
	for (int i = 1; i <= h; i++)
	{
		if (!colx[i]) az1++;
	}
	for (int i = 1; i <= w; i++)
	{
		if (!coly[i]) az2++;
	}
	dp2[0][0] = 1;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (i < w - 1 && !coly[i + 1] && !coly[i + 2])
			{
				dp2[i + 2][j + 1] += dp2[i][j];
				dp2[i + 2][j + 1] %= mod;
			}
			dp2[i + 1][j] += dp2[i][j];
			dp2[i + 1][j] %= mod;
		}
	}
	fa[0] = 1;
	for (int i = 1; i < N; i++) {
		fa[i] = fa[i - 1] * i % mod;
	}
	c[0][0] = 1;
	a[0][0] = 1;
	for (int i = 1; i < N; i++) {
		c[i][0] = 1;
		a[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			a[i][j] = c[i][j] * fa[j] % mod;
		}
	}
	for (int i = 0; 2 * i <= az1; i++)
	{
		for (int j = 0; 2 * j <= az2; j++)
		{
			//dp1[h][i], dp2[w][j]	
			lli sm1 = (dp1[h][i] * a[az1 - 2 * i][j]) % mod;
			lli sm2 = (dp2[w][j] * a[az2 - 2 * j][i]) % mod;
			pat += sm1 * sm2;
			pat %= mod;
		}
	}
	cout << pat;
	return 0;
}