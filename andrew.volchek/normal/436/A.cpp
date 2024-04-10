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

const int maxn = 2005;
vector < pair < int, int > > a[2];

int used[2][maxn];




int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	int n, nk;
	cin >> n >> nk;
	
	for (int i = 0; i < n; i++)
	{
		int t, h, m;
		cin >> t >> h >> m;
		
		a[t].pb(mp(h, m));
	}
	
	int ans = 0;
	
	for (int g = 0; g < 2; g++)
	{
		for (int i = 0; i < maxn; i++)
			used[0][i] = used[1][i] = 0;
			
		int curr = 0;
		
		int d = nk;
		
		for (int j = 0; j < n; j++)
		{
			int h = -1;
			int i1 = j & 1;
			int i2 = 1 - i1;
			
			for (int k = 0; k < a[i1].size(); k++)
			{
				if (used[i1][k])
					continue;
					
				if (a[i1][k].fst > d)
					continue;
					
				if (h == -1)
					h = k;
				else
				{
					if (a[i1][k].snd > a[i1][h].snd)
						h = k;
				}
			}
			
			if (h == -1)
				break;
				
			curr++;
			d += a[i1][h].snd;	
			used[i1][h] = 1;		
		}
		
		ans = max(ans, curr);
		
		swap(a[0], a[1]);
	}
	
	cout << ans << endl;
	
	return 0;
}