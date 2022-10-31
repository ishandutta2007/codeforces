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
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<ll> values;
		values.push_back(1);
		if (abs(k) == 1) {
			if(k == -1)
				values.push_back(k);
		} else {
			for (ll p = k; abs(p) <= (ll)1e14; p *= k)
				values.push_back(p);
		}
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		map<ll, int> cnt;
		ll ans = 0;
		ll sum = 0;
		rep(i, n) {
			++ cnt[sum];
			sum += a[i];
			for (ll x : values)
				ans += cnt[sum - x];
		}
		printf("%lld\n", ans);
	}
	return 0;
}