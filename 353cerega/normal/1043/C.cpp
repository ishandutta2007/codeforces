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
static long long a[maxn], mas[maxn];
int main()
{
//	srand(time(0));
//	freopen("a1.in", "r", stdin);
//	freopen("a1.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s;
	int n, flag;
	getline(cin, s);
	flag = 0;
	n = s.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if ((flag == 0 and s[i] == 'a') or (flag==1 and s[i]=='b'))
		{
			mas[i] = 1;
			flag = 1 - flag;
		}
		else
		{
			mas[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	return 0;
}