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
	int n; long long r;
	while(~scanf("%d%lld", &n, &r)) {
		vector<int> l(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &l[i]);
		vector<int> t(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &t[i]);
		ll rem = 0;
		bool ok = true;
		vector<ll> ans;
		ll k = 0;
		ll total = 0;
		rep(i, n) {
			int len = l[i], time = t[i];
			if(time < len) {
				ok = false;
				break;
			}
			int x = (int)min(rem, (ll)len);
			rem -= x;
			len -= x;
			time -= x;
			total += x;
			if(len == 0)
				continue;
			assert(rem == 0);
			int t = min(len, time - len);
			total += t * 2;
			if(t == len)
				continue;
			ll cnt = (len - t - 1) / r + 1;
			for(ll j = 0; j < cnt && ans.size() < (size_t)1e5; ++ j)
				ans.push_back(total + j * r);
			k += cnt;
			rem = cnt * r - (len - t);
			total += len - t;
		}
		if(!ok) {
			puts("-1");
			continue;
		}
		printf("%lld\n", k);
		if(k <= (ll)1e5) {
			for(int i = 0; i < (int)ans.size(); ++ i) {
				if(i != 0) putchar(' ');
				printf("%lld", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}