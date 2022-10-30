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

const int dirs[8][2] = 
{
	1, 0,
	0, 1,
	-1, 0,
	0, -1,
	1, 1, 
	1, -1,
	-1, 1, 
	-1, -1,
};

struct edge
{
	int to;
	int f;
	int c;
	int cost;
	int rev;
};

vector < edge > g[maxn];

void add(int from, int to, int c, int cost)
{
	edge f = {to, 0, c, cost, g[to].size()};
	edge b = {from, 0, 0, -cost, g[from].size()};
	
	g[from].pb(f);
	g[to].pb(b);
}

bool flow(int s, int t)
{
	int d[maxn];
	int id[maxn];
	int q[maxn];
	int pr[maxn];
	
	for (int i = 0; i < maxn; i++) d[i] = inf;
	for (int i = 0; i < maxn; i++) id[i] = 2;
	
	d[s] = 0;
	id[s] = 1;
	
	int head = 0;
	int tail = 0; 
	
	q[head++] = s;
	
	while (head != tail)
	{
		--head;
		head < 0 && (head = maxn);
		int v = q[head];
		
		
		for (int i = 0; i < g[v].size(); i++)
		{
			edge &e = g[v][i];
			if (e.f < e.c && d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				pr[e.to] = e.rev;
				
				if (id[e.to] == 2)
				{
					id[e.to] = 1;
					--tail < 0 && (tail = maxn);
					q[tail] = e.to;
					
				}
				else if (id[e.to] == 1)
				{
					
				}
				else
				{
					id[e.to] = 1;
					q[head++] = e.to;
					head == maxn && (head = 0);
				}
			}
		}
		
		id[v] = 0;
	}
	
	
	if (id[t] == 2) return false;
	//cout << "1" << endl;
	
	for (int v = t; v != s; v = g[v][pr[v]].to)
	{
		g[g[v][pr[v]].to][g[v][pr[v]].rev].f++;
		g[v][pr[v]].f--;
	}
	
	
	return true;
}

int n, m;
int a[88][88];

int main(int argc, char **argv)
{
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	int s = n*m;
	int t = n*m+1;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i + j) & 1)
			{
				for (int h = 0; h < 4; h++)
				{
					int x = i + dirs[h][0];
					int y = j + dirs[h][1];
					//cout << dirs[h][0] << " " << dirs[h][1] << endl;
					if (0 <= x && x < n && 0 <= y && y < m)
					{
						if (a[i][j] == a[x][y])	
							add(i*m + j, x*m + y, 1, 0);
						else
							add(i*m + j, x*m + y, 1, 1);
					}
				}
				
				add(s, i*m + j, 1, 0);
			}
			else
			{
				add(i*m + j, t, 1, 0);
			}
		}
	}
	
	while (flow(s, t));
	
	int ans = 0;
	
	/*for (int i = 0; i < g[s].size(); i++)
	{
		if (g[s][i].c == 1)
			cout << g[s][i].f << endl;
	}*/
	
	for (int i = 0; i < n*m; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			if (g[i][j].f > 0)
				ans += g[i][j].cost;
		}
	}
	
	cout << ans;
	
	
	return 0;
}