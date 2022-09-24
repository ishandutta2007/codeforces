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
long long gcd(long long ll, long long rr)
{
if (ll < rr)
return gcd(rr, ll);
if (rr == 0)
return ll;
return gcd(ll%rr, rr);
}
*/
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
vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i<n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
vector<int> z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i<n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
const long long maxn = 1e6 + 100;
static long long w[maxn], c[maxn], a[maxn], b[maxn], N[20], r[maxn], q[maxn];
const long long INF = 1e18;
int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("a1.in", "r", stdin);
//	freopen("a1.out", "w", stdout);
	srand(time(0));
	string s, t;
	cin >> s;
	cin >> t;
	long long len = s.size();
	long long l = 0, r = 0;
	long long lent = t.size();
	if (s[0] != '0')
	{
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '0')
			{
				s[i] = '1';
			}
			else
			{
				s[i] = '0';
			}
		}
	}
	vector<int> posl, posr;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '0')
		{
			l++;
			posl.push_back(i);
		}
		else
		{
			r++;
			posr.push_back(i);
		}
	}
	string r0 = "";
	long long l1, l2;
	vector<int> kek = z_function(t);
	long long flag;
	long long ans = 0;
	const int p = 31;
	vector<long long> p_pow(t.length());
	p_pow[0] = 1;
	for (size_t i = 1; i<p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	//     
	vector<long long> h(t.length());
	for (size_t i = 0; i<t.length(); ++i)
	{
		h[i] = (t[i] - 'a' + 1) * p_pow[i];
		if (i)  h[i] += h[i - 1];
	}

	//    
	//  
	for (int i = 1; i <= lent; i++)
	{
		flag = 0;
		r0 += t[i - 1];
		q[t[i - 1] - 'a']-= l;
		l1 = i;
		if (i*l >= lent or (lent-i*l)%r!=0)
		{
			continue;
		}
		if (flag == 1)
		{
			continue;
		}
		l2 = (lent - i * l) / r;
		for (int j = 1; j < posl.size(); j++)
		{
			long long tmp = (posl[j] - j)*l2 + j * l1;
			if (kek[tmp] < i)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			continue;
		}
		if (l2 != l1 and r == 0)
		{
			ans++;
			continue;
		}
		long long h1 = h[posr[0] * l1 + l2 - 1] - h[posr[0] * l1 - 1];
		long long i1 = posr[0] * l1;
		if ((l2 == l1) and (h1 == h[l2 - 1]*p_pow[i1]))
		{
			continue;
		}
		for (int j = 1; j < r; j++)
		{
			long long tmp = (posr[j] - j)*l1 + j * l2;
			long long h2 = h[tmp + l2 - 1] - h[tmp - 1];
			if (h1*p_pow[tmp-i1] != h2)
			{
				flag = 1;
			}
		}

		if (flag == 1)
		{
			continue;
		}
		ans++;
	}
	cout << ans;
}