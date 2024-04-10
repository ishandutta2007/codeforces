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

const int maxn = 700005;

char str[maxn];

vector < int > a[maxn];

int main(int argc, char *argv[])
{
    //freopen("a.in", "r", stdin);
    gets(str);
    int len = strlen(str);
    
    for (int i = 0; i < len; i++)
    {
		int curr = 0;
		int p = 1;
		for (int j = i; j < min(len, i + 4); j++)
		{
			curr += (str[j] - 'a' + 1) * p;
			p *= 27;
			
			a[curr].pb(i);
		}
	}
	
	int n;
	scanf("%d\n", &n);
	
	char q[2][100];
	
	map < pair < int, int >, int > cache;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s\n", q[0], q[1]);
		
		int len[2] = { strlen(q[0]), strlen(q[1]) };
		
		if (len[0] > len[1])
		{
			swap(len[0], len[1]);
			swap(q[0], q[1]);
		}
		
		int h[2] = { 0, 0 };

		for (int j = 0; j < 2; j++)
		{
			int p = 1;
			for (int k = 0; k < len[j]; k++)
			{
				h[j] += p * (q[j][k] - 'a' + 1);
				p *= 27;
			}
		}
		
		if (cache.find(mp(h[0], h[1])) != cache.end())
		{
			cout << cache[mp(h[0], h[1])] << endl;
			continue;
		}
			
		int ans = 1 << 30;
		
		for (int j = 0; j < a[h[0]].size(); j++)
		{
			int lo = -1, hi = a[h[1]].size();
			
			while (hi - lo > 1)
			{
				int mid = (lo + hi) >> 1;
				
				if (a[h[1]][mid] <= a[h[0]][j])
					lo = mid;
				else
					hi = mid;
			}
			
			if (lo >= 0)
			{
				ans = min(ans, max(a[h[0]][j] + len[0], a[h[1]][lo] + len[1]) - a[h[1]][lo]);
			}
			
			if (hi < a[h[1]].size())
			{
				ans = min(ans, max(a[h[0]][j] + len[0], a[h[1]][hi] + len[1]) - a[h[0]][j]);
			}
		}
		
		if (ans == (1 << 30))
			ans = -1;
		
		cache[mp(h[0], h[1])] = ans;
		cout << ans << endl;
	}
   
    
    return 0;
}