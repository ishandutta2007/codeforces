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
#include <queue>
#include "stdlib.h"
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
}*/

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

long long mod = 1000000007;

/*long long mul(long long a, long long b)
{
	return (a*b) % mod;
}
long long sum(long long a, long long b)
{
	return (a + b) % mod;
}
long long sub(long long a, long long b)
{
	return (a - b + mod) % mod;
}

long long pew(long long a, long long b)
{
	if (b == 0)
	{
		return 1;
	}
	long long tmp = pew(a, b / 2);
	if (b % 2 == 0)
	{
		return mul(tmp, tmp);
	}
	else
	{
		return mul(mul(tmp, tmp), a);
	}
}*/

//vector<long long> pr, mind(20000001), phi(20000001);


/*long long check(long long n)
{
	if (n == 1)
	{
		return 0;
	}
	for (long long j = 0; pr[j]*pr[j] <= n; j++)
	{
		if (n%pr[j] == 0)
		{
			return 0;
		}
	}
	return 1;
}*/


/*vector<long long> mult(vector<long long> a, vector<long long> b)
{
	vector<long long> tmp(3999);
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			tmp[i + j] = sum(tmp[i + j], a[i] * b[j]);
		}
	}
	for (int i = 2000; i < 3999; i++)
	{
		tmp[i - 1999] = sum(tmp[i - 1999], tmp[i]);
		tmp[i - 2000] = sum(tmp[i - 2000], tmp[i]);
		tmp[i] = 0;
	}
	tmp.resize(2000);
	return tmp;
}*/


//long long cnt = 0, ans = 0;

long long L(long long a, long long p)
{
	if (a == 1)
	{
		return 1;
	}
	if (a % 2 == 0)
	{
		long long tmp = 1;
		if ((p*p - 1) / 8 % 2 == 1)
		{
			tmp = -1;
		}
		return L(a / 2, p)*tmp;
	}
	long long tmp = 1;
	if ((a - 1)*(p - 1) / 4 % 2 == 1)
	{
		tmp = -1;
	}
	return L(p%a, a)*tmp;
}
long long n, t[4000000];

void build(long long v, long long tl, long long tr) {
	if (tl == tr)
		t[v] = tl;
	else {
		long long tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

long long sum(long long v, long long tl, long long tr, long long l, long long r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	long long tm = (tl + tr) / 2;
	return sum(v * 2, tl, tm, l, min(r, tm))
		+ sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(long long v, long long tl, long long tr, long long pos, long long new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		long long tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

long long d6 = 1000LL * 1000;
long long d12 = 1000LL * 1000 * 1000 * 1000;
long long d18 = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
long long d11 = 1000LL * 1000 * 1000 * 100;



int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	cin >> n;
	vector<long long> kek(n);
	vector<long long> ans(n);
	for (int i = 0; i < n; i++)
	{
		cin >> kek[i];
	}
	build(1, 1, n);
	for (int i = n - 1; i >= 0; i--)
	{
		long long l = 0, r = n;
		while (r - l > 1)
		{
			long long m = (r + l) / 2;
			long long tmp = sum(1, 1, n, 1, m);
			if (tmp > kek[i])
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		ans[i] = r;
		update(1, 1, n, r, 0);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}