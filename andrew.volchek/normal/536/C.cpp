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

ll sign(ll x)
{
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return -1;
}

struct R
{
	ll n, d;
	
	R()
	{
		n = 0, d = 1;
	}
	
	R(ll x)
	{
		n = x, d = 1;
	}
	
	R(ll _n, ll _d)
	{
		n = _n, d = _d;
		if (d < 0)
			n = -n, d = -d;
	}
	
	R operator + (const R &r) const
	{
		return R(n * r.d + r.n * d, d * r.d);
	}
	
	R operator - (const R &r) const
	{
		
		return R(n * r.d - r.n * d, d * r.d);
	}
	
	R operator * (const R &r) const
	{
		return R(n * r.n, d * r.d);
	}
	
	R operator / (const R &r) const
	{
		return R(n * r.d, d * r.n);
	}
	
	bool operator < (const R &r) const
	{		
		if (sign(n) != sign(r.n))
		{
			return n < r.n;
		}
		else
		{
			if (sign(n) == -1)
			{
				return R(-r.n, r.d) < R(-n, d);
			}
		}
			
		ll x = n / d;
		ll y = r.n / r.d;
		
		if (x < y)
			return true;
		else if (x == y)
		{
			ll n1 = n % d;
			ll n2 = r.n % r.d;
			if (n1 == 0)
			{
				if (n2 == 0)
					return false;
				return true;
			}
			else if (n2 == 0)
				return false;
				
			return R(r.d, n2) < R(d, n1);
		}
		else
		{
			return false;
		}
	}
	
	bool operator == (const R &r) const
	{
		return !(*this < r) && !(r < *this);
	}
};
/*
1/a + x * (1/b - 1/a) = 1/c + x * (1/d - 1/c)

(1/a - 1/c) / (1/d - 1/c - 1/b + 1/a) = 
*/


struct line
{
	// a + (b - a) * x = 0;
	ll a, b;
	int idx;
	
	line()
	{
		
	}
	
	bool operator < (const line &l) const
	{
		return mp(R(1, b) - R(1, a), R(1, a)) < mp(R(1, l.b) - R(1, l.a), R(1, l.a));
	}
	
	//(a2 - a) * (b2 * b) / (a2 * b * a - b2 * b * a - a2 * b2 * a + a2 * b2 * b)

	
	R intersect(const line &l) const
	{
		return R((l.a - a) * (l.b * b), (l.a * b * a - l.b * b * a - l.a * l.b * a + l.a * l.b * b));
	}
};


int main()
{
	//srand(time(NULL));
	//gen();
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);

	int n;
	scanf("%d", &n);
	//n = 200000;
	
	vector < line > a;
	
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		//x = rand() % 10000 + 1;
		//y = rand() % 10000 + 1;
		line l;
		l.a = x;
		l.b = y;
		l.idx = i;
		a.pb(l);
	}
	
	
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	
	vector < line > st;
	

	map < int, vector < int > > cc;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (j < n && a[i].a == a[j].a && a[i].b == a[j].b)
		{
			j++;
		}
			
		for (int h = i; h < j; h++)
			cc[a[i].idx].pb(a[h].idx);
			
		a[p++] = a[i];
		//cerr << a[i].idx << endl;
		i = j - 1;
	}
	
	a.resize(p);
	
	
	for (auto l : a)
	{
		while (!st.empty())
		{
			if (R(1, st.back().b) - R(1, st.back().a) == R(1, l.b) - R(1, l.a))
				st.pop_back();
			else
				break;
		}
		
		while (st.size() > 1)
		{
			auto x1 = st[st.size() - 2].intersect(l);
			auto x2 = st.back().intersect(st[st.size() - 2]);

			if (x1 < x2)
				st.pop_back();
			else
				break;
		}
		
		st.pb(l);
	}
	
	vector < int > ans;
	
	for (int i = 0; i < st.size(); i++)
	{
		bool good = true;
		
		if (i)
		{
			good &= st[i - 1].intersect(st[i]) < R(1, 1);
		}
		
		if (i + 1 < st.size())
		{
			good &= R(0, 1) < st[i].intersect(st[i + 1]);
		}
		
		if (good)
		{
			for (int x : cc[st[i].idx])
				ans.pb(x);
		}
	}
	
	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	return 0;
}