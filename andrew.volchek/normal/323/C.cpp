#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

const int maxn = 1000005;

vector < int > tree[4 * maxn];
int p1[maxn];
int p2[maxn];

void build(int v, int l, int r)
{
	if (l == r)
	{
		tree[v].pb(p1[l]);
		return;
	}
	
	int c = (r + l) / 2;
	
	build(2*v, l, c);
	build(2*v+1, c+1, r);
	
	tree[v].resize(r - l + 1);
	merge(tree[2*v].begin(), tree[2*v].end(),
		  tree[2*v+1].begin(), tree[2*v+1].end(),
		  tree[v].begin());
}

int ql, qr, qi, qj;
int res;

void query(int v, int l, int r)
{
	if (ql <= l && r <= qr)
	{
		vector < int > :: iterator it1, it2;
		it1 = lower_bound(tree[v].begin(), tree[v].end(), qi);
		it2 = upper_bound(tree[v].begin(), tree[v].end(), qj);
		
		res += it2 - it1;
		
		return;
	}
	
	int c = (l + r) / 2;
	
	if (ql <= c)
		query(2*v, l, c);
		
	if (c < qr)
		query(2*v+1, c+1, r);
}

int x = 0;
int n, m;

int func(int v)
{
	int t = (v - 1 + x);
	t %= n;
	return t + 1;
}

int main(int argc, char **argv)
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", p1+i);
	
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		p2[x] = i;
	}
	
	for (int i = 1; i <= n; i++)
		p1[i] = p2[p1[i]];
		
	build(1, 1, n);
	
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		ql = min(func(a), func(b));
		qr = max(func(a), func(b));
		qi = min(func(c), func(d));
		qj = max(func(c), func(d));
		res = 0;
		query(1, 1, n);
		x = res+1;
		printf("%d\n", res);
	}
	
	return 0;
}