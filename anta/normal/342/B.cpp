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
	int n; int m; int s; int f;
	while(~scanf("%d%d%d%d", &n, &m, &s, &f)) {
		-- s, -- f;
		int maxT = n + m + 1;
		vector<pii> intervals(maxT + 1, make_pair(-1, -2));
		rep(i, m) {
			int t; int l; int r;
			scanf("%d%d%d", &t, &l, &r), -- t, -- l;
			if(t <= maxT)
				intervals[t] = { l, r };
		}
		string ans;
		while(s != f) {
			int t = s < f ? s + 1 : s - 1;
			int l, r;
			tie(l, r) = intervals[ans.size()];
			if((l <= s && s < r) || (l <= t && t < r)) {
				ans += 'X';
			} else {
				ans += s < f ? 'R' : 'L';
				s = t;
			}
		}
		puts(ans.c_str());
	}
	return 0;
}