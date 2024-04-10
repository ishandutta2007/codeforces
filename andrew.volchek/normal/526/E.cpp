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

const int maxn = 2000005;



ll a[maxn];
int to[maxn];
int c[maxn];

int solve(ll ub, int n)
{
	ll sum = 0;
	int r = 0;
	
	for (int i = 0; i < n; i++)
	{
		while (r < n)
		{
			if (sum + a[r] <= ub)
			{
				sum += a[r];
				r++;
			}
			else
				break;
		}
		
		to[i] = r - 1;
		sum -= a[i];
	}
	

	int ind = -1;
	for (int i = 1; i < n / 2; i++)
		if (to[i] != to[i - 1] && (ind == -1 || to[ind] - ind > to[i] - i))
			ind = i;
			
	int ans = n;
	int n2 = n >> 1;
			
	for (int i = ind; i <= to[ind]; i++)
	{
		int j = to[i];
		int c = 1;
		
		int x = i + n2 - 1;
		
		while (j < x)
		{
			if (j == n - 1)
				break;
			j = to[j + 1];
			c++;
		}
		
		if (j >= x)
			ans = min(ans, c);
	}
	
	return ans;
}


int main()
{
	//srand(time(NULL));
	//gen();
	//	freopen("a.in", "r", stdin);
	int n, q;
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = a[i + n] = x;
	}
	
	for (int i = 0; i < q; i++)
	{
		ll x;
		cin >> x;
		cout << solve(x, n + n) << endl;
	}

	
	return 0;
}