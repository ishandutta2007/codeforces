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
	int n;
	while(~scanf("%d", &n)) {
		//1,2,4
		//1,3,6
		//1,2,6
		int cnt[8] = {};
		rep(i, n) {
			int x;
			scanf("%d", &x);
			++ cnt[x];
		}
		vector<vi> ans;
		rep(i, n / 3) {
			if(cnt[3] != 0) {
				ans.push_back({ 1, 3, 6 });
			} else if(cnt[4] != 0) {
				ans.push_back({ 1, 2, 4 });
			} else {
				ans.push_back({ 1, 2, 6 });
			}
			rep(k, 3) {
				if(-- cnt[ans.back()[k]] < 0) {
					ans.clear();
					break;
				}
			}
			if(ans.empty()) break;
		}
		if(ans.empty()) {
			puts("-1");
		} else {
			rep(i, n / 3)
				printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
		}
	}
	return 0;
}