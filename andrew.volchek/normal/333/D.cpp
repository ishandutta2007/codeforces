#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

pair < int, pair < int, int > > a[1000005];
vector < int > rows[1005];
bool was[1005][1005];
int n, m;



int main(int argc, char **argv)
{
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			a[i*m + j] = mp(x, mp(i, j));
		}
	}
	
	sort(a, a + n*m);
	
	for (int i = n*m - 1; i >= 0; i--)
	{
		int val = a[i].fst;
		int x = a[i].snd.fst;
		int y = a[i].snd.snd;
		
		for (int j = 0; j < rows[x].size(); j++)
		{
			if (was[rows[x][j]][y])
			{
				printf("%d", val);
				return 0;
			}
			
			was[rows[x][j]][y] = true;
			was[y][rows[x][j]] = true;
		}
		
		rows[x].pb(y);
	}
	
			
	return 0;
}