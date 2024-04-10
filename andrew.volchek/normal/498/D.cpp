#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 100005;

int t[maxn * 4][60];
int a[maxn];
int md[maxn * 70];


void mrg(int *aa, int *b, int *res)
{
	for (int i = 0; i < 60; i++)
	{
		int j = i + aa[i];
		j = j - i + b[md[j]];
		res[i] = j;
	}
}

void build(int v, int l, int r)
{
	if (l == r)
	{
		for (int i = 0; i < 60; i++)
		{
			if (i % a[l] == 0)
				t[v][i] = 2;
			else
				t[v][i] = 1;
		}
		return;
	}
	
	int c = (l + r) >> 1;
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	
	mrg(t[2 * v], t[2 * v + 1], t[v]);
}


void modify(int v, int l, int r, int ii, int val)
{
	if (l == r)
	{
		for (int i = 0; i < 60; i++)
		{
			if (i % val == 0)
				t[v][i] = 2;
			else
				t[v][i] = 1;
		}
		return;
	}
	
	int c = (l + r) >> 1;
	if (ii <= c)
		modify(2 * v, l, c, ii, val);
	else
		modify(2 * v + 1, c + 1, r, ii, val);
		
	mrg(t[2 * v], t[2 * v + 1], t[v]);	
}


int get(int v, int l, int r, int i, int j, int curr)
{
	if (i <= l && r <= j)
	{
		return curr + t[v][md[curr]];
	}
	
	int res = curr;
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		res = get(2 * v, l, c, i, j, res);
	if (c < j)
		res = get(2 * v + 1, c + 1, r, i, j, res);
		
	return res;
}
int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	
	for (int i = 0; i < maxn * 70; i++)
		md[i] = i % 60;
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
		
	
	build(1, 0, n - 1);
	
	
	int q;
	scanf("%d\n", &q);
	
	for (int i = 0; i < q; i++)
	{
		
		char c;
		int x, y;
		scanf("%c %d %d\n", &c, &x, &y);
		
		if (c == 'A')
		{
			printf("%d\n", get(1, 0, n - 1, x - 1, y - 2, 0));
		}
		else
		{
			//cout << x << " " << y << endl;
			modify(1, 0, n - 1, x - 1, y);
		}
	}
	
	
	return 0;
}