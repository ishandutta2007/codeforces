#include<bits/stdc++.h>

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

const int maxn = 1010;

int px[4]={0,1,0,-1}, py[4]={1,0,-1,0};
int n,m,col;
int vis[maxn][maxn], sz[maxn*maxn], res[maxn][maxn];
char s[maxn][maxn];

void dfs(int x, int y, int co) {
	vis[x][y] = co;
	sz[co]++;
	FOR(k,4) {
		int nx=x+px[k], ny=y+py[k];
		if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if (s[nx][ny] == '*') continue;
		if (vis[nx][ny]) continue;
		dfs(nx,ny,co);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%s", s[i]);
	FOR(i,n) FOR(j,m) if (s[i][j]=='.' && !vis[i][j]) dfs(i,j,++col);
	FOR(i,n) FOR(j,m) if (s[i][j] == '*') {
		res[i][j]=1;
		set<int> S;
		FOR(k,4) {
			int nx=i+px[k], ny=j+py[k];
			if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if (s[nx][ny]=='*') continue;
			S.insert(vis[nx][ny]);
		}
		for (set<int>::iterator k=S.begin(); k!=S.end(); k++) res[i][j] += sz[*k];
	}
	FOR(i,n) {
		FOR(j,m) if (s[i][j]=='.') printf(".");
		else printf("%d", res[i][j]%10);
		printf("\n");
	}
	return 0;
}