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

const int maxn = 300005;

int a[maxn];
int sum[maxn][2];
int rev[maxn][2];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	for (int i = 1; i <= n; i++)
	{
		sum[i][0] = sum[i - 1][0] + (a[i] == 1);
		sum[i][1] = sum[i - 1][1] + (a[i] == 2);
	}
	
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 2; j++)
			rev[i][j] = -1;
	
	for (int i = n; i >= 1; i--)
	{
		rev[sum[i][0]][0] = i;
		rev[sum[i][1]][1] = i;
	}
	
	vector < pair < int, int > > ans;
	
	for (int t = 1; t <= n; t++)
	{
		bool bad = false;
		int x = 0, y = 0;
		
		int u = 0, v = 0;
		int lst = 0;
		while (true)
		{
			if (rev[u + t][0] == -1 && rev[v + t][1] == -1)
			{
				bad = true;
				break;
			}
			
			int pos = 1e9;
			
			if (rev[u + t][0] != -1)
				pos = min(pos, rev[u + t][0]);
			
			if (rev[v + t][1] != -1)
				pos = min(pos, rev[v + t][1]);
				
			if (sum[pos][0] == u + t)
			{
				x++;
				lst = 0;
			}
			else
			{
				y++;
				lst = 1;
			}
				
			if (pos == n)
				break;
				
			u = sum[pos][0];
			v = sum[pos][1];
		}
		
		if (x == y)
			bad = true;
			
		if (x > y && lst == 1)
			bad = true;
			
		if (x < y && lst == 0)
			bad = true;
		
		if (!bad)
			ans.pb(mp(max(x, y), t));
	}
	
	sort(ans.begin(), ans.end());
	
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d %d\n", x.fst, x.snd);
	
	
	
	return 0;
}