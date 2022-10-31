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

const int maxn = 100005;
const ll mod = 1000000009;

int x[maxn], y[maxn];

set < pair < int, int > > a;
map < pair < int, int >, int > m;

int getDeg(int x, int y)
{
	if (y == 0)
		return 0;
		
	int res = a.count(mp(x - 1, y - 1));
	res += a.count(mp(x, y - 1));
	res += a.count(mp(x + 1, y - 1));
	
	return res;
}

bool canRemove(int i)
{
	if (a.count(mp(x[i] - 1, y[i] + 1)))
		if (getDeg(x[i] - 1, y[i] + 1) == 1)
			return false;
			
	if (a.count(mp(x[i], y[i] + 1)))
		if (getDeg(x[i], y[i] + 1) == 1)
			return false;
			
	if (a.count(mp(x[i] + 1, y[i] + 1)))
		if (getDeg(x[i] + 1, y[i] + 1) == 1)
			return false;
			
	return true;
}

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", x + i, y + i);
		a.insert(mp(x[i], y[i]));
		m[mp(x[i], y[i])] = i;
	}
	
		
	ll ans = 0;
	set < int > can;
	for (int i = 0; i < n; i++)
		if (canRemove(i))
			can.insert(i);
			
	for (int i = 0; i < n; i++)
	{
		int h;
		
		if (i & 1)
		{
			h = *can.begin();
		}
		else
		{
			h = *can.rbegin();
		}
		
		can.erase(h);
		a.erase(mp(x[h], y[h]));
		ans = (ans * n + h) % mod;
		
		for (int j = -2; j <= 2; j++)
		{
			if (a.count(mp(x[h] + j, y[h])))
			{
				int f = m[mp(x[h] + j, y[h])];
				if (can.count(f))
					can.erase(f);
					
				if (canRemove(f))
					can.insert(f);
			}
		}
		
		if (y[h])
		{
			for (int j = -1; j <= 1; j++)
			{
				if (a.count(mp(x[h] - j, y[h] - 1)) && canRemove(m[mp(x[h] - j, y[h] - 1)]))
					can.insert(m[mp(x[h] - j, y[h] - 1)]);
			}
			
			
		}
	}
	
	cout << ans << endl;
	
	
	
	
	return 0;
}