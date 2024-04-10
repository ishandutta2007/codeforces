#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		long long k;
		scanf("%lld", &k);
		int row; int col;
		scanf("%d%d", &row, &col), -- row, -- col;
		vi seq;
		if (n == 1) {
			seq.push_back(0);
		} else {
			rep(i, n - 1) seq.push_back(i);
			rep(i, n - 1) seq.push_back(n - 1 - i);
		}
		auto solve = [n, m, k, &seq](int y, int x) -> ll {
			ll res = 0;
			ll rows = k / m;
			int lastcols = k % m;
			ll quot = rows / seq.size();
			res += quot * count(seq.begin(), seq.end(), y);
			int rem = rows % seq.size();
			rep(i, rem) if(seq[i] == y)
				res += 1;
			if (x < lastcols && seq[rem] == y)
				res += 1;
			return res;
		};
		ll ma = 0, mi = INFL;
		rep(i, n) rep(j, m) {
			ll t = solve(i, j);
			amax(ma, t);
			amin(mi, t);
		}
		printf("%lld %lld %lld\n",
			ma,
			mi,
			solve(row, col));
	}
	return 0;
}