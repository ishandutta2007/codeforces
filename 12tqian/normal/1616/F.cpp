#include <bits/stdc++.h>

using namespace std;

template <class D> struct Matrix : std::vector<std::vector<D>> {
	using std::vector<std::vector<D>>::vector;

	int h() const { return int(this->size()); }
	int w() const { return int((*this)[0].size()); }

	Matrix operator*(const Matrix& r) const {
		assert(w() == r.h());
		Matrix res(h(), std::vector<D>(r.w()));
		for (int i = 0; i < h(); i++) {
			for (int j = 0; j < r.w(); j++) {
				for (int k = 0; k < w(); k++) {
					res[i][j] += (*this)[i][k] * r[k][j];
				}
			}
		}
		return res;
	}

	Matrix<D>& operator+=(const Matrix& r) {
		assert(h() == r.h() && w() == r.w());
		for (int i = 0; i < h(); i++) {
			for (int j = 0; j < h(); j++) {
				(*this)[i][j] += r[i][j];
			}
		}
		return *this;
	}

	Matrix& operator-=(const Matrix& r) {
		assert(h() == r.h() && w() == r.w());
		for (int i = 0; i < h(); i++) {
			for (int j = 0; j < h(); j++) {
				(*this)[i][j] -= r[i][j];
			}
		}
		return *this;
	}

	Matrix operator*(const D& r) const {
		Matrix res = (*this);
		for (int i = 0; i < h(); ++i) {
			for (int j = 0; j < w(); ++j) {
				res[i][j] *= r;
			}
		}
		return res;
	}

	Matrix operator/(const D &r) const{ return *this * (1 / r); }
	Matrix& operator*=(const Matrix& r) { return *this = *this * r; }
	Matrix operator+(const Matrix& r) { return *this += r; }
	Matrix operator-(const Matrix& r) { return *this -= r; }
	Matrix& operator*=(const D& r) { return *this = *this * r; }
	Matrix& operator/=(const D &r) { return *this = *this / r; }
	friend Matrix operator*(const D& r, Matrix m) { return m *= r; }

	Matrix pow(long long n) const {
		assert(h() == w());
		Matrix x = *this, r(h(), std::vector<D>(w()));
		for (int i = 0; i < h(); i++) r[i][i] = D(1);
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
};

namespace MatrixOperations {

template <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c)); }

template <class D> int get_row(Matrix<D>& m, int r, int i, int nxt, const D& EPS = -1) {
	std::pair<D, int> best = {0, -1};
	for (int j = nxt; j < r; j++) {
		if (EPS == D(-1) && m[j][i] != 0) {
			return j;
		}
		auto v = m[j][i];
		if (v < 0) v = -v;
		best = std::max(best, std::make_pair(v, j));
	}
	return best.first < EPS ? -1 : best.second;
}

// returns a pair of determinant, rank, while doing Gaussian elimination to m
template <class D> std::pair<D, int> gauss(Matrix<D>& m, const D& EPS = -1) {
	int r = m.h();
	int c = m.w();
	int rank = 0, nxt = 0;
	D prod = 1;
	for (int i = 0; i < r; i++) {
		int row = get_row(m, r, i, nxt, EPS);
		if (row == -1) {
			prod = 0;
			continue;
		}
		if (row != nxt) {
			prod *= -1;
			m[row].swap(m[nxt]);
		}
		prod *= m[nxt][i];
		rank++;
		D x = 1 / m[nxt][i];
		for (int k = i; k < c; k++) 
			m[nxt][k] *= x;
		for (int j = 0; j < r; j++) {
			if (j != nxt) {
				D v = m[j][i];
				if (v == 0) continue;
				for (int k = i; k < c; k++) {
					m[j][k] -= v * m[nxt][k];
				}
			}
		}
		nxt++;
	}
	return {prod, rank};
}

template <class D> Matrix<D> inv(Matrix<D> m, const D& EPS = -1) {
	int r = m.h();
	assert(m.h() == m.w());
	Matrix<D> x = make_matrix<D>(r, 2 * r);
	for (int i = 0; i < r; i++) {
		x[i][i + r] = 1;
		for (int j = 0; j < r; j++) {
			x[i][j] = m[i][j];
		}
	}
	if (gauss(x, EPS).second != r) return Matrix<D>();
	Matrix<D> res = make_matrix<D>(r, r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			res[i][j] = x[i][j + r];
		}
	}
	return res;
}

template <class D> int calc_rank(Matrix<D> a, const D& EPS = -1) { return gauss(a, EPS).second; }
template <class D> D calc_det(Matrix<D> a, const D& EPS = -1) { return gauss(a, EPS).first; }

template <class D> std::vector<std::vector<D>> solve_linear(Matrix<D> a, std::vector<D> b, const D& EPS = -1) {
	int h = a.h(), w = a.w();
	assert(int(b.size()) == h);
	int r = 0;
	std::vector<bool> used(w);
	std::vector<int> idxs;
	for (int x = 0; x < w; x++) {
		int my = get_row(a, h, x, r, EPS);
		if (my == -1) continue;
		if (r != my) std::swap(a[r], a[my]);
		std::swap(b[r], b[my]);
		for (int y = r + 1; y < h; y++) {
			if (!a[y][x]) continue;
			auto freq = a[y][x] / a[r][x];
			for (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];
			b[y] -= freq * b[r];
		}
		r++;
		used[x] = true;
		idxs.push_back(x);
		if (r == h) break;
	}
	auto zero = [&](const D& x) {
		return EPS == D(-1) ? x == 0 : -EPS < x && x < EPS;
	};
	for (int y = r; y < h; y++) {
		if (!zero(b[y])) return {};
	}
	std::vector<std::vector<D>> sols;
	{ // initial solution
		std::vector<D> v(w);
		for (int y = r - 1; y >= 0; y--) {
			int f = idxs[y];
			v[f] = b[y];
			for (int x = f + 1; x < w; x++) {
				v[f] -= a[y][x] * v[x];
			}
			v[f] /= a[y][f];
		}
		sols.push_back(v);
	}
	for (int s = 0; s < w; s++) {
		if (used[s]) continue;
		std::vector<D> v(w);
		v[s] = D(1);
		for (int y = r - 1; y >= 0; y--) {
			int f = idxs[y];
			for (int x = f + 1; x < w; x++) {
				v[f] -= a[y][x] * v[x];
			}
			v[f] /= a[y][f];
		}
		sols.push_back(v);
	}
	return sols;
}

} // MatrixOperations

// 5 is a root of both mods
template <int MOD, int RT> struct Mint {
	static const int mod = MOD;
	static constexpr Mint rt() { return RT; } // primitive root for FFT
	static constexpr int md() { return MOD; } // primitive root for FFT
	int v; 
	explicit operator int() const { return v; } // explicit -> don't silently convert to int
	explicit operator bool() const { return v != 0; }
	Mint() { v = 0; }
	Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
	friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
	friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
	friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
	friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
	friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
	friend std::istream& operator >> (std::istream& in, Mint& a) { 
		long long x; std::cin >> x; a = Mint(x); return in; }
	friend std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v; }
	Mint& operator+=(const Mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	Mint& operator-=(const Mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	Mint& operator*=(const Mint& m) { 
		v = (long long)v * m.v % MOD; return *this; }
	Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }
	friend Mint pow(Mint a, long long p) {
		Mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
		return ans; 
	}
	friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }
	Mint operator-() const { return Mint(-v); }
	Mint& operator++() { return *this += 1; }
	Mint& operator--() { return *this -= 1; }
	friend Mint operator+(Mint a, const Mint& b) { return a += b; }
	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
};

using namespace MatrixOperations;

using mi = Mint<3, 2>;

void solve_case(int tc = 0) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, -2));
	map<array<int, 2>, int> conv;
	vector<int> tmp;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		tmp.push_back(w);
		w = (w == 3 ? 0 : w);
		conv[{u, v}] = conv[{v, u}] = i;
		g[u][v] = g[v][u] = w;
	}
	vector<vector<int>> idx(n, vector<int>(n));
	vector<int> a;
	int vars = 0;
	vector<array<int, 2>> edges;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (g[i][j] == -2) {
				continue;
			}
			idx[i][j] = idx[j][i] = vars;
			a.push_back(g[i][j]);
			edges.push_back({i, j});
			++vars;
		}
	}
	vector<vector<mi>> eqs;
	for (int i = 0; i < m; ++i) {
		auto [u, v] = edges[i];
		if (g[u][v] != -1) {
			vector<mi> eq(m + 1);
			eq.back() = g[u][v];
			eq[i] = 1;
			eqs.push_back(eq);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (g[i][j] == -2 || g[j][k] == -2 || g[k][i] == -2) {
					continue;
				}
				int u = idx[i][j];
				int v = idx[j][k];
				int w = idx[k][i];
				vector<mi> eq(m + 1);
				if (a[u] == -1) {
					eq[u] = 1;
				} else {
					eq.back() -= a[u];
				}
				if (a[v] == -1) {
					eq[v] = 1;
				} else {
					eq.back() -= a[v];
				}
				if (a[w] == -1) {
					eq[w] = 1;
				} else {
					eq.back() -= a[w];
				}
				eqs.push_back(eq);
			}
		}
	}
	int h = (int)eqs.size();
	if (h == 0) {
		for (int i = 0; i < m; ++i) {
			if (tmp[i] == -1) {
				tmp[i] = 3;
			}
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int w = (int)eqs[0].size() - 1;
	Matrix<mi> mat = make_matrix<mi>(h, w);
	vector<mi> b(h);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			mat[i][j] = eqs[i][j];
		}
		b[i] = eqs[i][w];
	}
	auto res = solve_linear(mat, b);
	if (res.empty()) {
		cout << -1 << '\n';
	} else {
		auto sol = res[0];
		vector<int> ans(m);
		for (int i = 0; i < m; ++i) {
			int u = edges[i][0];
			int v = edges[i][1];
			int z = (sol[i] == 0 ? 3 : sol[i].v);
			ans[conv[{u, v}]] = z;
		}
		for (int i = 0; i < m; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	freopen("input.in", "r", stdin);
#endif
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}