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

int n;
lli a[N];
pair <int, int> b[N];
lli pat[N];
set <int> hj;
pair <lli, lli> mn[8 * N];
void build(int nl = 0, int nr = 2 * n - 1, int nd = 1)
{
	if (nl == nr)
	{
		mn[nd] = MP(a[nl], nl);
		return;
	}
	int mid = (nl + nr) / 2;
	build(nl, mid, 2 * nd);
	build(mid + 1, nr, 2 * nd + 1);
	mn[nd] = min(mn[2 * nd], mn[2 * nd + 1]);
}
lli query(int ql, int qr, int val, int nl = 0, int nr = 2 * n - 1, int nd = 1)
{
	if (qr < nl || ql > nr) return mod;
	if (nl == ql && nr == qr)
	{
		if (mn[nd].fr < val) return mn[nd].sc;
		else return mod;
	}
	int mid = (nl + nr) / 2;
	return min(query(ql, min(mid, qr), val, nl, mid, 2 * nd),
		query(max(ql, mid + 1), qr, val, mid + 1, nr, 2 * nd + 1));
}
int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
		b[i] = MP(a[i], i);
	}
	build();
	sort(b, b + n, greater<pair<int, int> >());
	for (int i = 0; i <= n; i++)
	{
		if (i == n) pat[b[0].sc] = mod, pat[b[0].sc + n] = mod;
		if (((b[0].fr + 1) / 2) > a[(i + b[0].sc) % n])
		{
			pat[b[0].sc] = i;
			pat[b[0].sc + n] = i;
			break;
		}
	}
	hj.insert(b[0].sc);
	hj.insert(b[0].sc + n);
	for (int i = 1; i < n; i++)
	{
		int sm = *hj.upper_bound(b[i].sc);
		lli ss = query(b[i].sc, sm - 1, (b[i].fr + 1) / 2);
		//cout << ss << endl;
		if (ss == mod) pat[b[i].sc] = sm - b[i].sc + pat[sm], pat[b[i].sc + n] = pat[b[i].sc];
		else
		{
			int l = b[i].sc, r = sm - 1, val = (b[i].fr + 1) / 2, ans;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (query(l, mid, val) != mod)
				{
					r = mid - 1;
					ans = mid;
				}
				else l = mid + 1;
			}
			pat[b[i].sc] = ans - b[i].sc, pat[b[i].sc + n] = pat[b[i].sc];
		}
		hj.insert(b[i].sc);
		hj.insert(b[i].sc + n);
	}
	for (int i = 0; i < n; i++)
	{
		if (pat[i] >= mod) cout << -1 << " ";
		else cout << pat[i] << " ";
	}
	return 0;
}