#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

ll getLen(ll n) {
	return n <= 1 ? 1 : 1 + getLen(n / 2) * 2;
}

ll solve(ll n, ll L, ll R) {
	ll len = getLen(n);
	amax(L, 0);
	amin(R, len);
	if (L >= R)
		return 0;
	if (n <= 1)
		return n;
	ll res = 0;
	ll x = getLen(n / 2);
	res += solve(n / 2, L, R);
	res += solve(n % 2, L - x, R - x);
	res += solve(n / 2, L - x - 1, R - x - 1);
	return res;
}

int main() {
	long long n; long long L; long long R;
	while (~scanf("%lld%lld%lld", &n, &L, &R)) {
		ll ans = solve(n, L - 1, R);
		printf("%lld\n", ans);
	}
	return 0;
}