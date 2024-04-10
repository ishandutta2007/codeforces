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
const lli mod = 998244353;
 
int t, n;
int sm[10], guyn[N], ss, sm1[10], ss1;
string s;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		for (int i = 0; i < 10; i++)
		{
			sm[i] = -1;
			sm1[i] = -1;
		}
		ss = 9;
		for (int i = 0; i < n; i++)
		{
			sm[s[i] - '0'] = i;
			ss = min(ss, s[i] - '0');
		}
		int a = 10;
		for (int i = 0; i < n; i++)
		{
			
			if (ss == s[i] - '0')
			{
				guyn[i] = 1;
				if (sm[ss] == i)
				{
					ss++;
					while (ss < 10 && (sm[ss] == -1 || sm[ss] < i))
					{
						ss++;
					}
				}
			}
			else
				a = min(a, s[i] - '0');
			if (ss > a) break;
		}
		ss1 = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (!guyn[i])
			{
				sm1[s[i] - '0'] = i;
				ss1 = max(ss1, s[i] - '0');
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (!guyn[i] && ss1 == s[i] - '0')
			{
				guyn[i] = 2;
				if (sm1[ss1] == i)
				{
					ss1--;
					while (ss1 >= 0 && (sm1[ss1] > i || sm1[ss1] == -1))
					{
						ss1--;
					}
				}
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (guyn[i] == 0)
			{
				cout << "-" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			for (int i = 0; i < n; i++)
			{
				cout << guyn[i];
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++) guyn[i] = 0;
	}
	return 0;
}