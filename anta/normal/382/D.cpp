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
#include <limits>
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
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

const int TopologicalSort_MaxN = 2000*2000;
char ts_color[TopologicalSort_MaxN];
int ts_stk1[TopologicalSort_MaxN+1], ts_stk2[TopologicalSort_MaxN+1];
int ts_order[TopologicalSort_MaxN];

int getedge(int v, int e);

bool topologicalSort(int n) {
	memset(ts_color, 0, n);
	int sp = 0, orderi = 0;
	rep(i, n) if(!ts_color[i]) {
		ts_stk1[sp] = i; ts_stk2[sp ++] = 0;
		while(sp > 0) {
			int v = ts_stk1[sp-1]; int e = ts_stk2[sp-1];
			ts_stk2[sp-1] = e + 1;
			if(e == 0) ts_color[v] = 1;
			int u = getedge(v, e);
			if(u == -2) {
				ts_color[v] = 2;
				ts_order[orderi ++] = v;
				-- sp;
				continue;
			}
			if(u != -1 && ts_color[u] != 2) {
				if(ts_color[u] == 1) return false;
				ts_stk1[sp] = u;
				ts_stk2[sp ++] = 0;
			}
		}
	}
	reverse(ts_order, ts_order + n);
	return true;
}

int n, m;
char board[2000][2001];
int height[2000*2000];

int getedge(int v, int e) {
	if(e >= 1) return -2;
	int y = v / m, x = v % m;
	switch(board[y][x]) {
	case '>': x ++; break;
	case '^': y --; break;
	case 'v': y ++; break;
	case '<': x --; break;
	case '#': return -2;
	}
	return y * m + x;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", board[i]);
	if(!topologicalSort(n * m)) {
		puts("-1");
		return 0;
	}
	mset(height, 0);
	rep(i, n*m) {
		int v = ts_order[i];
		int u = getedge(v, 0);
		if(u != -2)
			height[u] = max(height[u], height[v] + 1);
	}
	vi cs;
	rep(i, n) rep(j, m) if(board[i][j] == '#') {
		int v = i * m + j;
		int h = height[v], cnt = 0;
		if(h == 0) continue;
		static const int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
		rep(d, 4) {
			int yy = i + dy[d], xx = j + dx[d];
			if(yy<0||yy>=n||xx<0||xx>=m) continue;
			if(board[yy][xx] == '#') continue;
			int u = yy * m + xx;
			if(getedge(u, 0) == v && height[u] + 1 == h)
				cs.pb(h), cs.pb(h-1);;
		}
	}
	rep(i, 2) cs.pb(0);
	int ans = 0;
	nth_element(cs.begin(), cs.begin(), cs.end(), greater<int>());
	ans += cs[0];
	nth_element(cs.begin(), cs.begin()+1, cs.end(), greater<int>());
	ans += cs[1];
	cout << ans << endl;
	return 0;
}