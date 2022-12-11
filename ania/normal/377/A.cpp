#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int px[4] = {1,0,-1,0}, py[4] = {0,1,0,-1};
int n,m;
char v[555][555];
int lft;

void dfs(int x, int y) {
	if (lft == 0) return;
	v[x][y] = '.';
	lft--;
	if (lft == 0) return;
	FOR(k,4) {
		int nx = x+px[k], ny = y+py[k];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (v[nx][ny] == 'X') dfs(nx,ny);
	}
}

int main() {
	int k, s=0;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,n) scanf("%s", v[i]);
	FOR(i,n) FOR(j,m) if (v[i][j] == '.') {
		v[i][j] = 'X';
		s++;
	}
	lft = s-k;
	FOR(i,n) FOR(j,m) if (v[i][j] == 'X') {
		dfs(i,j);
		FOR(q,n) printf("%s\n", v[q]);
		return 0;
	}
	return 0;
}