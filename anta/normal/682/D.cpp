#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct DP {
	int m, k;
	vector<int> dp;
	void init(int m_, int k_) {
		m = m_, k = k_;
		dp.assign((m + 1) * (k + 1) * 2, -1);
	}
	int &operator()(int j, int kk, int b) {
		return dp[(j * (k + 1) + kk) * 2 + b];
	}
	void swap(DP &that) {
		dp.swap(that.dp);
		std::swap(m, that.m);
		std::swap(k, that.k);
	}
};

int main() {
	int n; int m; int k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		string s, t;
		cin >> s >> t;
		DP dp, ndp;
		ndp.init(m, k);
		ndp(0, 0, 0) = 0;
		rer(i, 0, n) {
			dp.swap(ndp);
			ndp.init(m, k);
			rer(j, 0, m) rer(kk, 0, k) rep(b, 2) {
				int x = dp(j, kk, b);
				if(x == -1) continue;
				if(i < n) amax(ndp(j, kk, 0), x);
				if(j < m) amax(dp(j + 1, kk, 0), x);
				if(b == 1) {
					if(i < n && j < m && s[i] == t[j])
						amax(ndp(j + 1, kk, 1), x + 1);
				}
				if(i < n && j < m && s[i] == t[j] && kk < k)
					amax(ndp(j + 1, kk + 1, 1), x + 1);
			}
		}
		int ans = max(dp(m, k, 0), dp(m, k, 1));
		printf("%d\n", ans);
	}
	return 0;
}