#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;


const char *dima = "DIMA";
int n, m;
char board[1000][1001];
char color[1000][1000];
int memo[1000][1000];

bool visit(int i, int j) {
	color[i][j] = 1;
	int k = strchr(dima, board[i][j]) - dima;
	static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
	rep(d, 4) {
		int yy = i + dy[d], xx = j + dx[d];
		if(yy<0||yy>=n||xx<0||xx>=m) continue;
		if(board[yy][xx] != dima[(k+1)%4]) continue;
		if(color[yy][xx] == 2) continue;
		if(color[yy][xx] == 1) return false;
		if(!visit(yy, xx)) return false;
	}
	color[i][j] = 2;
	return true;
}
bool topologicalSort() {
	mset(color, 0);
	rep(i, n) rep(j, m) if (!color[i][j] && !visit(i, j))
		return false;
	return true;
}

int rec(int i, int j) {
	int &r = memo[i][j];
	if(r != -1) return r;
	r = 1;
	int k = strchr(dima, board[i][j]) - dima;
	static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
	rep(d, 4) {
		int yy = i + dy[d], xx = j + dx[d];
		if(yy<0||yy>=n||xx<0||xx>=m) continue;
		if(board[yy][xx] != dima[(k+1)%4]) continue;
		r = max(r, 1 + rec(yy, xx));
	}
	return r;
}

int main() {
	cin >> n >> m;
	rep(i, n) cin >> board[i];
	if(!topologicalSort()) {
		puts("Poor Inna!");
	}else {
		int r = 0;
		mset(memo, -1);
		rep(i, n) rep(j, m) if(board[i][j] == dima[0])
			r = max(r, rec(i, j) / 4);
		if(r == 0) puts("Poor Dima!");
		else cout << r << endl;
	}
	return 0;
}