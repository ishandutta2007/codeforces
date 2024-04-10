#include "bits/stdc++.h"
using namespace std;

template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y); }

struct Matrix {
	using Num = double;
	vector<vector<Num> > v;
	Matrix() {}
	Matrix(int n, int m) : v(n, vector<Num>(m)) { }
	inline int height() const { return (int)v.size(); }
	inline int width() const { return (int)v[0].size(); }
	inline Num& at(int i, int j) { return v[i][j]; }
	inline const Num& at(int i, int j) const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		for (int i = 0; i < n; ++ i) A.at(i, i) = 1;
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	Matrix operator*(const Matrix& B) const {
		int n = height(), m = B.width(), p = B.height();
		assert(p == width());
		Matrix res(n, m);
		for (int i = 0; i < n; ++ i) for (int j = 0; j < m; ++ j) {
			Num x = 0;
			for (int k = 0; k < p; ++ k) x += at(i, k) * B.at(k, j);
			res.at(i, j) = x;
		}
		return res;
	}
	Matrix &normalize() {
		int n = height();
		for (auto &row : v) {
			auto sum = accumulate(row.begin(), row.end(), 0.);
			auto inv = 1 / sum;
			for (auto &x : row) x *= inv;
		}
		return *this;
	}
};

template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Point {
	int x, y;
};

//by-ay, -(bx-ax), -ax*by+ay*bx
struct Line {
	int a, b;
	long long c;
	static Line make(Point p, Point q) {
		int a = q.y - p.y;
		int b = p.x - q.x;
		auto c = (long long)p.y * q.x - (long long)p.x * q.y;
		auto g = (int)gcd(abs(c), (long long)gcd(abs(a), abs(b)));
		if (c < 0 || (c == 0 && (b < 0 || (b == 0 && a < 0))))
			g = -g;
		a /= g, b /= g, c /= g;
		return Line{ a, b, c };
	}
	bool operator<(const Line &that) const {
		return tie(a, b, c) < tie(that.a, that.b, that.c);
	}
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<Point> points(n);
		for (int i = 0; i < n; ++ i) {
			int x; int y;
			scanf("%d%d", &x, &y);
			points[i] = { x, y };
		}
		map<Line, vector<int>> incidence;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < i; ++ j) {
				auto line = Line::make(points[i], points[j]);
				auto &v = incidence[line];
				v.push_back(i);
				v.push_back(j);
			}
		}
		vector<vector<Line>> invIncidence(n);
		for (auto &p : incidence) {
			auto &v = p.second;
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			for (int i : v)
				invIncidence[i].push_back(p.first);
		}
		Matrix A(n, n);
		for (int i = 0; i < n; ++ i) {
			auto p1 = 1. / (int)invIncidence[i].size();
			for (auto r : invIncidence[i]) {
				const auto &v = incidence[r];
				auto p2 = 1. / (int)v.size();
				for (int j : v)
					A.at(i, j) += p1 * p2;
			}
		}
		const int K = 13;
		vector<Matrix> powers(K + 1);
		powers[0] = A;
		for (int k = 0; k < K; ++ k) {
			powers[k + 1] = powers[k] * powers[k];
			powers[k + 1].normalize();
		}
		int q;
		scanf("%d", &q);
		for (int qi = 0; qi < q; ++ qi) {
			int t; int m;
			scanf("%d%d", &t, &m), -- t;
			vector<double> cur(n, 0), nxt;
			auto mul = [&](const Matrix &A) {
				nxt.assign(n, 0);
				for (int i = 0; i < n; ++ i) {
					double x = 0;
					for (int j = 0; j < n; ++ j)
						x += cur[j] * A.at(i, j);
					nxt[i] = x;
				}
				cur.swap(nxt);
			};
			cur[t] = 1;
			for (int k = 0; k <= K; ++ k) if ((m - 1) >> k & 1)
				mul(powers[k]);
			double ans = 0;
			for (const auto &p : incidence) {
				const auto &v = p.second;
				double sum = 0;
				for (int i : v)
					sum += cur[i];
				amax(ans, sum / v.size());
			}
			mul(A);
			for (int i = 0; i < n; ++ i)
				amax(ans, cur[i]);
			printf("%.10f\n", ans);
		}
	}
}