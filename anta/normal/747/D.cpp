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
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> t(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &t[i]);
		vector<int> negatives;
		rep(i, n) {
			if (t[i] < 0)
				negatives.push_back(i);
		}
		if (negatives.empty()) {
			puts("0");
		}
		else if ((int)negatives.size() > k) {
			puts("-1");
		}
		else {
			vector<int> xs;
			rep(i, negatives.size() - 1) {
				int x = negatives[i + 1] - negatives[i] - 1;
				xs.push_back(x);
			}
			sort(xs.begin(), xs.end());
			int ans = INF;
			rep(last, 2) {
				int rem = k - (int)negatives.size();
				if (last)
					rem -= n - negatives.back() - 1;
				if (rem < 0) continue;
				int total = (int)negatives.size() * 2;
				if (last)
					-- total;
				for (int x : xs) {
					if (x > rem)
						break;
					rem -= x;
					total -= 2;
				}
				amin(ans, total);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}