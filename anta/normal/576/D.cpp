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
#include <bitset>
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

typedef bitset<160> BitSet;
struct Matrix {
	int wid;
	vector<BitSet> v, w;
	Matrix(): wid(0) {}
	Matrix(int n, int m): v(n, BitSet()), wid(m) { }
	inline int height() const { return (int)v.size(); }
	inline int width() const { return wid; }
	inline bool at(int i, int j) const { return v[i][j]; }
	static Matrix identity(int n) {
		Matrix A(n, n);
		rep(i, n) A.v[i][i] = 1;
		return A;
	}
	inline static Matrix identity(const Matrix& A) { return identity(A.height()); }
	vector<BitSet> trans() const {
		int n = height(), m = width();
		vector<BitSet> res(m, BitSet());
		rep(i, n) rep(j, m)
			res[j][i] = v[i][j];
		return res;
	}
	Matrix& operator*=(const Matrix& B) {
		int n = height(), m = B.width(), p = B.height();
		vector<BitSet> transB = B.trans();
		assert(p == width());
		w.assign(n, BitSet());
		rep(i, n) rep(j, m)
			w[i][j] = (v[i] & transB[j]).any();
		v.swap(w);
		return *this;
	}
};
Matrix operator^(const Matrix& t, ll k) {
	Matrix A = t, B = Matrix::identity(t);
	while(k) {
		if(k & 1) B *= A;
		A *= A;
		k >>= 1;
	}
	return B;
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		vector<pair<int,pii> > edges(m);
		rep(i, m) {
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d), -- a, -- b;
			edges[i] = mp(d, mp(a, b));
		}
		sort(all(edges));
		Matrix curA(n, n);
		curA.v[n-1][n-1] = true;
		Matrix v(1, n);
		v.v[0][0] = true;
		int prevd = 0;
		int ans = -1;
		for(int ix = 0; ; ++ ix) {
			int d = ix < m ? edges[ix].first : (int)1e9+200;
			int k = d - prevd;
			Matrix pv = v;
			v *= curA ^ k;
			if(v.v[0][n-1]) {
				v = pv;
				rep(l, n+1) {
					if(v.v[0][n-1]) {
						ans = prevd + l;
						break;
					}
					v *= curA;
				}
				if(ans == -1) cerr << "err" << endl, abort();
				break;
			}
			if(ix == m) break;
			pii p = edges[ix].second;
			curA.v[p.first][p.second] = true;
			prevd = d;
		}
		if(ans == -1)
			puts("Impossible");
		else
			printf("%d\n", ans);
	}
	return 0;
}