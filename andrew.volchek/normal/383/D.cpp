#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 1005;
const int maxw = 20001;
const int zero = 10000;
const int mod = 1e9 + 7;

int a[maxn];
int w1[maxn][maxw], w2[maxn][maxw];

int f(int l, int r)
{
	if (l == r)
		return 0;
		
	int res = 0;
	int c = (l + r) / 2;
	
	res += f(l, c);
	res += f(c+1, r);

	if (res >= mod)
		res -= mod;
		
	for (int i = c; i >= l; i--)
	{
		for (int j = 0; j < maxw; j++) w1[c - i + 1][j] = 0;
		for (int j = a[i]; j < maxw - a[i]; j++)
		{
			w1[c - i + 1][j] = w1[c - i][j - a[i]] + w1[c - i][j + a[i]];
			if (w1[c - i + 1][j] >= mod)
				w1[c - i + 1][j] -= mod;
		}
	}
	
	for (int i = c; i >= l; i--)
	{
		for (int j = 0; j < maxw; j++)
		{
			w1[c - i + 1][j] += w1[c - i][j];
			if (w1[c - i + 1][j] >= mod)
				w1[c - i + 1][j] -= mod;
		}
	}
	
	for (int i = c + 1; i <= r; i++)
	{
		for (int j = 0; j < maxw; j++) w2[i - c][j] = 0;
		for (int j = a[i]; j < maxw - a[i]; j++)
		{
			w2[i - c][j] = w2[i - c - 1][j - a[i]] + w2[i - c - 1][j + a[i]];
			if (w2[i - c][j] >= mod)
				w2[i - c][j] -= mod;
		}
	}
	
	for (int i = c + 1; i <= r; i++)
	{
		for (int j = 0; j < maxw; j++)
		{
			w2[i - c][j] += w2[i - c - 1][j];
			if (w2[i - c][j] >= mod)
				w2[i - c][j] -= mod;
		}
	}
	
	int i1 = c - l + 1;
	int i2 = r - (c + 1) + 1;
	
	w1[i1][zero] = (w1[i1][zero] + mod - 1) % mod;
	w2[i2][zero] = (w2[i2][zero] + mod - 1) % mod;
	
	for (int i = 0; i < maxw; i++)
	{
		res += ((ll)w1[i1][i] * w2[i2][zero - (i - zero)]) % mod;
		if (res >= mod)
			res -= mod;
	}
	
	return res;
}


int main()
{
	//freopen("a.in", "r", stdin);
	
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	w1[0][zero] = w2[0][zero] = 1;
	
	cout << f(1, n) << endl;	
	

	
	return 0;
}