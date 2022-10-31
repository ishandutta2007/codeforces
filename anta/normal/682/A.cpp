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
		int a[5] = {}, b[5] = {};
		rer(x, 1, n)
			++ a[x % 5];
		rer(y, 1, m)
			++ b[y % 5];
		ll ans = 0;
		rep(i, 5) rep(j, 5) if((i + j) % 5 == 0)
			ans += (ll)a[i] * b[j];
		printf("%lld\n", ans);
	}
	return 0;
}