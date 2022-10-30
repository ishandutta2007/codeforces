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
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

void visit(const vector<vector<int> > &g, int v, vector< vector<int> >& scc,
		vector<int> &S, vector<char> &inS,
		vector<int> &low, vector<int> &num, int& time) {
	low[v] = num[v] = ++time;
	S.push_back(v); inS[v] = true;
	each(e, g[v]) {
		int w = *e;
		if (num[w] == 0) {
			visit(g, w, scc, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		} else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		scc.push_back(vector<int>());
		while (1) {
			int w = S.back(); S.pop_back(); inS[w] = false;
			scc.back().push_back(w);
			if (v == w) break;
		}
	}
}
void stronglyConnectedComponents(const vector<vector<int> >& g,
		vector< vector<int> >& scc) {
	const int n = g.size();
	vector<int> num(n), low(n);
	vector<int> S;
	vector<char> inS(n);
	int time = 0;
	rep(u, n) if (num[u] == 0)
		visit(g, u, scc, S, inS, low, num, time);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char *s = new char[n+1], *t = new char[m+1];
	scanf("%s", s);
	scanf("%s", t);
	vector<vi> g(n * m);
	rep(y, n) rep(x, m) {
		{	int yy = y, xx = x + (s[y] == '>' ? +1 : -1);
			if(!(yy < 0 || yy >= n || xx < 0 || xx >= m))
				g[y * m + x].push_back(yy * m + xx);
		}
		{	int yy = y + (t[x] == 'v' ? +1 : -1), xx = x;
			if(!(yy < 0 || yy >= n || xx < 0 || xx >= m))
				g[y * m + x].push_back(yy * m + xx);
		}
	}
	vector<vi> scc;
	stronglyConnectedComponents(g, scc);
	int ans = scc.size() == 1;
	puts(ans ? "YES" : "NO");
	return 0;
}