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
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> last(n, -1);
		vector<vi> ans(n);
		rep(i, n) {
			int k = (int)(upper_bound(last.begin(), last.end(), a[i], greater<int>()) - last.begin());
			ans[k].push_back(a[i]);
			last[k] = a[i];
		}
		rep(k, n) if (last[k] != -1) {
			for (int i = 0; i < (int)ans[k].size(); ++ i) {
				if (i != 0) putchar(' ');
				printf("%d", ans[k][i]);
			}
			puts("");
		}
	}
	return 0;
}