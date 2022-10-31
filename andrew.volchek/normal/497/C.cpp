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

int ans[maxn];

struct ev
{
	int type;
	int a, b, k;
	int ind;
	bool operator < (const ev &other) const 
	{
		return b < other.b || (b == other.b && type < other.type);
	}
};



int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	scanf("%d", &n);
	
	vector < ev > e;
	
	for (int i = 0; i < n; i++)
	{
		ev x;
		x.type = 0;
		x.ind = i;
		scanf("%d %d", &x.a, &x.b);
		e.pb(x);
	}
	
	
	int m;
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++)
	{
		ev x;
		x.type = 1;
		x.ind = i;
		scanf("%d %d %d", &x.a, &x.b, &x.k);
		e.pb(x);
	}
	
	sort(e.begin(), e.end());
	
	for (int i = 0; i < n; i++)
		ans[i] = -1;
		
	set < pair < int, int > > s;
		
	for (auto x : e)
	{
		if (x.type == 0)
		{
			s.insert(mp(x.a, x.ind));
		}
		else
		{
			while (!s.empty() && x.k > 0)
			{
				auto it = s.lower_bound(mp(x.a, -1e9));
				if (it == s.end())
					break;
				ans[it->snd] = x.ind + 1;
				s.erase(it);
				x.k--;
			}
		}
	}
	
	bool good = true;
	for (int i = 0; i < n; i++)
		good &= ans[i] != -1;
		
	if (!good)
	{
		puts("NO");
		return 0;
	}
	
	puts("YES");
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
		
	
	return 0;
}