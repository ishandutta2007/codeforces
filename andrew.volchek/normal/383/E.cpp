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

const int maxm = (1 << 24) + 1;
int a[maxm], b[maxm];

void rec(int l, int r)
{
	if (l == r)
	{
		b[l] = a[l];
		return;
	}
	
	int c = (l + r) / 2;
	
	rec(l, c);
	rec(c + 1, r);
	
	for (int i = c + 1; i <= r; i++)
		b[i] += b[l + i - c - 1];
}

char str[10];

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n;
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++)
	{
		gets(str);
		int mask = 0;
		for (int j = 0; j < 3; j++)
			mask |= (1 << (str[j] - 'a'));
			
		for (int j = mask; j > 0; j = mask & (j - 1))
		{
			if (__builtin_popcount(j) & 1)
				a[j]++;
			else
				a[j]--;
		}
	}
	
	rec(0, (1 << 24) - 1);
	
	int ans = 0;
	
	for (int i = 0; i < (1 << 24); i++)
		ans ^= b[i] * b[i];
	
	cout << ans << endl;
	
	return 0;
}