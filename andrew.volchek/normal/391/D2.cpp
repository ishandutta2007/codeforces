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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;
int x1[maxn], y1[maxn], l1[maxn];
int x2[maxn], y2[maxn], l2[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> x1[i] >> y1[i] >> l1[i];
		
	for (int i = 0; i < m; i++)
		cin >> x2[i] >> y2[i] >> l2[i];
		
	int lo = 0, hi = 1e8 + 5;
	
	while (hi - lo > 1)
	{
		int mid = (lo + hi) >> 1;
		
		vector < pair < int, pair < int, int > > > e;
		for (int i = 0; i < n; i++)
		{
			if (y1[i] + mid <= y1[i] + l1[i] - mid)
			{
				e.pb(mp(x1[i], mp(0, i)));
			}
		}
		
		for (int i = 0; i < m; i++)
		{
			if (x2[i] + mid <= x2[i] + l2[i] - mid)
			{
				e.pb(mp(x2[i] + mid, mp(-1, y2[i])));
				e.pb(mp(x2[i] + l2[i] - mid, mp(1, y2[i])));
			}
		}
		
		sort(e.begin(), e.end());
		
		bool any = false;
		
		multiset < int > s;
		
		for (int i = 0; i < e.size(); i++)
		{
			int j = i;
			while (j < e.size() && e[i].fst == e[j].fst) j++;
			
			for (int h = i; h < j; h++)
			{
				if (e[h].snd.fst == -1)
				{
					s.insert(e[h].snd.snd);
				}
				else if (e[h].snd.fst == 0)
				{
					auto it = s.lower_bound(y1[e[h].snd.snd] + mid);
					if (it != s.end() && *it <= y1[e[h].snd.snd] + l1[e[h].snd.snd] - mid)
						any = true;
				}
				else
				{
					s.erase(s.find(e[h].snd.snd));
				}
			}
			
			i = j - 1;
		}
		
		if (any)
			lo = mid;
		else
			hi = mid;
	}
	
	cout << lo << endl;
	
	return 0;
}