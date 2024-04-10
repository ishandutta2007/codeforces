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

using namespace std;

const long long maxn = 4e5+5;

static long long parent[maxn], siz[maxn], Rank[maxn];

void make_set(int v) {
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
		swap(ll, rr);
	if (rr == 0)
		return ll;
	return gcd(ll%rr, rr);
}

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
static long long a[maxn], x[maxn], y[maxn], mas[maxn];
int main()
{
	//srand(time(0));
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m, flag;
	long long ans=0;
	cin >> n >> m;
	long long sumx = 0;
	long long sumy = 0;
	vector <pair <long long,long long>> z;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		sumx += x[i];
		sumy += y[i];
		z.push_back({ x[i] - y[i],i });
	}
	sort(z.begin(), z.end());
	long long sum1 = 0;
	long long sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum2 += y[z[i].second];
		mas[z[i].second] = (n - i - 1)*x[z[i].second] + i * y[z[i].second] + sumy - sum2 + sum1;
		sum1 += x[z[i].second];
	}
	for (int i = 0; i < m; i++)
	{
		long long u, v;
		cin >> u >> v;
		u--;
		v--;
		if (x[u] - y[u] < x[v] - y[v])
		{
			mas[u] -= x[u] + y[v];
			mas[v] -= x[u] + y[v];
		}
		else
		{
			mas[u] -= x[v] + y[u];
			mas[v] -= x[v] + y[u];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	return 0;
}