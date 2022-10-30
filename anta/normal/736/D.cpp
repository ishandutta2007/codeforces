#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		using BitSet = bitset<4096>;
		vector<BitSet> A(n);
		vpii pairs(m);
		rep(i, m) {
			int a; int b;
			scanf("%d%d", &a, &b), -- a, -- b;
			pairs[i] = { a, b };
			A[a].set(b);
		}
		rep(i, n)
			A[i][n + i] = true;
		rep(i, n) {
			int j = i;
			for(; j < n && !A[j][i]; ++ j);
			assert(j < n);
			swap(A[i], A[j]);
			rep(k, n) if(k != i && A[k][i])
				A[k] ^= A[i];
		}
		for(auto p : pairs) {
			bool ans = !A[p.second][n + p.first];
			puts(ans ? "YES" : "NO");
		}
	}
	return 0;
}