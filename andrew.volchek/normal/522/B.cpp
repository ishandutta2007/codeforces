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

const int maxn = 200005;

int h[maxn], w[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	
	multiset < int > s;
	ll ws = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", w + i, h + i);
		s.insert(h[i]);
		ws += w[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		s.erase(s.find(h[i]));
		ll x = (ws - w[i]) * (*s.rbegin());
		s.insert(h[i]);
		printf("%d", (int)x);
	}
	
	
	return 0;
}