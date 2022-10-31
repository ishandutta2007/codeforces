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

const int maxn = 100005;
const int maxa = 1000005;
int x[maxn];
ll a, b;
int n;
ll c[maxa];

int main()
{
	scanf("%d", &n);
	//n = 100000;
	for (int i = 0; i < n; i++)
		scanf("%d", x+i);
		//x[i] = i+1;
	//	a = 1e9;
	//	b = a - 1000000;
	cin >> a >> b;
	
	
	sort(x, x+n);
	n = unique(x, x+n) - x;
	
	for (int i = 0; i < maxa; i++)
		c[i] = 1e9;
	
	for (int i = 0; i < n; i++)
	{
		ll st = (b / x[i]) * x[i];
		if (b % x[i])
			st += x[i];
		for (ll j = st; j <= a; j+=x[i])
			if (j - x[i] >= b)
				c[j-b] = min(c[j-b], j - x[i]);
	}
	
	ll mm = 1e9;
	for (ll i = 0; i < n; i++)
		if ((a / x[i]) * x[i] >= b)
			mm = min(mm, (a / x[i]) * x[i]);
		
	ll curr = a;
	ll ans = 0;
	
	for (ll i = a; i > b; i--)
	{
		if (curr == i)
		{
			if (mm < curr)
			{
				ans++;
				curr = mm;
			}
			else
			{
				ans++;
				curr--;
			}
		}
		
		if (c[i-b] >= b)
			mm = min(mm, c[i-b]);
		
	}
	
	cout << ans;
	
	

	return 0;
}