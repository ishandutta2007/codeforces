#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool check(int w, const vector<int> &a, int m) {
	int n = (int)a.size();
	vector<int> dp(n);
	rep(start, 2) if(start < n) {
		dp[start] = start == 0 ? a[0] : max(a[0] + w, a[1]);
		reu(i, start + 1, n) {
			int x = dp[i - 1];
			if(dp[i - 1] >= a[i] - 1)
				amax(x, a[i] + w);
			else if(dp[i - 1] >= a[i] - w - 1)
				amax(x, a[i]);
			if(i >= 2 && dp[i - 2] >= a[i] - w - 1)
				amax(x, a[i - 1] + w);
			dp[i] = x;
		}
		if(dp[n - 1] >= min(m - 1, m + a[start] - w - 1))
			return true;
	}
	return false;
}

int main() {
	int m;
	while(~scanf("%d", &m)) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		pair<int, int> maxd(a[0] + m - a[n - 1], 0);
		rep(i, n - 1)
			amax(maxd, make_pair(a[i + 1] - a[i], i + 1));
		rotate(a.begin(), a.begin() + maxd.second, a.end());
		for(int i = n - 1; i >= 0; -- i) {
			if((a[i] -= a[0]) < 0)
				a[i] += m;
		}
		int lo = 0, up = a[0] + m - a[n - 1] - 1;
		while(up - lo > 0) {
			int mid = (lo + up) / 2;
			if(check(mid, a, m))
				up = mid;
			else
				lo = mid + 1;
		}
		printf("%d\n", up);
	}
	return 0;
}