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
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		map<string, int> a;
		rep(i, n) {
			char buf[501];
			scanf("%s", buf);
			a[buf] |= 1;
		}
		rep(i, m) {
			char buf[501];
			scanf("%s", buf);
			a[buf] |= 2;
		}
		int cnt[4] = {};
		for (auto &&p : a)
			++ cnt[p.second];
		bool ans = cnt[1] + cnt[3] % 2 > cnt[2];
		puts(ans ? "YES" : "NO");
	}
	return 0;
}