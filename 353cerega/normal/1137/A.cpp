#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
#include <map>
#include <string>
#include <ctime>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <bitset>
using namespace std;

/*long long pew(long long a, long long step)
{
if (step == 0)
{
return 1;
}
long long b = pew((a*a) % mod, step / 2);
if (step % 2 == 0)
{
return b;
}
else
{
return (b*a) % mod;
}
}

void precal(int cnt)
{
long long tmp = 1;
f[0] = 1;
obrf[0] = 1;
for (int i = 1; i <= cnt; i++)
{
tmp *= i;
tmp %= mod;
f[i] = tmp;
obrf[i] = pew(tmp, mod - 2);
}
}*/

/*void make_set(int v) {
parent[v] = v;
Rank[v] = 0;
siz[v] = 1;
}

int find_set(int v) {
if (v == parent[v])
return v;
return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
a = find_set(a);
b = find_set(b);
if (a != b) {
if (Rank[a] < Rank[b])
swap(a, b);
parent[b] = a;
siz[a] += siz[b];
if (Rank[a] == Rank[b])
++Rank[a];
}
}
/*long long gcd(long long ll, long long rr)
{
if (ll < rr)
return gcd(rr, ll);
if (rr == 0)
return ll;
return gcd(ll%rr, rr);
}*/

/*void QSort(int ll, int rr)
{
int ee = ll;
int ff = rr;

long long q = rand();
q = c[ll+q%(rr-ll+1)];
while (ee <= ff)
{
while (c[ee] < q) ee++;
while (c[ff] > q) ff--;
if (ee <= ff)
{
swap(c[ee], c[ff]);
swap(s[ee], s[ff]);
ee++;
ff--;
}
}
if (ff > ll) QSort(ll, ff);
if (ee < rr) QSort(ee, rr);
}*/

long long gcd(long long a, long long b)
{
	if (a < b)
	{
		return gcd(b, a);
	}
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(a%b, b);
	}
}

const long long p1 = 31;
const long long p2 = 29;
vector<long long> p1_pow(600000);
vector<long long> p2_pow(600000);

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> a(n), b1(n), b2(n), c1(n), c2(n);
	vector<pair<long long,long long>> q;
	for (int i = 0; i < n; i++)
	{
		a[i].resize(m);
		b1[i].resize(m);
		b2[i].resize(m);
		c1[i].resize(m);
		c2[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			q.push_back({ a[i][j], j });
		}

		sort(q.begin(), q.end());
		long long cur = 1;
		for (int j = 0; j < m; j++)
		{
			b1[i][q[j].second] = cur - 1;
			if (j != m - 1 and q[j].first != q[j + 1].first)
			{
				cur++;
			}
		}
		for (int j = 0; j < m; j++)
		{
			b2[i][j] = cur - 1 - b1[i][j];
		}
		q.clear();
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			q.push_back({ a[i][j], i });
		}
		sort(q.begin(), q.end());
		long long cur = 1;
		for (int i = 0; i < n; i++)
		{
			c1[q[i].second][j] = cur - 1;
			if (i != n - 1 and q[i].first != q[i + 1].first)
			{
				cur++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			c2[i][j] = cur - 1 - c1[i][j];
		}
		q.clear();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			long long ans = max(b1[i][j], c1[i][j]) + max(b2[i][j], c2[i][j]) + 1;
			cout << ans << " ";
		}
		cout << endl;
	}

	/*string s, t;
	getline(cin, s);
	getline(cin, t);
	p1_pow[0] = 1;
	p2_pow[0] = 1;
	for (size_t i = 1; i<p1_pow.size(); ++i)
		p1_pow[i] = p1_pow[i - 1] * p1;
	for (size_t i = 1; i<p2_pow.size(); ++i)
		p2_pow[i] = p2_pow[i - 1] * p2;
	vector<long long> h1(t.length());
	vector<long long> h2(t.length());
	for (size_t i = 0; i<t.length(); ++i)
	{
		h1[i] = (t[i] - '0' + 1) * p1_pow[i];
		h2[i] = (t[i] - '0' + 1) * p2_pow[i];
		if (i)  h1[i] += h1[i - 1];
		if (i)  h2[i] += h2[i - 1];
	}
	long long len = t.length();
	for (int i = 1; i < t.length(); i++)
	{
		long long h11 = h1[t.length() - 1];
		if (i) h11 -= h1[i - 1];
		long long h21 = h1[t.length() - i - 1];
		long long h12 = h2[t.length() - 1];
		if (i) h12 -= h2[i - 1];
		long long h22 = h2[t.length() - i - 1];
		if (h21*p1_pow[i] == h11 and h22*p2_pow[i] == h12)
		{
			len = i;
			break;
		}
	}
	long long a1 = 0, b1 = 0, a2 = 0, b2 = 0, a=0, b=0;
	string kek = "";
	for (int i = 0; i < len; i++)
	{
		if (t[i] == '0')
		{
			a1++;
		}
		else
		{
			b1++;
		}
		kek += t[i];
	}
	for (int i = 0; i < t.length(); i++)
	{
		if (t[i] == '0')
		{
			a2++;
		}
		else
		{
			b2++;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			a++;
		}
		else
		{
			b++;
		}
	}
	if (a2 > a or b2 > b)
	{
		cout << s << endl;
		return 0;
	}
	string ans = t;
	a -= a2;
	b -= b2;
	while (a >= a1 and b >= b1)
	{
		a -= a1;
		b -= b1;
		ans += kek;
	}
	while (a > 0)
	{
		a--;
		ans += '0';
	}
	while (b > 0)
	{
		b--;
		ans += '1';
	}
	cout << ans << endl;*/
}