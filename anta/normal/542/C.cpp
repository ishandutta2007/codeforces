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
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename T>T gcd(T x, T y){if(y==0)return x;else return gcd(y,x%y);}
template<typename T>T lcm(T x, T y){ return x == 0 ? 0 : x/gcd(x,y)*y; }


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
//	while(1){
	int n;
	scanf("%d", &n);
//	n=rand()%8+3;
	vector<int> f(n);
	rep(i, n) scanf("%d", &f[i]), -- f[i];
	vector<vi> g(n);
	rep(i, n) g[i].push_back(f[i]);
	vector<vi> scc;
	stronglyConnectedComponents(g, scc);
	long long l = 1;
	vector<bool> incycle(n, false);
	rep(i, scc.size()) if((int)scc[i].size() > 1 || f[scc[i][0]] == scc[i][0]) {
//		cerr << "cycle: " << scc[i].size() << endl;
		l = lcm(l, (ll)scc[i].size());
		each(j, scc[i])
			incycle[*j] = true;
	}
	int maxd = 1;
	rep(i, n) {
		int d = 0;
		for(int j = i; !incycle[j]; ++ d)
			j = f[j];
		if(d > 0) {
//			cerr << i+1 << ": " << d << endl;
			amax(maxd, d);
		}
	}
	ll ans = (maxd + l - 1) / l * l;
	/*
	int naiveans=0;
	vi v(n),w(n);
	rep(i,n)v[i]=i;
	for(int k=1;;++k) {
		w.swap(v);
		rep(i,n)v[i]=f[w[i]];
		bool ok=true;
		rep(i,n)ok&=v[i]==v[v[i]];
		if(ok){naiveans=k;break;}
	}
	if(ans!=naiveans) {
		rep(i,n)cerr<<f[i]<<",";cerr<<endl;
		cerr<<ans<<"!="<<naiveans<<endl;
	}*/
	cout << ans << endl;
//	}
	return 0;
}