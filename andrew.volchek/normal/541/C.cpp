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

struct f
{
	vector < int > a;
	f(int n = 0)
	{
		for (int i = 0; i < n; i++)
			a.pb(i);
	}
	f operator * (const f &o)
	{
		vector < int > res(a.size());
		for (int i = 0; i < a.size(); i++)
			res[i] = a[o.a[i]];
		f r;
		r.a = res;
		return r;
	}
};

f bpow(f x, ll n)
{
	f res(x.a.size());
	while (n)
	{
		if (n & 1)
			res = res * x;
		x = x * x;
		n >>= 1;
	}
	
	return res;
}

bool check(f x)
{
	return (x * x).a == x.a;
}


ll gcd(ll a, ll b)
{
	return a ? gcd(b % a, a) : b;
}


int used[1000];


int main()
{
	srand(time(NULL));
	//freopen("a.in", "r", stdin);
	//gen();
	int n;
	cin >> n;
	
	f x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x.a[i];
		x.a[i]--;
	}
	
	for (int i = 1; i < 205; i++)
	{
		if (check(bpow(x, i)))
		{
			cout << i << endl;
			return 0;
		}
	}
	
	ll g = 1;
	
	for (int i = 0; i < n; i++)
	{
		if (used[i])
			continue;
			
			
		int v = i;
		vector < int > a;
		while (true)
		{
			//cerr << v << endl;
			if (used[v] == 2)
			{
				break;
			}
			
			if (used[v])
			{
				int cnt = 1;
				while (a.back() != v)
				{
					used[a.back()] = 2;
					a.pop_back(), cnt++;
				}
				g = g / gcd(g, cnt) * cnt;
				break;
			}
			used[v] = 1;
			a.pb(v);
			v = x.a[v];
		}
		
		for (int x : a)
			used[x] = 2;
	}
	//cerr << g <<endl;
	
	
	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j < 205; j++)
		{
			if (check(bpow(x, g * i + j)))
			{
				cout << g * i + j << endl;
				return 0;
			}
		}
	}
	
	
	return 0;
}