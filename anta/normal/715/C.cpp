#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct GModInt {
	static int Mod;
	unsigned x;
	GModInt() : x(0) {}
	GModInt(signed sig) { int sigt = sig % Mod; if(sigt < 0) sigt += Mod; x = sigt; }
	GModInt(signed long long sig) { int sigt = sig % Mod; if(sigt < 0) sigt += Mod; x = sigt; }
	int get() const { return (int)x; }

	GModInt &operator+=(GModInt that) { if((x += that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator-=(GModInt that) { if((x += Mod - that.x) >= (unsigned)Mod) x -= Mod; return *this; }
	GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }
	GModInt &operator/=(GModInt that) { return *this *= that.inverse(); }

	GModInt operator+(GModInt that) const { return GModInt(*this) += that; }
	GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }
	GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }
	GModInt operator/(GModInt that) const { return GModInt(*this) /= that; }

	GModInt inverse() const {
		signed a = x, b = Mod, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		GModInt res; res.x = (unsigned)u;
		return res;
	}
};
int GModInt::Mod = 0;
typedef GModInt mint;

vector<int> t_parent;
vi t_ord;

template<typename T>
void wtree_getorder(const vector<vector<pair<int, T> > > &gw, int root, vector<T> &t_weight) {
	int n = (int)gw.size();
	t_parent.assign(n, -1);
	t_ord.clear();
	t_weight.assign(n, T());

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for(int j = (int)gw[i].size() - 1; j >= 0; j --) {
			int c = gw[i][j].first;
			if(t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				t_weight[c] = gw[i][j].second;
				stk.push_back(c);
			}
		}
	}
}


template<typename VertexAttr, typename EdgeAttr>
class CentroidDecomposition {
public:
	struct Vertex : VertexAttr {
		int id;

		Vertex() {}
		Vertex(int id, VertexAttr attr) : id(id), VertexAttr(attr) {}
	};

	struct VertexAndEdge : Vertex, EdgeAttr {
		VertexAndEdge() {}
		VertexAndEdge(Vertex vertex, EdgeAttr edgeAttr) : Vertex(vertex), EdgeAttr(edgeAttr) {}
	};

	struct TourEntry : VertexAndEdge {
		unsigned f;

		TourEntry() {}
		TourEntry(Vertex to, EdgeAttr edgeAttr, unsigned f) :
			VertexAndEdge(to, edgeAttr), f(f) {
		}
	};

	struct DfsEntry : VertexAndEdge {
		int px;
		DfsEntry() {}
		DfsEntry(VertexAndEdge vertexAndEdge, int px) :
			VertexAndEdge(vertexAndEdge), px(px) {
		}
	};

	void init(
		const vector<int> &t_ord, const vector<int> &t_parent,
		const vector<VertexAttr> &vertexAttrs,
		const vector<EdgeAttr> &upEdgeAttrs,
		const vector<EdgeAttr> &downEdgeAttrs) {
		int n = (int)t_ord.size();
		vector<unsigned> a(n), b(n), f(n);
		unsigned maxf = 0;
		for(int ix = n - 1; ix >= 0; -- ix) {
			int i = t_ord[ix], p = t_parent[i];
			unsigned m = b[i];
			m |= m >> 1;
			m |= m >> 2;
			m |= m >> 4;
			m |= m >> 8;
			m |= m >> 16;
			unsigned fi = ~(a[i] | m);
			fi &= ~fi + 1;
			f[i] = fi;
			if(maxf < fi)
				maxf = fi;
			unsigned S = (a[i] & ~(fi - 1)) | fi;
			if(p != -1) {
				b[p] |= a[p] & S;
				a[p] |= S;
			}
		}
		eulerTour(t_ord, t_parent, vertexAttrs, upEdgeAttrs, downEdgeAttrs, f, _tour);
		_currentLevel = 0;
		while(maxf >> 1 >> _currentLevel) ++ _currentLevel;
		_subtrees.assign(_currentLevel + 1, vector<pair<int, int> >());
		if(_currentLevel != 0) {
			int middle = 1;
			while(_tour[middle].f != maxf) ++ middle;
			std::rotate(_tour.begin() + 1, _tour.begin() + (middle + 1), _tour.end());
		}
		_subtrees[_currentLevel].assign(1, make_pair(1, (n - 1) * 2 + 1));
	}

	bool makeNextLevel() {
		if(_currentLevel == 0) return false;
		unsigned lv = 1U << (_currentLevel - 1);
		const vector<pair<int, int> > &currentSubtrees = _subtrees[_currentLevel];
		for(int si = 0; si < (int)currentSubtrees.size(); ++ si) {
			int L = currentSubtrees[si].first, R = currentSubtrees[si].second;
			int nextL = L + 1;
			unsigned nextLevel = 0;
			int nextMiddle = -1;
			for(int ix = L; ix < R; ++ ix) {
				unsigned f = _tour[ix].f;
				if(f > lv) {
					std::rotate(_tour.begin() + nextL, _tour.begin() + nextMiddle, _tour.begin() + ix);
					int k = _currentLevel;
					while(nextLevel != (1U << k)) -- k;
					_subtrees[k].push_back(make_pair(nextL, ix));
					nextL = ix + 2;
					nextLevel = 0;
					nextMiddle = -1;
				} else if(nextLevel < f) {
					nextLevel = f;
					nextMiddle = ix + 1;
				}
			}
		}
		-- _currentLevel;
		return true;
	}

	int currentLevel() const { return _currentLevel; }
	int numCurrentSubtrees() const { return (int)_subtrees[_currentLevel].size(); }

	void getDfsOrder(int si, vector<DfsEntry> &ord, vector<pair<int, int> > &tmpStack) const {
		assert(0 <= si && si < numCurrentSubtrees());
		tmpStack.resize(_tour.size() / 2 + 2);
		pair<int, int> subtree = _subtrees[_currentLevel][si];
		int L = subtree.first, R = subtree.second;
		ord.clear();
		ord.push_back(DfsEntry(VertexAndEdge((Vertex)(VertexAndEdge)_tour[R - 1], EdgeAttr()), -1));
		int sp = 1;
		tmpStack[0] = make_pair(-1, -1);
		tmpStack[sp ++] = make_pair(_tour[R - 1].id, 0);
		for(int tx = L; tx < R - 1; ++ tx) {
			int id = _tour[tx].id;
			if(id == tmpStack[sp - 2].first) {
				-- sp;
			} else {
				int px = tmpStack[sp - 1].second;
				int ix = (int)ord.size();
				tmpStack[sp ++] = make_pair(id, ix);
				ord.push_back(DfsEntry(_tour[tx], px));
			}
		}
	}

	void debugShow() const {
		cerr << "level " << _currentLevel << ":\n";
		const vector<pair<int, int> > &currentSubtrees = _subtrees[_currentLevel];
		for(int si = 0; si < (int)currentSubtrees.size(); ++ si) {
			int L = currentSubtrees[si].first, R = currentSubtrees[si].second;
			if(L == R)
				cerr << "[" << (L == 0 ? 0 : _tour[L - 1].id) << "]";
			for(int ix = L; ix < R; ++ ix) {
				cerr << _tour[ix].id << ", ";
			}
			cerr << '\n';
		}
	}

private:
	static void eulerTour(
		const vector<int> &t_ord, const vector<int> &t_parent,
		const vector<VertexAttr> &vertexAttrs,
		const vector<EdgeAttr> &upEdgeAttrs,
		const vector<EdgeAttr> &downEdgeAttrs,
		const vector<unsigned> &f, vector<TourEntry> &tour) {
		int n = (int)t_ord.size();
		tour.clear(); tour.reserve((n - 1) * 2 + 1);
		int root = t_ord[0], i = root;
		//a kind of sentinel
		tour.push_back(TourEntry(Vertex(root, vertexAttrs[root]), EdgeAttr(), f[root]));
		for(int ix = 1; ix <= n; ++ ix) {
			int p = ix < n ? t_parent[t_ord[ix]] : root;
			while(i != p) {
				EdgeAttr w = upEdgeAttrs[i];
				i = t_parent[i];
				tour.push_back(TourEntry(Vertex(i, vertexAttrs[i]), w, f[i]));
			}
			if(ix < n) {
				i = t_ord[ix];
				EdgeAttr w = downEdgeAttrs[i];
				tour.push_back(TourEntry(Vertex(i, vertexAttrs[i]), w, f[i]));
			}
		}
		assert(tour.size() == (n - 1) * 2 + 1);
	}

private:
	int _currentLevel;
	vector<TourEntry> _tour;
	vector<vector<pair<int, int> > > _subtrees;
};



struct VertexAttr {};
struct EdgeAttr { mint digit; };
struct Sum {
	mint numF, numB;
	mint p10, ip10;
};

ll solve(vector<Sum>::iterator begin, vector<Sum>::iterator end) {
	const auto cmp = [](const Sum &a, const Sum &b) {
		return a.numB.get() < b.numB.get();
	};
	sort(begin, end, cmp);
	ll res = 0;
	for(auto it = begin; it != end; ++ it) {
		mint val = (mint() - it->numF) * it->ip10;
		auto range = equal_range(begin, end, Sum{ mint(),val,mint(),mint() }, cmp);
		res += range.second - range.first;
	}
	return res;
}

int main() {
	//
	int n; int M;
	while(~scanf("%d%d", &n, &M)) {
		mint::Mod = M;
		vector<vector<int> > g(n);
		vector<vector<pair<int, EdgeAttr> > > gw(n);
		for(int i = 0; i < n - 1; ++ i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			g[u].push_back(v);
			g[v].push_back(u);
			gw[u].push_back(make_pair(v, EdgeAttr{ w }));
			gw[v].push_back(make_pair(u, EdgeAttr{ w }));
		}
		vector<EdgeAttr> digit;
		wtree_getorder(gw, 0, digit);
		CentroidDecomposition<VertexAttr, EdgeAttr> cd;
		cd.init(t_ord, t_parent, vector<VertexAttr>(n), digit, digit);
		const mint Ten = 10, InvTen = Ten.inverse();
		ll ans = 0;
		do{
			vector<pair<int, int>> tmpStack;
			vector<CentroidDecomposition<VertexAttr, EdgeAttr>::DfsEntry> ord;
			vector<Sum> sums;
			vi bounds;
			rep(si, cd.numCurrentSubtrees()) {
				cd.getDfsOrder(si,ord, tmpStack);
				sums.resize(ord.size());
				sums[0] = { mint(), mint(), mint(1), mint(1) };
				bounds.clear();
				bounds.push_back(0);
				ll cnt = 0;
				for(int ix = 1; ix < (int)ord.size(); ++ ix) {
					const auto &entry = ord[ix];
					const auto &psum = sums[entry.px];
					auto &isum = sums[ix];
					mint d = entry.digit;
					isum = {
						psum.numF * Ten + d,
						psum.numB + d * psum.p10,
						psum.p10 * Ten,
						psum.ip10 * InvTen
					};
					if(entry.px == 0)
						bounds.push_back(ix);
				}
				bounds.push_back((int)ord.size());
				rep(bi, bounds.size() - 1)
					cnt -= solve(sums.begin() + bounds[bi], sums.begin() + bounds[bi + 1]);
				cnt += solve(sums.begin(), sums.end());
				ans += cnt;
			}
		} while(cd.makeNextLevel());
		printf("%lld\n", ans);
	}
	return 0;
}