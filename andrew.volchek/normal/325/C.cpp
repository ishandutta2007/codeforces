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
const ll ub = 314000000;

ll mi[maxn], ma[maxn];
ll prodMi[maxn], prodMa[maxn];

int inf[maxn];
int color[maxn];

vector < int > prod[maxn];
int prodDeg[maxn];
ll prodCost[maxn];
int prodM[maxn];

vector < int > prodByMonster[maxn];
vector < int > monsterInProd[maxn];

void calcProd(int v);

void dfs(int monster)
{
	color[monster] = 1;
	
	for (int p : prodByMonster[monster])
	{
		calcProd(p);
		
		if (prodDeg[p] > 0)
			continue;
		
		if (prodMa[p] == -2)
		{
			ma[monster] = -2;
			break;
		}
		else
		{
			ma[monster] = max(ma[monster], prodMa[p]);
		}
	}
	
	color[monster] = 2;
}

void calcProd(int v)
{
	if (prodDeg[v] > 0)
		return;
		
	prodMa[v] = prodCost[v];
		
	for (int to : prod[v])
	{
		if (color[to] == 1)
		{
			prodMa[v] = -2;
			return;
		}
		
		if (color[to] == 0)
			dfs(to);
			
		if (ma[to] == -2)
		{
			prodMa[v] = -2;
			return;
		}
		else
		{
			prodMa[v] = min(ub, prodMa[v] + ma[to]);
		}
	}
}

void gen()
{
	freopen("a.in", "w", stdout);
	cout << 64 << " " << 32 << endl;
	for (int i = 1; i < 32; i++)
	{
		cout << i << " " << 3 << " " << i + 1 << " " << i + 1 << " " << -1 << endl;
		cout << i << " " << 2 << " " << " " << i + 1 << " " << -1 << endl;
	}
	cout << 32 << " " << 1 << " " << -1 << endl;
	cout << 32 << " " << 1 << " " << -1 << endl;
	exit(0);
}

int main(int argc, char *argv[])
{
	//gen();
    //freopen("a.in", "r", stdin);
    
    int n, m;
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++)
    {
		int type, cnt;
		scanf("%d %d", &type, &cnt);
		
		prodByMonster[type].pb(i);
		prodM[i] = type;
		
		for (int j = 0; j < cnt; j++)
		{
			int x;
			scanf("%d", &x);
			
			if (x == -1)
				prodCost[i]++;
			else
			{
				monsterInProd[x].pb(i);
				prodDeg[i]++;
				prod[i].pb(x);
			}
		}
		
		prodMi[i] = prodCost[i];
	}
	
	for (int i = 1; i <= n; i++)
		mi[i] = -1;
	
	priority_queue < pair < int, int > > q;
	
	for (int i = 0; i < m; i++)
	{
		if (prodDeg[i] == 0)
		{
			prodMi[i] = prodCost[i];
			int x = prodM[i];
			
			if (mi[x] == -1 || mi[x] > prodMi[i])
			{
				mi[x] = prodMi[i];
				q.push(mp(-mi[x], x));
			}
		}
	}
	
	vector < int > used(n + 1, 0);
	
	while (!q.empty())
	{
		int v = q.top().snd;
		ll currD = -q.top().fst;
		
		q.pop();
		
		if (currD != mi[v])
			continue;
			
		for (int to : monsterInProd[v])
		{
			prodDeg[to] -= 1;;
			prodMi[to] += currD;
			prodMi[to] = min(prodMi[to], ub);
			
			if (prodDeg[to] == 0)
			{
				int x = prodM[to];
				
				if (mi[x] == -1 || mi[x] > prodMi[to])
				{
					mi[x] = prodMi[to];
					q.push(mp(-mi[x], x));
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (color[i] == 0)
			dfs(i);
			
	for (int i = 1; i <= n; i++)
	{
		if (mi[i] == -1)
			printf("-1 -1\n");
		else
			printf("%d %d\n", int(mi[i]), int(ma[i]));
	}
	
	return 0;
}