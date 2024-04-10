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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}


const int maxn = 200005;

int t[maxn];

void clear()
{
	for (int i = 0; i < maxn; i++)
		t[i] = 0;
}

void add(int i, int v)
{
	while (i < maxn)
	{
		t[i] += v;
		i = i | (i + 1);
	}
}

int get(int r)
{
	int res = 0;
	while (r >= 0)
	{
		res += t[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}

int a[maxn], b[maxn], an[maxn], bn[maxn];

void enumerate(int *x, int *y, int n)
{
	clear();
	
	for (int i = 0; i < n; i++)
	{
		int res = x[i] - get(x[i]);
		y[i] = res;
		add(x[i], 1);
	}
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		scanf("%d", b + i);
		
	enumerate(a, an, n);
	enumerate(b, bn, n);
	
	for (int i = n - 1; i >= 0; i--)
	{
		int res = an[i] + bn[i];
		
		if (res >= (n - 1 - i + 1))
		{
			res -= (n - 1 - i + 1);
			if (i > 0)
				an[i - 1]++;
		}
		
		an[i] = res;
	}
	
	vector < int > ans(n);
	
	clear();
	
	for (int i = 0; i < n; i++)
	{
		int need = an[i];
		
		int lo = -1, hi = n;
		while (hi - lo > 1)
		{
			int mid = (lo + hi) >> 1;
			
			if (mid - get(mid) < need)
				lo = mid;
			else
				hi = mid;
		}
		
		ans[i] = hi;
		add(hi, 1);
	}
	
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	return 0;
}