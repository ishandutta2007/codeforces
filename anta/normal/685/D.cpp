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
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<int> x(n), y(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d%d", &x[i], &y[i]);
		vpii events;
		vi xs;
		xs.reserve(n * k);
		rep(i, n) {
			events.emplace_back(y[i] - k + 1, i * 2 + 0);
			events.emplace_back(y[i] + 1, i * 2 + 1);
			rep(j, k)
				xs.push_back(x[i] - k + 1 + j);
		}
		sort(events.begin(), events.end());
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		vector<int> cnt(xs.size(), 0), num(n + 1, 0), prevy(n + 1, 0);
		vector<long long> ans(n + 1, 0);
		for(auto ev : events) {
			int cury = ev.first;
			{
				int i = ev.second / 2;
				int j = lower_bound(xs.begin(), xs.end(), x[i] - k + 1) - xs.begin();
				int add = ev.second % 2 == 0 ? 1 : -1;
				rep(l, k) {
					int c = cnt[j + l];
					{
						int mul = cury - prevy[c];
						ans[c] += mul * num[c];
						prevy[c] = cury;
					}
					-- num[c];
					c += add;
					{
						int mul = cury - prevy[c];
						ans[c] += mul * num[c];
						prevy[c] = cury;
					}
					++ num[c];
					cnt[j + l] = c;
				}
			}
		}
		rer(s, 1, n) {
			if(s != 1) putchar(' ');
			printf("%lld", ans[s]);
		}
		puts("");
	}
	return 0;
}