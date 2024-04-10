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
	int n; long long k;
	while (~scanf("%d%lld", &n, &k)) {
		if (k > (ll)n * (n - 1) / 2) {
			puts("Impossible");
			continue;
		}
		string ans;
		rep(i, n) {
			ans += '(';
			if (k >= n - i - 1) {
				k -= n - i - 1;
			} else {
				ans += ')';
			}
		}
		while ((int)ans.size() < n * 2)
			ans += ')';
		puts(ans.c_str());
	}
	return 0;
}