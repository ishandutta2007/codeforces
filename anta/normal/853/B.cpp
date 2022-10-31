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
	int n; int m; int k;
	while (~scanf("%d%d%d", &n, &m, &k)) {
		vector<vpii> from(n), to(n);
		vector<int> days;
		struct Event {
			int d;
			int i;
			int c;
			bool operator<(const Event &that) const { return d < that.d; }
		};
		vector<Event> events;
		const ll inf = (ll)1e12;
		vector<multiset<ll>> costL(n), costR(n);
		rep(i, n) {
			costL[i].insert(inf);
			costR[i].insert(inf);
		}
		rep(ix, m) {
			int d; int f; int t; int c;
			scanf("%d%d%d%d", &d, &f, &t, &c), -- d, -- f, -- t;
			if (t == -1) {
				int i = f;
				days.push_back(d + 1);
				events.push_back(Event{ d + 1, i * 2 + 0, c });
			} else {
				int i = t;
				costR[i].insert(c);
				events.push_back(Event{ d - k + 1, i * 2 + 1, c });
			}
		}
		sort(days.begin(), days.end());
		days.erase(unique(days.begin(), days.end()), days.end());
		sort(events.begin(), events.end());
		int ei = 0;
		ll ans = INFL;
		ll curCost = 0;
		rep(i, n) {
			curCost += *costL[i].begin();
			curCost += *costR[i].begin();
		}
		for (int d : days) {
			for (; ei != events.size() && events[ei].d <= d; ++ ei) {
				const auto &e = events[ei];
				int i = e.i / 2;
				if (e.i % 2 == 0) {
					ll p = *costL[i].begin();
					costL[i].insert(e.c);
					curCost += *costL[i].begin() - p;
				} else {
					ll p = *costR[i].begin();
					costR[i].erase(costR[i].find(e.c));
					curCost += *costR[i].begin() - p;
				}
			}
			if (curCost < inf)
				amin(ans, curCost);
		}
		printf("%lld\n", ans == INFL ? -1 : ans);
	}
	return 0;
}