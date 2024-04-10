#include "bits/stdc++.h"
using namespace std;


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

void tree_getorder(const vector<vector<int>> &g, int root) {
	int n = (int)g.size();
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

struct GCDQuery {
	struct Decomposition {
		int x, y;
		int p, ppi;
	};
	int N, sqrtN;
	vector<int> smallTable, smallTable2;
	vector<Decomposition> decomposition;
	vector<int> primePowers;
	void init(const vector<int> &smallestPrimeFactor) {
		int N = (int)smallestPrimeFactor.size() - 1;
		int sqrtN = (int)sqrt(double(N));
		this->N = N, this->sqrtN = sqrtN;

		primePowers.clear();
		primePowers.push_back(1);
		for (int p = 2; p <= sqrtN; ++ p) if(smallestPrimeFactor[p] == p) {
			int q = p;
			while (1) {
				primePowers.push_back(q);
				if ((long long)q * p > N) break;
				q *= p;
			}
		}
		int numSmallPPs = (int)primePowers.size();

		vector<int> ppIndex(N + 1, -1);
		for (int i = 0; i < numSmallPPs; ++ i)
			ppIndex[primePowers[i]] = i;

		struct NextDivisor {
			int x;
			int p, q;
		};
		vector<NextDivisor> nextDivisor(N + 1);
		nextDivisor[1] = { 1, 1, 0 };
		for (int i = 2; i <= N; ++ i) {
			int p = smallestPrimeFactor[i];
			int j = i / p, q = p;
			while (j % p == 0) j /= p, q *= p;
			nextDivisor[i] = { j, p, q };
		}

		decomposition.resize(N + 1);
		for (int i = 0; i <= sqrtN; ++ i)
			decomposition[i] = { i, 1, 1, 0 };
		for (int i = sqrtN + 1; i <= N; ++ i) {
			int x = i, y = 1;
			while (1) {
				auto t = nextDivisor[x];
				if (t.x <= sqrtN) break;
				x = t.x;
				y *= t.q;
			}
			assert(y <= sqrtN);
			auto t = nextDivisor[x];
			decomposition[i] = { t.x, y, t.p, ppIndex[t.q] };
		}

		smallTable.resize((sqrtN + 1) * (sqrtN + 1));
		for (int b = 0; b <= sqrtN; ++ b)
			smallTable[ix2(0, b)] = b;
		for (int a = 1; a <= sqrtN; ++ a) for (int b = 0; b <= sqrtN; ++ b)
			smallTable[ix2(a, b)] = smallTable[ix2(b % a, a)];

		smallTable2.assign(numSmallPPs * (sqrtN + 1), 1);
		for (int ppi = 1; ppi < numSmallPPs; ++ ppi) {
			int q = primePowers[ppi];
			int p = smallestPrimeFactor[q];
			for (int qq = p; ; qq *= p) {
				for (int b = 0; b <= sqrtN; b += qq)
					smallTable2[ix2(ppi, b)] = qq;
				if (qq == q) break;
			}
		}
	}

	int gcd(int a, int b) const {
		assert(a <= N && b <= N);
		if (a == 0 || b == 0) return a + b;
		auto da = decomposition[a];
		auto db = decomposition[b];
		int res = 1;
		res *= gcdSmall(da.x, db.x);
		res *= gcdSmall(da.x, db.y);
		res *= gcdSmall(da.y, db.x);
		res *= gcdSmall(da.y, db.y);
		if (da.p == db.p) {
			if (da.ppi > 0)
				res *= primePowers[min(da.ppi, db.ppi)];
			else
				res *= da.p;
		} else {
			if (da.ppi > 0) {
				res *= gcdPP(da.ppi, db.x);
				res *= gcdPP(da.ppi, db.y);
			}
			if (db.ppi > 0) {
				res *= gcdPP(db.ppi, da.x);
				res *= gcdPP(db.ppi, da.y);
			}
		}
		return res;
	}

private:
	int gcdSmall(int a, int b) const {
		return smallTable[ix2(a, b)];
	}

	int gcdPP(int ppi, int b) const {
		return smallTable2[ix2(ppi, b)];
	}

	int ix2(int i, int j) const { return i * (sqrtN + 1) + j; }
};

int main() {
	struct VertexAttr {
		int a;
		VertexAttr() {}
		VertexAttr(int a) : a(a) {}
	};
	struct EdgeAttr {};

	int n;
	while (~scanf("%d", &n)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		int A = *max_element(as.begin(), as.end());
		linearSieve(A);
		vector<vector<int>> divisors(A + 1);
		for (int a = 1; a <= A; ++ a) for (int b = a; b <= A; b += a)
			divisors[b].push_back(a);
		GCDQuery gcd;
		gcd.init(smallestPrimeFactor);
		vector<long long> ans(A + 1, 0);
		vector<int> cnt(A + 1, 0);
		vector<int> values;
		CentroidDecomposition<VertexAttr, EdgeAttr> cd;
		cd.init(t_ord, t_parent, vector<VertexAttr>(as.begin(), as.end()), vector<EdgeAttr>(n), vector<EdgeAttr>(n));
		do {
			vector<pair<int, int>> tmpStack;
			vector<CentroidDecomposition<VertexAttr, EdgeAttr>::DfsEntry> ord;
			vector<int> bounds;
			vector<int> gcds;
			for (int si = 0; si < cd.numCurrentSubtrees(); ++ si) {
				cd.getDfsOrder(si, ord, tmpStack);
				gcds.resize(ord.size());
				gcds[0] = ord[0].a;
				bounds.clear();
				bounds.push_back(0);
				for (int ix = 1; ix < (int)ord.size(); ++ ix) {
					const auto &entry = ord[ix];
					gcds[ix] = gcd.gcd(gcds[entry.px], entry.a);
					if (entry.px == 0)
						bounds.push_back(ix);
				}
				bounds.push_back((int)ord.size());
				auto add = [&](int L, int R, int sign) {
					for (int ix = L; ix < R; ++ ix) {
						for(int a : divisors[gcds[ix]])
							if(cnt[a] ++ == 0)
								values.push_back(a);
					}
					for (int a : values) {
						ans[a] += sign * ((long long)cnt[a] * (cnt[a] + 1) / 2);
						cnt[a] = 0;
					}
					values.clear();
				};
				add(0, bounds.back(), 1);
				for (int bi = 1; bi < (int)bounds.size() - 1; ++ bi) {
					int L = bounds[bi], R = bounds[bi + 1];
					add(L, R, -1);
				}
			}
		} while (cd.makeNextLevel());
		for (int p : primes) {
			for (int i = 1, a = p; a <= A; ++ i, a += p)
				ans[i] -= ans[a];
		}
		for (int a = 1; a <= A; ++ a) if(ans[a] > 0)
			printf("%d %lld\n", a, ans[a]);
	}
}