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

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	
	string s, t;
	getline(cin, s);
	getline(cin, t);
	vector<int> keks = prefix_function(t);
	long long len = t.length() - keks[t.length() - 1];
	long long a1 = 0, b1 = 0, a2 = 0, b2 = 0, a=0, b=0;
	string kek = "";
	for (int i = t.length()-len; i < t.length(); i++)
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
	cout << ans << endl;
}