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
	int n; int c;
	while(~scanf("%d%d", &n, &c)) {
		vector<vi> words(n);
		rep(i, n) {
			int l;
			scanf("%d", &l);
			words[i].resize(l);
			rep(j, l) {
				int c;
				scanf("%d", &c), -- c;
				words[i][j] = c;
			}
		}
		vector<int> cnt(c + 1, 0);
		rep(i, n - 1) {
			const vi &v = words[i], &w = words[i + 1];
			for(int j = 0; ; ++ j) {
				if(j == v.size()) {
					++ cnt[0], -- cnt[c];
					break;
				} else if(j == w.size()) {
					break;
				}
				int x = v[j], y = w[j];
				if(x != y) {
					if(x < y) {
						++ cnt[0], -- cnt[c - y];
						++ cnt[c - x], -- cnt[c];
					} else {
						++ cnt[c - x], -- cnt[c - y];
					}
					break;
				}
			}
		}
		rep(i, c) cnt[i + 1] += cnt[i];
		int ans = -1;
		rep(i, c) if(cnt[i] == n - 1) {
			ans = i;
			break;
		}
		printf("%d\n", ans);
	}
	return 0;
}