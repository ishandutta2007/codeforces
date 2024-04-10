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

const int maxn = 1005;
const ll inf = 1e9;

ll a[maxn], b[maxn];

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	
	ll ans = 1e18;
	
	for (int h = 1; h < maxn; h++)
	{
		bool good = true;
		ll curr = 0;
		for (int i = 0; i < n; i++)
		{
			ll c = inf;
			
			if (a[i] > h && b[i] > h)
				good = false;
				
			if (a[i] <= h)
				c = min(c, b[i]);
				
			if (b[i] <= h)
				c = min(c, a[i]);
				
			curr += c;
		}
		
		if (good)
			ans = min(ans, curr * h);
	}
	
	cout << ans << endl;
	

	return 0;
}