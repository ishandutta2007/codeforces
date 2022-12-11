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

#define maxn 1111

int px[8] = {1,0,-1,0,1,1,-1,-1}, py[8] = {0,1,0,-1,1,-1,1,-1};
int cntb, T, wall;
vector<pii> black;
int c[maxn][maxn];
char s[maxn][maxn];

void dfs(int i, int j)
{
		//printf("dfs %d %d\n", i,j);
		c[i][j] = T;
		if(s[i][j] == '1')
		{
				cntb++;
				black.pb(mp(i,j));
		}
		else if(s[i][j] == '0')
		{
				FOR(k,8)
				{
						int x = i+px[k], y = j+py[k];
						if(c[x][y] == 0 || (s[x][y] != '0' && c[x][y] != T)) dfs(x,y);
				}
		}
		else wall = 1;
}

void dfs2(int i, int j)
{
		cntb--;
		c[i][j] = -1;
		FOR(k,8)
		{
				int x = i+px[k], y = j+py[k];
				if(c[x][y] == T && s[x][y] == '1') dfs2(x,y);
		}
}

int main()
{
		int n,m,res=0;
		scanf("%d%d", &n, &m);
		FORI(i,n) scanf("%s", s[i]+1);
		FORI(i,n) FORI(j,m) if(s[i][j] == '0' && c[i][j] == 0)
		{
				T++;
				black.clear();
				cntb=0;
				wall = 0;
				dfs(i,j);
				//printf("----------end\n");
				if(wall) continue;
				bool wrong = 0;
				FOREACH(k,black)
				{
						int x = k->fi, y = k->se;
						//printf("black %d %d\n", x, y);
						int cnt = 0;
						FOR(a,4)
						{
								int X = x+px[a], Y = y+py[a];
								if(s[X][Y] == '1' && c[X][Y] == T)
										cnt++;
						}
						if(cnt != 2) { wrong = 1; }
				}
				//printf("---------------------------\n");
				if(wrong) continue;
				dfs2(black[0].fi, black[0].se);
				if(cntb > 0) continue;
				res = max(res, SZ(black));
		}
		FORI(i,n-1) FORI(j,m-1) if(s[i][j] == '1' && s[i][j+1] == '1' && s[i+1][j] == '1' && s[i+1][j+1] == '1') res = max(res, 4);
		printf("%d\n", res);
		return 0;
}