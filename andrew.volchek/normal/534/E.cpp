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
#include <functional>

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

int b[maxn];
int bo[maxn];
ll a[maxn];

int n, m;

ll go(int pos, int dir)
{
	for (int i = 0; i < n; i++)
		b[i] = bo[i];
		
	ll len = 0;
	int cnt = 1;
	
	if (!b[pos])
		return -1;
	
	b[pos]--;
	
	while (true)
	{
		if (pos + dir < 0 || pos + dir == n)
			dir = -dir;
			
		if (!b[pos + dir])
			break;
			
		b[pos + dir]--;
		cnt++;
		len += abs(a[pos + dir] - a[pos]);
		pos += dir;
	}
	
	if (cnt == m)
		return len;
	else
		return -1;
}



int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
		
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		bo[x - 1]++;
	}
	
	ll ans = -1;
	
	
	for (int i = 0; i < n; i++)
	{
		if (!i || i == n || bo[i + 1] != bo[i] || bo[i - 1] != bo[i])
		{
			ll res = go(i, 1);
			if (ans == -1)
				ans = res;
			else
			{
				if (res != -1 && ans != res)
				{
					cout << -1 << endl;
					return 0;
				}
			}
			
			res = go(i, -1);
			if (ans == -1)
				ans = res;
			else
			{
				if (res != -1 && ans != res)
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	
	cout << ans << endl;	
	
	return 0;
}