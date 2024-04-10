#include "bits/stdc++.h"
using namespace std;


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

class SchieberVishkinLCA {
public:
	typedef unsigned Word;
	typedef int Vertex;
private:

	static inline Word lowestOneBit(Word v) {
		return v & (~v + 1);
	}
	static inline Word highestOneBitMask(Word v) {
		v |= v >> 1; v |= v >> 2; v |= v >> 4; v |= v >> 8; v |= v >> 16;
		return v >> 1;
	}

	std::vector<Word> indices;			//Vertex -> index
	std::vector<Word> maxHIndices;		//Vertex -> index
	std::vector<Word> ancestorHeights;	//Vertex -> Word
	std::vector<Vertex> pathParents;	//index-1 -> Vertex
public:

	void build(const std::vector<Vertex> &preorder, const std::vector<Vertex> &parents, Vertex root) {
		Vertex N = static_cast<Vertex>(preorder.size());

		ancestorHeights.resize(N);
		maxHIndices.resize(N);
		indices.resize(N);
		pathParents.resize(N);

		for (Vertex ix = 0; ix < N; ++ ix)
			indices[preorder[ix]] = ix + 1;

		for (Vertex i = 0; i < N; ++ i)
			maxHIndices[i] = indices[i];
		for (Vertex ix = N - 1; ix > 0; -- ix) {
			Vertex v = preorder[ix], parent = parents[v];
			if (lowestOneBit(maxHIndices[parent]) < lowestOneBit(maxHIndices[v]))
				maxHIndices[parent] = maxHIndices[v];
		}

		ancestorHeights[root] = 0;
		for (Vertex ix = 1; ix < N; ++ ix) {
			Vertex v = preorder[ix], parent = parents[v];
			ancestorHeights[v] = ancestorHeights[parent] | lowestOneBit(maxHIndices[v]);
		}

		pathParents[0] = root;
		for (Vertex ix = 1; ix < N; ++ ix) {
			Vertex v = preorder[ix], parent = parents[v];
			if (maxHIndices[v] != maxHIndices[parent])
				pathParents[indices[v] - 1] = parent;
			else
				pathParents[indices[v] - 1] = pathParents[indices[parent] - 1];
		}
	}

	Vertex query(Vertex v, Vertex u) const {
		Word Iv = maxHIndices[v], Iu = maxHIndices[u];
		Word hIv = lowestOneBit(Iv), hIu = lowestOneBit(Iu);
		Word hbMask = highestOneBitMask((Iv ^ Iu) | hIv | hIu);
		Word j = lowestOneBit(ancestorHeights[v] & ancestorHeights[u] & ~hbMask);
		Vertex x, y;
		if (j == hIv) x = v;
		else {
			Word kMask = highestOneBitMask(ancestorHeights[v] & (j - 1));
			x = pathParents[(indices[v] & ~kMask | (kMask + 1)) - 1];
		}
		if (j == hIu) y = u;
		else {
			Word kMask = highestOneBitMask(ancestorHeights[u] & (j - 1));
			y = pathParents[(indices[u] & ~kMask | (kMask + 1)) - 1];
		}
		return indices[x] < indices[y] ? x : y;
	}
};

vector<int> t_parent;
vector<int> t_ord;

void tree_getorder(const vector<vector<int>> &g, int root) {
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

vector<mint> modInverse;

void computeModInverse(int n) {
	n = max(n, 1);
	modInverse.resize(n + 1);
	modInverse[1] = 1;
	for (int i = 2; i <= n; ++ i)
		modInverse[i].x = (long long)modInverse[mint::Mod % i].x * (mint::Mod - mint::Mod / i) % mint::Mod;
}
int main() {
	const int X = 10000000;
	linearSieve(X);
	computeModInverse(X);
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<int> > g(n);
		for (int i = 0; i < n - 1; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tree_getorder(g, 0);
		SchieberVishkinLCA lca;
		lca.build(t_ord, t_parent, 0);
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<int> ppid(X + 1, -1);
		int nIds = 0;
		for (int p : primes) {
			int q = p;
			while (1) {
				ppid[q] = nIds ++;
				if ((long long)q * p > X) break;
				q *= p;
			}
		}
		vector<vector<pair<int, int>>> queries(n);
		Factors fs;
		int q;
		scanf("%d", &q);
		for (int qi = 0; qi < q; ++ qi) {
			int u; int v; int x;
			scanf("%d%d%d", &u, &v, &x), -- u, -- v;
			int w = lca.query(u, v);
			primeFactors(x, fs);
			for (auto f : fs) {
				int q = 1;
				for (int k = 0; k < f.second; ++ k) q *= f.first;
				queries[u].emplace_back(ppid[q], qi * 3 + 0);
				queries[v].emplace_back(ppid[q], qi * 3 + 0);
				queries[w].emplace_back(ppid[q], qi * 3 + 1);
				if(t_parent[w] != -1)
					queries[t_parent[w]].emplace_back(ppid[q], qi * 3 + 2);
			}\
		}
		vector<mint> curProd(nIds, 1);
		vector<mint> ansProds(q * 3, 1);
		vector<pair<int, int>> history;
		function<void(int)> dfs = [&](int i) {
			primeFactors(as[i], fs);
			size_t histstart = history.size();
			for (auto f : fs) {
				int q = 1, r = 1;
				for (int k = 1; ; ++ k) {
					if ((long long)q * f.first > X) break;
					q *= f.first;
					if(k <= f.second) r *= f.first;
					int id = ppid[q];
					curProd[id] *= r;
					history.emplace_back(id, r);
				}
			}
			for (auto q : queries[i])
				ansProds[q.second] *= curProd[q.first];

			for (int j : g[i]) if (t_parent[i] != j)
				dfs(j);

			while (history.size() > histstart) {
				int id, r; tie(id, r) = history.back();
				curProd[id] *= modInverse[r];
				history.pop_back();
			}
		};
		dfs(0);
		for (int i = 0; i < q; ++ i) {
			mint ans = ansProds[i * 3 + 0] / (ansProds[i * 3 + 1] * ansProds[i * 3 + 2]);
			printf("%d\n", ans.get());
		}
	}
}