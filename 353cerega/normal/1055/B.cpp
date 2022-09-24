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
int n, m;
using namespace std;
const long long maxn = 2e5 + 5;
const long long mod = 1000000007;
static long long obrf[maxn], f[maxn];
static int parent[maxn], siz[maxn], Rank[maxn];
static long long aa[maxn];
static long long kek[maxn];
long long pew(long long a, long long step)
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
}

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

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	int n, m, l;
	cin >> n >> m >> l;

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> aa[i];
		if (aa[i] > l)
		{
			kek[i] = 1;
			ans++;
			if (i > 0 and kek[i - 1])
				ans--;
		}
	}
	for (int i = 0; i < m; i++)
	{
		long long t, p, d;
		cin >> t;
		if (t == 0)
		{
			cout << ans << endl;
		}
		else
		{
			cin >> p >> d;
			if (aa[p - 1] <= l and aa[p - 1]+d > l)
			{
				kek[p - 1] = 1;
				ans++;
				if (p > 1 and kek[p - 2])
				{
					ans--;
				}
				if (kek[p])
				{
					ans--;
				}
			}
			aa[p - 1] += d;
		}
	}
}