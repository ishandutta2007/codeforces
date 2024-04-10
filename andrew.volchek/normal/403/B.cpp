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

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 5005;

int a[maxn];
set < int > b;

int f(int x)
{
	int sum = 0;
	int g = sqrt(x) + 2;
	for (int j = 2; j < g; j++)
	{
		int cnt = 0;
		while (x % j == 0)
		{
			cnt++;
			x /= j;
		}
		
		if (cnt)
		{
			if (b.count(j))
			{
				sum -= cnt;
			}
			else
			{
				sum += cnt;
			}
		}
	}
	
	if (x > 1)
	{
		
			if (b.count(x))
			{
				sum--;
			}
			else
			{
				sum++;
			}
	}
	
	return sum;
}

int gcd(int a, int b)
{
	return a ? gcd(b % a, a) : b;
}


int gg[maxn];


int main()
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		b.insert(x);
	}
	
	gg[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		gg[i] = gcd(gg[i - 1], a[i]);
	}
	
	int curr = 1;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (gg[i] == 1)
			continue;
			
		int res = f(gg[i] / curr);
		
		if (res < 0)
		{
			ans += (i + 1) * (-res);
			curr *= gg[i] / curr;
		}
	}
	
	for (int i = 0; i < n; i++)
		ans += f(a[i]);
		
	cout << ans << endl;
	
	
	return 0;
}