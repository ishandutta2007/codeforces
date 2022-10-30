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
#define fst first
#define snd second

const int maxn = 10000;
const int inf = 1000000000;


int n;
vector < pair < int , int > > a;
vector < int > g[111];
int used[111];
void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs(g[v][i]);
}

int main(int argc, char **argv)
{
	cin >> n;
	for (int q = 0; q < n; q++)
	{
		int type, x, y;
		cin >> type >> x >> y;
		int curr = a.size();
		if (type == 1)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if ((a[j].fst < x && x < a[j].snd) || (a[j].fst < y && y < a[j].snd))
				{
					g[curr].push_back(j);
				}
				if ((x < a[j].fst && a[j].fst < y) || (x < a[j].snd && a[j].snd < y))
				{
					g[j].push_back(curr);
				}
			}
			a.pb(mp(x, y));
		}
		else
		{
			x--;
			y--;
			for (int i = 0; i < 111; i++)
				used[i] = 0;
				dfs(x);
			if (used[y])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	
	
	return 0;
}