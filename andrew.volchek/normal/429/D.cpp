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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;
const int dirs[9][2] =
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
	0, 0,
	1, 1,
	1, -1,
	-1, 1,
	-1, -1,
};

ll xt[maxn], yt[maxn], x[maxn], y[maxn];

namespace std 
{
	template <>
	struct hash < pair < ll, ll > >
	{
		size_t operator()(pair < ll, ll > x) const
		{
			return (abs(x.fst) + 1LL) * (abs(x.snd) + 1LL);
		}
	};
}

unordered_map < pair < ll, ll >, int > h;

pair < ll, ll > gr(int i, ld r)
{
	return mp(floor((ld)x[i] / r), floor((ld)y[i] / r));
}

void rebuild(int m, ll r2)
{
	ld r = sqrt(r2);
	h.clear();
	
	for (int i = 1; i <= m; i++)
		h[gr(i, r / 2.0)] = i;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	int p[maxn];
	
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		xt[i] = i;
		yt[i] = yt[i - 1] + t;
		p[i] = i;
	}
	
	random_shuffle(p + 1, p + 1 + n);
	random_shuffle(p + 1, p + 1 + n);
	
	for (int i = 1; i <= n; i++)
		x[i] = xt[p[i]], y[i] = yt[p[i]];
	
	ll r2 = 1e18 * 1.5;
	rebuild(1, r2);
	
	for (int i = 2; i <= n; i++)
	{
		ld r = sqrt(r2);
		pair < ll, ll > curr = gr(i, r / 2.0);
		
		ll cr = r2;
		
		for (int ddx = -2; ddx <= 2; ddx++)
			for (int ddy = -2; ddy <= 2; ddy++)
			{
				auto it = h.find(mp(curr.fst + ddx, curr.snd + ddy));
				if (it == h.end())
					continue;
					
				ll dx = x[it->snd] - x[i];
				ll dy = y[it->snd] - y[i];
				
				cr = min(cr, dx * dx + dy * dy);
			}
		
		if (cr < r2)
		{
			r2 = cr;
			rebuild(i, r2);
		}
		else
		{
			h[curr] = i;
		}
	}
	
	cout << r2 << endl;
	
	return 0;
}