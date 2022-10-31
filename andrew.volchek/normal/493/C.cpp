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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}


void relax(pair < ll, ll > &ans, pair < ll, ll > curr)
{
	if (curr.fst - curr.snd > ans.fst - ans.snd)
		ans = curr;
	else if (curr.fst - curr.snd == ans.fst - ans.snd)
	{
		if (curr.fst > ans.fst)
			ans = curr;
	}
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	vector < pair < int, int > > a;
	ll cnt[2];
	for (int j = 0; j < 2; j++)
	{
		int n;
		scanf("%d", &n);
		cnt[j] = n;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a.pb(mp(x, j));
		}
	}
	sort(a.begin(), a.end());
	
	ll sa = 0, sb = 0;
	
	pair < ll, ll > ans(-1e14, 1e14);
	
	if (a[0].fst > 0)
	{
		relax(ans, mp(cnt[0] * 3, cnt[1] * 3));
	}
	
	for (int i = 0; i < a.size(); i++)
	{
		int j = i;
		while (j < a.size() && a[j].fst == a[i].fst) j++;
		
		for (int h = i; h < j; h++)
		{
			if (a[h].snd == 0)
				sa++;
			else
				sb++;
		}
		
		relax(ans, mp(sa * 2 + (cnt[0] - sa) * 3, sb * 2 + (cnt[1] - sb) * 3));
		
		i = j - 1;
	}
	
	cout << ans.fst << ":" << ans.snd << endl;

	return 0;
}