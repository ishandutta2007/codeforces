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
const lli mod = 998244353;
int n, k, pat;
bool a[2010][2010], b[2010][2010], c[2010][2010];
int praj[2010][2010], prnq[2010][2010], prb[2010][2010], prc[2010][2010];
int main()
{
	fastio;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char A;
			cin >> A;
			if (A == 'W') a[i][j] = false;
			else a[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			praj[i][j] = praj[i][j - 1] + a[i][j];
			prnq[i][j] = prnq[i - 1][j] + a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (praj[i][j - 1] == 0 && (praj[i][n] - praj[i][min(n, j + k - 1)]) == 0 && praj[i][n]) b[i][j] = true;
			if (prnq[i - 1][j] == 0 && (prnq[n][j] - prnq[min(n, i + k - 1)][j]) == 0 && prnq[n][j]) c[i][j] = true;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			prc[i][j] = prc[i][j - 1] + c[i][j];
			prb[i][j] = prb[i - 1][j] + b[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			pat = max(pat, prc[i][min(n, j + k - 1)] - prc[i][j - 1] + prb[min(n, i + k - 1)][j] - prb[i - 1][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (praj[i][n] == 0) pat++;
		if (prnq[n][i] == 0) pat++;
	}
	cout << pat;
	return 0;
}