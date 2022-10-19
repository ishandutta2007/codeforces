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


const int N = 2e5 + 30;
const int mod = 1000000007;
int n, m;
string s, t;
int a[27][N], sm;
int b[27];
int main()
{
	fastio;
	cin >> n >> s >> m;
	a[s[0] - 'a'][0]++;
	for (int i = 1; i < s.length(); i++)
	{
		for (int j = 0; j < 27; j++)
		{
			a[j][i] = a[j][i - 1];
		}
		a[s[i] - 'a'][i]++;
	}
	for (int i = 0; i < m; i++)
	{
		sm = 0;
		for (int j = 0; j < 27; j++)
		{
			b[j] = 0;
		}
		cin >> t;
		for (int j = 0; j < t.length(); j++)
		{
			b[t[j] - 'a']++;
		}
		for (int j = 0; j < 26; j++)
		{
			if (b[j])
				sm = max(sm, lower_bound(a[j], a[j] + s.length(), b[j]) - a[j]);
		}
		cout << sm + 1 << endl;
	}
	return 0;
}