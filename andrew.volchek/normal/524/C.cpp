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


int can[10000005];
ll a[5005];

int n, k;

bool check(int cnt, ll need)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= cnt; j++)
		{
			if (j == cnt)
			{
				if (a[i] * j == need)
					return true;
				break;
			}
			
			
			if (a[i] * j > need)
				continue;
				
			ll x = need - a[i] * j;
			
			if (x % (cnt - j))
				continue;
				
			x /= cnt - j;
			
			if (x > 10000001)
				continue;
			
			if (can[x] || x == 0)
				return true;
		}
	}
	
	return false;
}

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		can[a[i]] = 1;
	}
		
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		
		int ans = -1;
		
		for (int j = 1; j <= k; j++)
			if (check(j, x))
			{
				ans = j;
				break;
			}
			
		cout << ans << endl;
	}
	

	return 0;
}