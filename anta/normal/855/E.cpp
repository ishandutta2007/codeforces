#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

ll memo[11][64][1 << 10][2];
ll rec(int D, int i, int S, bool lz) {
	ll &r = memo[D][i + 1][S][lz];
	if (r != -1) return r;
	if (i == -1) return r = S == 0 ? 1 : 0;
	r = 0;
	rep(d, D) {
		bool nlz = lz && d == 0;
		r += rec(D, i - 1, nlz ? S : S ^ (1 << d), nlz);
	}
	return r;
}

int main() {
	memset(memo, -1, sizeof(memo));
	int T;
	scanf("%d", &T);
	for (int ii = 0; ii < T; ++ ii) {
		int b; long long L; long long R;
		scanf("%d%lld%lld", &b, &L, &R);
		auto solve = [b](ll N) {
			vector<int> digits;
			while (N > 0) {
				digits.push_back((int)(N % b));
				N /= b;
			}
			ll r = 0;
			int S = 0;
			for (int i = (int)digits.size() - 1; i >= 0; -- i) {
				rep(d, digits[i]) {
					bool nlz = i == digits.size() - 1 && d == 0;
					r += rec(b, i - 1, nlz ? S : S ^ (1 << d), nlz);
				}
				S ^= 1 << digits[i];
			}
			return r;
		};
		ll ans = solve(R + 1) - solve(L);
		printf("%lld\n", ans);
	}
	return 0;
}