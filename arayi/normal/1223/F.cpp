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



const int N = 3e5 + 30;
const lli mod = 1e9 + 7;

int q, n, a[N], par[N];
lli fp[N], pat;
map <int, int> sm[N];
struct el
{
	int val, par;

};

int l = 1;
el t[5 * N];
map <int, lli> g[5 * N];
void rec(int l1, int r)
{
	//cout << l << " " << r << " " << pat << endl;
	int mid = (l1 + r) / 2;
	stack <int> sm;
	sm.push(0);
	t[l].val = 0;
	int ll = l;
	int nw = l++;
	g[l].clear();
	for (int i = mid; i >= l1; i--)
	{
		if (sm.top() == a[i])
		{
			nw = t[nw].par;
			t[nw].val++;
			sm.pop();
		}
		else
		{
			sm.push(a[i]);
			if (g[nw][a[i]])
			{
				nw = g[nw][a[i]];
				t[nw].val++;
			}
			else
			{
				t[l].val = 1;
				t[l].par = nw;
				g[nw][a[i]] = l;
				nw = l++;
				g[l].clear();
			}
		}
	}
	while (!sm.empty()) sm.pop();
	nw = ll;
	sm.push(0);
	for (int i = mid + 1; i <= r; i++)
	{
		if (sm.top() == a[i])
		{
			nw = t[nw].par;
			pat += t[nw].val;
			sm.pop();
		}
		else
		{
			sm.push(a[i]);
			if (g[nw][a[i]])
			{
				nw = g[nw][a[i]];
				pat += t[nw].val;
			}
			else
			{
				i++;
				int i1 = sm.size() - 1;
				while (i <= r && sm.size() != i1)
				{
					if (sm.top() == a[i]) sm.pop();
					else sm.push(a[i]);
					i++;
				}
				i--;
				if (sm.size() == i1) pat += t[nw].val;
			}
		}
	}
	if (l1 < mid)
		rec(l1, mid);
	if (mid + 1 < r)
		rec(mid + 1, r);
}
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		pat = 0, fp[0] = 0;
		int nw = 0;
		stack <int> ss;
		sm[0].clear();
		cin >> n;
		int l = 1;
		fp[nw]++;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (!ss.empty() && ss.top() == a[i])
			{
				ss.pop();
				nw = par[nw];
			}
			else
			{
				if (sm[nw][a[i]]) nw = sm[nw][a[i]];
				else
				{
					sm[nw][a[i]] = l;
					sm[l].clear();
					par[l] = nw;
					fp[l] = 0;
					nw = l++;
				}
				ss.push(a[i]);
			}
			pat += fp[nw];
			fp[nw]++;
		}
		cout << pat << endl;
	}
	return 0;
}