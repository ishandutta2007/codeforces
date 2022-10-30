#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct Piece {
	char c;
	int x, y;
};
int main() {
	int n;
	while(~scanf("%d", &n)) {
		int x0; int y0;
		scanf("%d%d", &x0, &y0);
		vector<Piece> pieces(n);
		map<ll, vector<ll>> lines[4];
		auto getLine = [x0, y0](int x1, int y1, int k) -> pair<ll,ll> {
			ll x = x1 - x0, y = y1 - y0;
			if(k == 0)
				return make_pair(x, y);
			else if(k == 1)
				return make_pair(y, x);
			else if(k == 2)
				return make_pair(x + y, x - y);
			else if(k == 3)
				return make_pair(x - y, x + y);
			else
				return abort(), make_pair(0, 0);
		};
		pair<ll,ll> origins[4];
		rep(k, 4) {
			auto p = getLine(x0, y0, k);
			origins[k] = p;
			lines[k][p.first].push_back(p.second);
		}
		rep(i, n) {
			char buf[101];
			scanf("%s", buf);
			int x; int y;
			scanf("%d%d", &x, &y);
			rep(k, 4) {
				auto p = getLine(x, y, k);
				lines[k][p.first].push_back(p.second);
			}
			pieces[i] = { *buf, x, y };
		}
		rep(k, 4) for(auto &&p : lines[k]) {
			auto &v = p.second;
			sort(v.begin(), v.end());
		}
		bool ans = false;
		for(auto &&p : pieces) {
			rep(k, 4) {
				if(!(p.c == 'R' || p.c == 'Q') && k < 2) continue;
				if(!(p.c == 'B' || p.c == 'Q') && k >= 2) continue;
				auto t = getLine(p.x, p.y, k);
				if(origins[k].first != t.first) continue;
				const auto &v = lines[k][t.first];
				int i = (int)(lower_bound(v.begin(), v.end(), t.second) - v.begin());
				if(i + 1 < (int)v.size())
					ans |= v[i + 1] == origins[k].second;
				if(i - 1 >= 0)
					ans |= v[i - 1] == origins[k].second;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}