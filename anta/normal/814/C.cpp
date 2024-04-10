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
	int n;
	while (~scanf("%d", &n)) {
		char S[1501];
		scanf("%s", S);
		array<vector<int>, 26> lists;
		rep(a, 26) {
			vector<int> cnt(n + 1);
			rep(i, n)
				cnt[i + 1] = cnt[i] + (S[i] == 'a' + a);
			vector<int> minNum(n + 1, INF);
			minNum[0] = 0;
			rep(i, n) {
				rer(j, i + 1, n)
					amin(minNum[j - i], (j - i) - (cnt[j] - cnt[i]));
			}
			lists[a].clear();
			rer(i, 0, n)
				lists[a].push_back(minNum[i]);
			assert(is_sorted(lists[a].begin(), lists[a].end()));
		}
		int Q;
		scanf("%d", &Q);
		rep(ii, Q) {
			int m;
			scanf("%d", &m);
			char buf[2];
			scanf("%s", buf);
			const auto &v = lists[*buf - 'a'];
			int ans = (int)(upper_bound(v.begin(), v.end(), m) - v.begin()) - 1;
			printf("%d\n", ans);
		}
	}
	return 0;
}