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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}


int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	int n;
	scanf("%d", &n);
	
	ll a = 0, b = 0;
	vector < int > c, d;
	int lst = 0;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		
		if (x > 0)
		{
			a += x;
			c.pb(x);
			lst = 0;
		}
		else 
		{
			b -= x;
			d.pb(-x);
			lst = 1;
		}
	}
	
	if (a > b)
		puts("first");
	else if (a < b)
		puts("second");
	else
	{
		if (c > d)
			puts("first");
		else if (c < d)
			puts("second");
		else
		{
			if (!lst)
				puts("first");
			else
				puts("second");
		}
	}
	

	return 0;
}