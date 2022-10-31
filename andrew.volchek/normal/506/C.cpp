
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

ll a[maxn], h[maxn];
ll n, m, k, p;

bool check(ll x)
{
	priority_queue < pair < ll, int > > q;
	vector < ll > add(n, 0);
	
	for (int i = 0; i < n; i++)
	{
		ll need = x / a[i] + 1;
		q.push(mp(m - need + 1, i));
	}
	
	int left = 0;
	
	for (int i = m; i >= 1; i--)
	{
		if (q.top().fst == i)
			return false;
				
		for (int j = 0; j < k; j++)
		{
			auto v = q.top();
			q.pop();
			
			if (v.fst < 1)
			{
				left++;
				q.push(v);
				continue;
			}
			
			add[v.snd] += p;
			ll need = (x + add[v.snd]) / a[v.snd] + 1;
			q.push(mp(m - need + 1, v.snd));
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		while (left && x + add[i] - m * a[i] < h[i])
			left--, add[i] += p;
			
		if (x + add[i] - m * a[i] < h[i])
			return false;
	}
			
	return true;
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	scanf("%lld %lld %lld %lld", &n, &m, &k, &p);
	
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", h + i, a + i);
		
	ll lo = -1, hi = 1e16;
	
	while (hi - lo > 1)
	{
		ll mid = (lo + hi) >> 1;
		
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	
	cout << hi << endl;

	return 0;
}