#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

struct Disk {
	int x, y, r;
	int i;
};

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<Disk> disks(n + 1);
		rep(i, n) {
			int x; int y; int r;
			scanf("%d%d%d", &x, &y, &r);
			disks[i] = { x,y,r,i };
		}
		disks[n] = { 0, 0, (int)1e7, -1 };
		sort(disks.begin(), disks.end(), [](Disk a, Disk b) {
			return a.r > b.r;
		});
		auto sq = [](int x) { return (ll)x * x; };
		vector<vi> g(n + 1);
		rep(i, n + 1) {
			for (int j = i - 1; j >= 0; -- j) {
				auto a = disks[i], b = disks[j];
				if (sq(a.x - b.x) + sq(a.y - b.y) <= sq(b.r)) {
					g[j].push_back(i);
					break;
				}
			}
		}
		vector<ll> memo((n + 1) * 4, -INFL);
		function<ll(int,int,int,int)> rec = [&](int i, int j, int p, int q) -> ll {
			if (j == g[i].size())
				return 0;
			int c = g[i][j];
			ll &r = memo[c * 4 + p * 2 + q];
			if (r != -INFL) return r;
			amax(r, rec(c, 0, p ^ 1, q) + (p == 0 ? 1 : -1) * sq(disks[c].r) + rec(i, j + 1, p, q));
			amax(r, rec(c, 0, p, q ^ 1) + (q == 0 ? 1 : -1) * sq(disks[c].r) + rec(i, j + 1, p, q));
			return r;
		};
		double ans = (double)rec(0, 0, 0, 0);
		ans *= acos(-1.);
		printf("%.10f\n", ans);
	}
	return 0;
}