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
};
typedef ModInt<5> Num;

typedef vector<Num> Vec;
typedef vector<Vec> Mat;

vector<int> solve(Mat A, vector<Vec> bs) {
	int n = A.size(), m = A[0].size();
	int rank = 0;
	vector<char> used(n, 0);
	rep(j, m) {
		int i = 0;
		while (i < n && (used[i] || A[i][j].x == 0))
			i ++;
		if (i == n) continue;
		rank ++;
		used[i] = true;
		rep(k, n) if (!used[k]) {
			Num coef = Num() - A[k][j] / A[i][j];
			rep(l, m)
				A[k][l] += A[i][l] * coef;
			for(auto &b : bs)
				b[k] += b[i] * coef;
		}
	}
	vector<int> res;
	for (auto &b : bs) {
		bool ok = true;
		rep(i, n)
			ok &= used[i] || b[i].x == 0;
		if (!ok)
			res.push_back(-1);
		else
			res.push_back(rank);
	}
	return res;
}

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		Mat A(m, Vec(n));
		rep(i, n) {
			char buf[501];
			scanf("%s", buf);
			rep(j, m)
				A[j][i] = buf[j] - 'a';
		}
		int q;
		scanf("%d", &q);
		vector<Vec> bs(q, Vec(m));
		rep(i, q) {
			char buf[501];
			scanf("%s", buf);
			rep(j, m)
				bs[i][j] = buf[j] - 'a';
		}
		auto ranks = solve(A, bs);
		for (int rank : ranks) {
			using minta = ModInt<1000000007>;
			minta ans;
			if (rank != -1) {
				ans = 1;
				rep(k, n - rank)
					ans *= 5;
			}
			printf("%d\n", ans.get());
		}
	}
	return 0;
}