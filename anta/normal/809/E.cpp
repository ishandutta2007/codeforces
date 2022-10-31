#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) { }
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1000000007> mint;

vector<int> primes;
vector<int> smallestPrimeFactor;
void linearSieve(int n) {
	if (n < 1) n = 1;
	if ((int)smallestPrimeFactor.size() >= n + 1) return;
	int primePiBound = n < 20 ? n - 1 : (int)(n / (log(n * 1.) - 2) + 2);
	primes.assign(primePiBound + 1, numeric_limits<int>::max());
	int P = 0;
	smallestPrimeFactor.assign(n + 1, 0);
	smallestPrimeFactor[1] = 1;
	int n2 = n / 2, n3 = n / 3, n5 = n / 5;
	if (n >= 2)
		primes[P ++] = 2;
	if (n >= 3)
		primes[P ++] = 3;
	for (int q = 2; q <= n; q += 2)
		smallestPrimeFactor[q] = 2;
	for (int q = 3; q <= n; q += 6)
		smallestPrimeFactor[q] = 3;
	for (int q = 5; q <= n5; q += 2) {
		if (smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
		int bound = smallestPrimeFactor[q];
		for (int i = 2; ; ++ i) {
			int p = primes[i];
			if (p > bound) break;
			int pq = p * q;
			if (pq > n) break;
			smallestPrimeFactor[pq] = p;
		}
	}
	for (int q = (n5 + 1) | 1; q <= n; q += 2) {
		if (smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
	}
	primes.resize(P);
}

typedef int FactorsInt;
typedef vector<pair<FactorsInt, int> > Factors;
void primeFactors(FactorsInt x, Factors &out_v) {
	linearSieve(x);
	out_v.clear();
	while (x != 1) {
		int p = smallestPrimeFactor[x], k = 0;
		x /= p, k ++;
		while (x % p == 0) x /= p, k ++;
		out_v.push_back(make_pair(p, k));
	}
}

template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y); }


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
		for (int ix = n - 1; ix >= 0; -- ix) {
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
			if (maxf < fi)
				maxf = fi;
			unsigned S = (a[i] & ~(fi - 1)) | fi;
			if (p != -1) {
				b[p] |= a[p] & S;
				a[p] |= S;
			}
		}
		eulerTour(t_ord, t_parent, vertexAttrs, upEdgeAttrs, downEdgeAttrs, f, _tour);
		_currentLevel = 0;
		while (maxf >> 1 >> _currentLevel) ++ _currentLevel;
		_subtrees.assign(_currentLevel + 1, vector<pair<int, int> >());
		if (_currentLevel != 0) {
			int middle = 1;
			while (_tour[middle].f != maxf) ++ middle;
			std::rotate(_tour.begin() + 1, _tour.begin() + (middle + 1), _tour.end());
		}
		_subtrees[_currentLevel].assign(1, make_pair(1, (n - 1) * 2 + 1));
	}

	bool makeNextLevel() {
		if (_currentLevel == 0) return false;
		unsigned lv = 1U << (_currentLevel - 1);
		const vector<pair<int, int> > &currentSubtrees = _subtrees[_currentLevel];
		for (int si = 0; si < (int)currentSubtrees.size(); ++ si) {
			int L = currentSubtrees[si].first, R = currentSubtrees[si].second;
			int nextL = L + 1;
			unsigned nextLevel = 0;
			int nextMiddle = -1;
			for (int ix = L; ix < R; ++ ix) {
				unsigned f = _tour[ix].f;
				if (f > lv) {
					std::rotate(_tour.begin() + nextL, _tour.begin() + nextMiddle, _tour.begin() + ix);
					int k = _currentLevel;
					while (nextLevel != (1U << k)) -- k;
					_subtrees[k].push_back(make_pair(nextL, ix));
					nextL = ix + 2;
					nextLevel = 0;
					nextMiddle = -1;
				} else if (nextLevel < f) {
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
		for (int tx = L; tx < R - 1; ++ tx) {
			int id = _tour[tx].id;
			if (id == tmpStack[sp - 2].first) {
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
		for (int si = 0; si < (int)currentSubtrees.size(); ++ si) {
			int L = currentSubtrees[si].first, R = currentSubtrees[si].second;
			if (L == R)
				cerr << "[" << (L == 0 ? 0 : _tour[L - 1].id) << "]";
			for (int ix = L; ix < R; ++ ix) {
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
		for (int ix = 1; ix <= n; ++ ix) {
			int p = ix < n ? t_parent[t_ord[ix]] : root;
			while (i != p) {
				EdgeAttr w = upEdgeAttrs[i];
				i = t_parent[i];
				tour.push_back(TourEntry(Vertex(i, vertexAttrs[i]), w, f[i]));
			}
			if (ix < n) {
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


vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_ord.clear();

	vector<int> stk; stk.push_back(root);
	while (!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		t_ord.push_back(i);
		for (int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if (t_parent[c] == -1 && c != root) {
				t_parent[c] = i;
				stk.push_back(c);
			}
		}
	}
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		linearSieve(n);
		vector<int> mu(n + 1);
		mu[1] = 1;
		rer(i, 2, n) {
			int p = smallestPrimeFactor[i];
			mu[i] = i / p % p == 0 ? 0 : -mu[i / p];
		}
		vector<int> nextDivisor(n + 1);
		nextDivisor[1] = 1;
		rer(i, 2, n) {
			int p = smallestPrimeFactor[i];
			int j = i / p;
			while (j % p == 0) j /= p;
			nextDivisor[i] = j;
		}
		vector<mint> den(n + 1), iden(n + 1);
		den[1] = iden[1] = 1;
		rer(i, 2, n) {
			int p = smallestPrimeFactor[i];
			iden[i] = iden[nextDivisor[i]] * (mint(1) - mint(p).inverse());
			den[i] = iden[i].inverse();
		}
		vector<mint> coeffs(n + 1);
		vector<vi> divisors(n + 1);
		rer(i, 1, n) for (int j = i, k = 1; j <= n; j += i, ++ k) {
			coeffs[j] += den[i] * mu[k];
			divisors[j].push_back(i);
		}
		mint ans;
		tree_getorder(g, 0);
		struct VertexAttr {};
		struct EdgeAttr {};
		CentroidDecomposition<VertexAttr, EdgeAttr> cd;
		cd.init(t_ord, t_parent, vector<VertexAttr>(n), vector<EdgeAttr>(n), vector<EdgeAttr>(n));
		do {
			vector<pair<int, int>> tmpStack;
			vector<CentroidDecomposition<VertexAttr, EdgeAttr>::DfsEntry> ord;
			vector<int> depth;
			vi bounds;
			vector<mint> sum0(n + 1), sum1(n + 1);
			rep(si, cd.numCurrentSubtrees()) {
				cd.getDfsOrder(si, ord, tmpStack);
				depth.resize(ord.size());
				depth[0] = 0;
				bounds.clear();
				bounds.push_back(0);
				for (int ix = 1; ix < (int)ord.size(); ++ ix) {
					const auto &entry = ord[ix];
					depth[ix] = depth[entry.px] + 1;
					if (entry.px == 0)
						bounds.push_back(ix);
				}
				bounds.push_back((int)ord.size());
				rep(bi, (int)bounds.size() - 1) {
					reu(ix, bounds[bi], bounds[bi + 1]) {
						int i = ord[ix].id;
						mint c1 = mint(a[i]) * iden[a[i]], c0 = c1 * depth[ix];
						for (int d : divisors[a[i]])
							ans += (c0 * sum0[d] + c1 * sum1[d]) * coeffs[d];
					}
					reu(ix, bounds[bi], bounds[bi + 1]) {
						int i = ord[ix].id;
						mint x0 = mint(a[i]) * iden[a[i]], x1 = x0 * depth[ix];
						for (int d : divisors[a[i]]) {
							sum0[d] += x0;
							sum1[d] += x1;
						}
					}
				}
				rep(ix, ord.size()) {
					int i = ord[ix].id;
					for (int d : divisors[a[i]])
						sum0[d] = sum1[d] = mint();
				}
			}
		} while (cd.makeNextLevel());
		ans *= 2;
		ans /= (ll)n * (n - 1);
		printf("%d\n", ans.get());
	}
	return 0;
}