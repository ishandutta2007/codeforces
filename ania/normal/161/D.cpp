#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int n,k;
int occ[50050][505];
vector<int> g[50050];

long long dfs(int u, int p)
{
	long long res = 0;
	occ[u][0] = 1;
	FOREACH(i,g[u]) if(*i != p)
	{
		res += dfs(*i, u);
		REP(j,0,k) occ[u][j+1] += occ[*i][j];
	}
	res += occ[u][k];
	res *= 2;
	//printf("occ[%d] = ", u+1); REP(j,0,k) printf("%d ", occ[u][j]); printf("\n");
	FOREACH(i,g[u]) if(*i != p)
	{
		REP(j,1,k-1) res += 1LL * occ[*i][j-1] * (occ[u][k-j] - occ[*i][k-j-1]);
	}
	return res / 2;
}

int main()
{
	scanf("%d%d", &n, &k);
	FOR(i,n-1)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	cout << dfs(0, -1) << endl;
	return 0;
}