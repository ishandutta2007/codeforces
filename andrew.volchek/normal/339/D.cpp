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
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

const int maxn = 231072;
int tree[maxn*4];

int arr[maxn];

void build(int v, int l, int r, int depth)
{
	if (l == r)
	{
		tree[v] = arr[l-1];
		return;
	}
	
	int c = (l + r) / 2;
	
	build(v*2, l, c, depth-1);
	build(v*2+1, c+1, r, depth-1);
	
	if (depth & 1)
		tree[v] = tree[2*v] | tree[2*v+1];
	else
		tree[v] = tree[2*v] ^ tree[2*v+1];
	
}

void modify(int v, int l, int r, int i, int val, int depth)
{
	if (l == r)
	{
		tree[v] = val;
		return;
	}
	
	int c = (l + r)  / 2;
	
	if (i <= c)
		modify(v*2, l, c, i, val, depth-1);
	else
		modify(v*2+1, c+1, r, i, val, depth-1);
		
	if (depth & 1)
		tree[v] = tree[2*v] | tree[2*v+1];
	else
		tree[v] = tree[2*v] ^ tree[2*v+1];
}

int main(int argc, char **argv)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < (1 << n); i++)
	{
		scanf("%d", arr + i);
	}
	
	build(1, 1, (1 << n), n);
	
	for (int i = 0; i < m; i++)
	{
		int p, b;
		scanf("%d %d", &p, &b);
		
		modify(1, 1, (1 << n) , p, b, n);
		printf("%d\n", tree[1]);
	}

	
	return 0;
}