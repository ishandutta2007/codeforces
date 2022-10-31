#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

ll a[105];

ll gcd(ll a, ll b)
{
	return a ? gcd(b % a, a) : b;
}

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = 0;
	n++;
	sort(a, a+n);
	
	ll g = a[1];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			g = gcd(g, abs(a[i]-a[j]));
		}
	
	ll cnt = (a[n-1] / g) - n;
	
	if (!(cnt & 1))
		puts("Alice");
	else
		puts("Bob");
	

	return 0;
}