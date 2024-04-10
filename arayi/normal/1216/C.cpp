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
int dx[] = { 2, 2, 1, -1, -2, -2, 1, -1 };
int dy[] = { 1, -1, 2, 2, 1, -1, -2, -2 };



const int N = 1e6 + 30;
const lli mod = 1e18 + 1;
pair <int, int> a[N];
lli x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
lli s1, s2, s3;
int main()
{
	fastio;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	if (x1 >= x3 && x2 <= x4 && y3 <= y1 && y4 >= y2)
		cout << "NO";
	else
	{
		if (x1 >= x3 && x2 <= x4 && y3 <= y1) y1 = max(y1, y4);
		if (x1 >= x3 && x2 <= x4 && y4 >= y2) y2 = min(y2, y3);
		if (x1 >= x3 && y3 <= y1 && y4 >= y2) x1 = max(x1, x4);
		if (x4 >= x2 && y3 <= y1 && y4 >= y2) x2 = min(x2, x3);
		if (x5 <= x1 && x6 >= x2 && y5 <= y1 && y6 >= y2) cout << "NO";
		else cout << "YES";
	}

	return 0;
}