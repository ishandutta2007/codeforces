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
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

int sign(ll x)
{
	if (x > 0)
		return -1;
	else if (x == 0)
		return 0;
	else
		return 1;
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	int n;
	cin >> n;
	
	
	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		
		if (sign(a * x1 + b * y1 + c) != sign(a * x2 + b * y2 + c))
			ans++;
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}