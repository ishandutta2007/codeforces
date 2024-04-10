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

ll cnt(ll x)
{
	if (x == 0)
		return 1;
	if (x == 1)
		return 1;
	return 2LL * cnt(x - 1);
}


int main()
{
//	srand(time(NULL));
//	gen();
//	freopen("a.in", "r", stdin);

	
	ll n, k;
	cin >> n >> k;
	k--;
	
	vector < int > ans(n);
	int p = 1;
	int l = 0;
	int r = n - 1;
	
	for (int i = 0; i < n; i++)
	{
		if (cnt(n - i - 1) <= k)
		{
			k -= cnt(n - i - 1);
			ans[r--] = p;
		}
		else
		{
			ans[l++] = p;
		}
		p++;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	
	cout << endl;
	
	return 0;
}