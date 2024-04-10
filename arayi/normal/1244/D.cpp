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
lli w[N][3];
vector <int> g[N];
vector <int> ss;
int nerk[6][N];
lli pat[6];
void dfs(int v, int par)
{
	ss.PB(v);
	for (auto p : g[v])
	{
		if (p == par)continue;
		dfs(p, v);
	}
	
}
int main()
{
	fastio;
	cin >> n;
	for (int j = 0; j < 3; j++)
		for (int i = 1; i <= n; i++)
			cin >> w[i][j];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);
	}
	int sm;
	for (int i = 1; i <= n; i++)
	{
		if (g[i].size() >= 3)
		{
			cout << -1;
			return 0;
		}
		if (g[i].size() == 1) sm = i;
	}
	int sm1 = g[sm][0];
	dfs(sm, -1);
	nerk[0][sm] = 0, nerk[0][sm1] = 1, pat[0] = w[sm][0] + w[sm1][1];
	nerk[1][sm] = 0, nerk[1][sm1] = 2, pat[1] = w[sm][0] + w[sm1][2];
	nerk[2][sm] = 1, nerk[2][sm1] = 0, pat[2] = w[sm][1] + w[sm1][0];
	nerk[3][sm] = 1, nerk[3][sm1] = 2, pat[3] = w[sm][1] + w[sm1][2];
	nerk[4][sm] = 2, nerk[4][sm1] = 0, pat[4] = w[sm][2] + w[sm1][0];
	nerk[5][sm] = 2, nerk[5][sm1] = 1, pat[5] = w[sm][2] + w[sm1][1];
	vector <pair<lli, int> > aa;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 2; j < ss.size(); j++)
		{
			//cout << ss[j] << " ";
			nerk[i][ss[j]] = 3 - nerk[i][ss[j - 1]] - nerk[i][ss[j - 2]];
			//cout << nerk[i][ss[j]] << " ";
			pat[i] += w[ss[j]][nerk[i][ss[j]]];
		}
		aa.PB(MP(pat[i], i));
	}
	sort(aa.begin(), aa.end());
	cout << aa[0].fr << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << nerk[aa[0].sc][i] + 1 << " ";
	}
	return 0;
}