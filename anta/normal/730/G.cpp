#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

typedef pair<int, int> Seg1D;
inline bool commonSeg1D(const Seg1D &x, const Seg1D &y) {
	return y.first < x.second && x.first < y.second;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vpii ans(n);
		set<int> candidates;
		candidates.insert(0);
		rep(i, n) {
			int s; int d;
			scanf("%d%d", &s, &d), -- s;

			auto check = [i, &ans](int t, int d) {
				auto p = make_pair(t, t + d);
				rep(j, i) {
					if(commonSeg1D(ans[j], p))
						return false;
				}
				return true;
			};

			int t;
			if(check(s, d)) {
				t = s;
			} else {
				t = -1;
				for(int x : candidates) {
					if(check(x, d)) {
						t = x;
						break;
					}
				}
			}
			ans[i] = { t, t + d };
			candidates.insert(t + d);
		}
		for(int i = 0; i < (int)ans.size(); ++ i)
			printf("%d %d\n", ans[i].first + 1, ans[i].second);
	}
	return 0;
}