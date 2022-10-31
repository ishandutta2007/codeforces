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

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 100005;
const int inf = 1e9;

int n;
multiset < int > v;
set < pair < pair < int, int >, int > > s;

void add(int x, int val)
{
	v.insert(n - min(n, x) + val);
}

void remove(int x, int val)
{
	v.erase(v.find(n - min(n, x) + val));
}

void addS(int l, int val)
{
	auto it = s.upper_bound(mp(mp(l, inf), -1));
	
	if (it != s.begin())
	{
		it--;
		
		if (it->snd >= val)
			return;
		else
		{
			if (it->fst.fst == l)
			{
				remove(it->fst.fst, it->snd);
				remove(it->fst.snd, it->snd);
				s.erase(it);
				add(l, val);
			}
			else
			{
				remove(it->fst.snd, it->snd);
				add(l - 1, it->snd);
				auto t = mp(mp(it->fst.fst, l - 1), it->snd);
				s.erase(it);
				s.insert(t);
				add(l, val);
			}
		}	
	}
	else
		add(l, val);
	
	int r = l;
	
	while (true)
	{
		auto it = s.upper_bound(mp(mp(l, -1), -1));
		
		if (it == s.end())
		{
			r = n + 1;
			break;
		}
			
		if (it->snd >= val)
		{
			r = it->fst.fst - 1;
			break;
		}
		
		remove(it->fst.fst, it->snd);
		remove(it->fst.snd, it->snd);
		r = it->fst.snd;
		s.erase(it);
	}
	
	add(r, val);
	
	s.insert(mp(mp(l, r), val));
}

int a[3][maxn];
map < int, int > rev[3];

void print()
{
	cerr << endl;
	for (auto x : s)
	{
		cerr << x.fst.fst << " " << x.fst.snd << " " << x.snd << endl;
	}
	cerr << endl;
}

int main(int argc, char *argv[])
{
   // freopen("a.in", "r", stdin);
    
	
	scanf("%d", &n);
	
	set < int > e;
	
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (rev[i].find(a[i][j]) == rev[i].end())
				rev[i][a[i][j]] = j;
			e.insert(a[i][j]);
		}
	
	v.insert(0);
	v.insert(n);
	s.insert(mp(mp(0, n + 1), 0));
	
	//print();
	
	for (int x : e)
	{
		if (rev[0].find(x) != rev[0].end())
			continue;
			
		if (rev[1].find(x) == rev[1].end())
		{
			addS(0, rev[2][x]);
		}
		else
		{
			int y;
			if (rev[2].find(x) == rev[2].end())
				y = inf;
			else
				y = rev[2][x];
				
			addS(n + 1 - rev[1][x], y);
		}
	}
	
	//print();
	
	int ans = n + (*v.begin());
	//cerr << (*v.begin()) << endl;
	
	for (int i = n; i >= 1; i--)
	{
		if (rev[0][a[0][i]] < i)
		{
			ans = min(ans, i - 1 + (*v.begin()));
			continue;
		}
			
		int x = a[0][i];
		
		if (rev[1].find(x) == rev[1].end() && rev[2].find(x) == rev[2].end())
			break;
		
		if (rev[1].find(x) == rev[1].end())
		{
			addS(0, rev[2][x]);
		}
		else
		{
			int y;
			if (rev[2].find(x) == rev[2].end())
				y = inf;
			else
				y = rev[2][x];
				
			addS(n + 1 - rev[1][x], y);
		}
		
		ans = min(ans, i - 1 + (*v.begin()));
	}
	
	cout << ans << endl;
	
	return 0;
}