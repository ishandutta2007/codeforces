#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

struct query
{
	ll l, c;
	int x;
};

vector < pair < ll, query > > q;
const int maxn = 100005;
int a[maxn];
ll len = 0;


int main()
{
	
//	freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int type;
		scanf("%d", &type);
		
		
		if (type == 1)
		{
			int x;
			scanf("%d", &x);
			
			pair < ll, query > qt;
			qt.fst = len;
			qt.snd.x = x;
			q.pb(qt);
			
			if (len < (ll)maxn)
			{
				a[len] = x;
			}
			
			len++;
		}
		else
		{
			int l, c;
			scanf("%d %d", &l, &c);
			
			pair < ll, query > qt;
			qt.fst = len;
			qt.snd.l = l;
			qt.snd.c = c;
			qt.snd.x = -1;
			q.pb(qt);
			
			for (int h = 0; h < c && len < (ll)maxn; h++)
			{
				for (int j = 0; j < l && len < (ll)maxn; j++)
				{
					a[len++] = a[j];
				}
			}
			
			len = (ll)qt.fst + (ll)l * c;
		}
	}
	

	
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		x--;
		
		
		int lo = -1;
		int hi = q.size();
		
		while (hi - lo > 1)
		{
			int mid = (lo + hi) / 2;
			
			if (q[mid].fst <= x)
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}
		
		if (q[lo].snd.x != -1)
		{
			if (i)
				printf(" ");
			printf("%d", q[lo].snd.x);
		}
		else
		{
			ll c = x - q[lo].fst;
			c %= q[lo].snd.l;
			
			
			if (i)
				printf(" ");
			
			printf("%d", a[c]);
		}
	
	}
	

	return 0;
}