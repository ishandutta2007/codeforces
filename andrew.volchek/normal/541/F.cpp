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
#include <functional>

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


int main()
{
	srand(time(NULL));
	//freopen("a.in", "r", stdin);
	//gen();
	
	int n, t;
	cin >> n >> t;
	vector < pair < int, int > > a;
	for (int i = 0; i < n; i++)
	{
		int ti, qi;
		cin >> ti >> qi;
		a.pb(mp(qi, ti));
	}
	
	
	for (int i = 2; i <= t; i++)
	{
		multiset < pair < int, int > > s;
		vector < pair < int, int > > b;
		for (auto x : a)
			if (x.snd + 1 <= i)
				s.insert(x);
			else
				b.pb(x);
				
		while (s.size() > 1)
		{
			auto u = *s.rbegin();
			s.erase(s.find(u));
			auto v = *s.rbegin();
			s.erase(s.find(v));
			
			b.pb(mp(u.fst + v.fst, i));
		}
		
		a.clear();
		for (auto x : b)
			a.pb(x);
		for (auto x : s)
			a.pb(x);
	}
	
	int ans = 0;
	for (auto x : a)
		if (x.snd <= t)
			ans = max(ans, x.fst);
			
	cout << ans << endl;
	
	return 0;
}