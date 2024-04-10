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
#include <bitset>
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

struct GetStrID {
	static const int MaxLen = 500001;	//
	static const int Alphas = 26;	//
	typedef char Alpha;
	static const int EndAlpha = -1;

private:
	template<typename T>
	struct Trie {
		bool terminate;
		T val;
		Trie<T> *next[Alphas];

		Trie(): terminate(false) { memset(next, 0, sizeof(next)); }
		~Trie() { for(Alpha a = 0; a < Alphas; ++ a) delete next[a]; }

		void insert(Alpha *s, const T &v) {
			if(*s == EndAlpha) {
				terminate = true;
				val = v;
				return;
			}else {
				if(!next[*s])
					next[*s] = new Trie;
				return next[*s]->insert(s+1, v);
			}
		}
		bool find(Alpha *s, T &out_v) const {
			if(*s == EndAlpha) {
				if(terminate) {
					out_v = val;
					return true;
				}else return false;
			}
			return next[*s] && next[*s]->find(s+1, out_v);
		}
	};

public:
	GetStrID(const char *alphas): cnt(0) {
		assert(strlen(alphas) <= Alphas);
		memset(idx, -1, sizeof(idx));
		for(const char *p = alphas; *p; ++ p)
			idx[*p] = p - alphas;
	}
	char idx[128];
	Trie<int> trie;
	int cnt;
	vector<int> lengths, weights;

	void clear() {
		trie = Trie<int>(); cnt = 0;
		lengths.clear();
		weights.clear();
	}
	int get(const char *x) {
		static char tmp[MaxLen+1];
		{	int i;
			for(i = 0; x[i]; i ++) tmp[i] = idx[x[i]];
			tmp[i] = EndAlpha;
		}
		int ret = -1;
		if(!trie.find(tmp, ret)) {
			lengths.push_back(strlen(x));
			weights.push_back(count(x, x + lengths.back(), 'r'));
			ret = cnt ++;
			trie.insert(tmp, ret);
		}
		return ret;
	}
	int size() const { return cnt; }

	int getlen(int i) const { return lengths[i]; }
	int getweight(int i) const { return weights[i]; }
};

void visit(const vector<vector<int> > &g, int v,
		vector<int> &scccolor, int &colors,
		vector<int> &S, vector<char> &inS,
		vector<int> &low, vector<int> &num, int& time) {
	low[v] = num[v] = ++time;
	S.push_back(v); inS[v] = true;
	each(e, g[v]) {
		int w = *e;
		if (num[w] == 0) {
			visit(g, w, scccolor, colors, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		} else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		while (1) {
			int w = S.back(); S.pop_back(); inS[w] = false;
			scccolor[w] = colors;
			if (v == w) break;
		}
		colors ++;
	}
}
int stronglyConnectedComponents(const vector<vector<int> >& g,
		vector<int>& scccolor) {
	const int n = g.size();
	vector<int> num(n), low(n);
	vector<int> S;
	vector<char> inS(n);
	scccolor.resize(n);
	int time = 0, colors = 0;
	rep(u, n) if (num[u] == 0)
		visit(g, u, scccolor, colors, S, inS, low, num, time);
	return colors;
}

void constructCondensation(const vector<vi> &g, const vector<int> &col, int S, vector<vi> &h) {
	h.assign(S, vi());
	int n = g.size();
	rep(i, n) each(j, g[i]) if(col[i] != col[*j])
		h[col[i]].pb(col[*j]);
}

bool topologicalSort(const vector<vi> &g, vi &ord) {
	int n = g.size();
	vi deg(n);
	rep(i, n) each(j, g[i]) deg[*j] ++;
	ord.assign(n, -1);
	int t = 0;
	rep(i, n) if(deg[i] == 0) ord[t ++] = i;
	for(int h = 0; h < t; h ++) {
		int v = ord[h];
		each(j, g[v])
			if(-- deg[*j] == 0)
				ord[t ++] = *j;
	}
	return t == n;
}




int main() {
	int m;
	scanf("%d", &m);
	char *e = new char[200001];
	GetStrID id("abcdefghijklmnopqrstuvwxyz");
	vector<int> es(m);
	rep(i, m) {
		scanf("%s", e);
		for(char *p = e; *p; ++ p)
			*p = tolower(*p);
		es[i] = id.get(e);
	}
	int n;
	scanf("%d", &n);
	char *x = new char[500001], *y = new char[500001];
	vector<int> xs(n), ys(n);
	rep(i, n) {
		scanf("%s%s", x, y);
		for(char *p = x; *p; ++ p)
			*p = tolower(*p);
		for(char *p = y; *p; ++ p)
			*p = tolower(*p);
		xs[i] = id.get(x);
		ys[i] = id.get(y);
	}
	int V = id.size();
	vector<vi> g(V);
	rep(i, n)
		g[xs[i]].push_back(ys[i]);
	vector<int> col(g.size());
	int S = stronglyConnectedComponents(g, col);
	vector<vi> h;
	constructCondensation(g, col, S, h);
	vector<int> ord;
	topologicalSort(h, ord);
	vector<pii> weights(S, pii(INF, INF));
	rep(i, g.size())
		amin(weights[col[i]], mp(id.getweight(i), id.getlen(i)));
	for(int ix = ord.size() - 1; ix >= 0; -- ix) {
		int i = ord[ix];
		each(j, h[i])
			amin(weights[i], weights[*j]);
	}
	long long ans1 = 0, ans2 = 0;
	rep(i, m) {
		pii p = weights[col[es[i]]];
		ans1 += p.first;
		ans2 += p.second;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}