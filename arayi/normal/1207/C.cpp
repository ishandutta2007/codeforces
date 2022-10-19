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
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e6 + 30;
const lli mod = 1000000007;
int t, n, sm[N], h;
lli a, b, pat;
string s, s1;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		pat = 0;
		cin >> n >> a >> b >> s1;
		h = 1;
		s = '0';
		for (int i = 1; i < n; i++)
		{
			if (s1[i] == '1' || s1[i - 1] == '1')s += '1';
			else s += '0';
		}
		s += '0';
		sm[s.length() - 1] = -1;
		for (int i = s.length() - 2; i >= 0; i--)
		{
			sm[i] = sm[i + 1];
			if (s[i] == '1') sm[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			pat += h * b;
			if (h == 1 && s[i + 1] == '1') pat += a, h = 2;
			if (h == 2 && s[i + 1] == '0')
			{
				if (sm[i + 1] == -1 || ((sm[i + 1] - i - 1) * b) > (2 * a))
				{
					pat += a;
					h = 1;
				}
			}
			pat += a;
		//cout << pat << endl;
		}
		pat += b;
		cout << pat << endl;
		for (int i = 0; i < n; i++)
		{
			sm[i] = 0;
		}
	}
	return 0;
}