#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

using namespace std;

const int maxn = 4e5 + 5;
const long long mod = 1e9 + 7;
int parent[maxn];
int ranks[maxn];
static long long s[maxn];
static long long f[maxn];
static long long c[maxn];
static long long a[maxn], b[maxn], mincost[maxn];
long long ans = 0;

void QSort(int l, int r)
{
	int ee = l;
	int ff = r;
	long long q = c[(l + r) / 2];
	while (ee <= ff)
	{
		while (c[ee] < q) ee++;
		while (c[ff] > q) ff--;
		if (ee <= ff)
		{
			swap(c[ee], c[ff]);
			swap(s[ee], s[ff]);
			swap(f[ee], f[ff]);
			ee++;
			ff--;
		}
	}
	if (ff > l) QSort(l, ff);
	if (ee < r) QSort(ee, r);
}

void make_set(int v) {
	parent[v] = v;

	ranks[v] = 0;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int aa, int bb, long long cnt) {
	aa = find_set(aa);
	bb = find_set(bb);
	if (aa != bb) {
		if (ranks[aa] < ranks[bb])
			swap(aa, bb);
		a[aa] = max(max(a[aa], a[bb]), cnt);
		mincost[aa] = min(mincost[aa], mincost[bb]);
		b[aa] += b[bb];
		if (b[aa] > a[aa]*mincost[aa])
		{
			ans -= b[aa] - a[aa]*mincost[aa];
			b[aa] = a[aa]*mincost[aa];
		}
		parent[bb] = aa;
		if (ranks[aa] == ranks[bb])
			ranks[aa]++;
	}
}
int main()
{
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int x, y, z, t1, t2, t3, T1, T2;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	T1 = abs(x - y)*t1;
	T2 = (abs(x - z) + abs(x - y))*t2 + 3 * t3;
	if (T2 <= T1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}