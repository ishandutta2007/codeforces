#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int solve(int n, ll k) {
	assert(0 <= k && k < (1LL << (n + 1)) - 1);
	if (k == (1LL << n) - 1)
		return n + 1;
	else if (k < (1LL << n) - 1)
		return solve(n - 1, k);
	else
		return solve(n - 1, k - (1LL << n));
}

int main() {
	int n; long long k;
	while (~scanf("%d%lld", &n, &k)) {
		--k;
		int ans = solve(n, k);
		printf("%d\n", ans);
	}
	return 0;
}