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
const int inf = 300100100;

int n,m;
char s[maxn][maxn];
int dst[5][maxn][maxn];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

void bfs(int x) {
	FOR(i,n) FOR(j,m) dst[x][i][j] = inf;
	queue<int> q;
	FOR(i,n) FOR(j,m) if (s[i][j]=='0'+x) {
		q.push(i); q.push(j);
		dst[x][i][j] = 0;
	}
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		int b = q.front();
		q.pop();
		FOR(k,4) {
			int A = a+dx[k], B = b+dy[k];
			if (A<0 || B<0 || A>=n || B>=m) continue;
			if (s[A][B] == '#') continue;
			if (dst[x][A][B] > dst[x][a][b]+1) {
				dst[x][A][B] = dst[x][a][b]+1;
				q.push(A);
				q.push(B);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%s", s[i]);
	FORI(i,3) bfs(i);
	int res = inf;
	FORI(x,3) {
		int c2r = 0;
		FORI(y,3) if (x!=y) {
			int cd = inf;
			FOR(i,n) FOR(j,m) if (s[i][j]=='0'+y) cd = min(cd, dst[x][i][j]);
			c2r += cd-1;
		}
		if (c2r < res) res = c2r;
	}
	FOR(i,n) FOR(j,m) {
		int cd = 0;
		FORI(x,3) cd += dst[x][i][j];
		if (cd-2 < res) res = cd-2;
	}
	printf("%d\n", res<inf/2 ? res : -1);
	return 0;
}