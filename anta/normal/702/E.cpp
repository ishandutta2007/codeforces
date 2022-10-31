#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Sum {
	int min;
	ll sum;
	Sum() : min(INF), sum(0) {}
	explicit Sum(int w) : min(w), sum(w) {}
	Sum &operator+=(const Sum &that)  {
		amin(min, that.min);
		sum += that.sum;
		return *this;
	}
};

int main() {
	int n; long long len;
	while(~scanf("%d%lld", &n, &len)) {
		vector<int> f(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &f[i]);
		vector<int> w(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &w[i]);
		vector<pair<int,Sum>> pow(n), npow(n);
		rep(i, n)
			pow[i] = { f[i], Sum(w[i]) };
		vector<pair<int,Sum>> ans(n);
		rep(i, n)
			ans[i] = { i, Sum() };
		ll rem = len;
		for(ll p = 1; rem > 0; p *= 2) {
			if(rem & p) {
				rep(i, n) {
					auto &x = pow[ans[i].first];
					ans[i].first = x.first;
					ans[i].second += x.second;
				}
				rem -= p;
			}
			npow = pow;
			rep(i, n) {
				auto &x = pow[pow[i].first];
				npow[i].first = x.first;
				npow[i].second += x.second;
			}
			pow.swap(npow);
		}
		rep(i, n) {
			const Sum &sum = ans[i].second;
			printf("%lld %d\n", sum.sum, sum.min);
		}
	}
	return 0;
}