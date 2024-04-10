#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int solve(int i, ll sum, ll minSum, const vector<int> &a, const vector<vpii> &gw) {
	if(sum - minSum > a[i])
		return 0;
	int r = 1;
	for(auto e : gw[i]) {
		ll nsum = sum + e.second;
		r += solve(e.first, nsum, min(minSum, nsum), a, gw);
	}
	return r;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<vpii> gw(n);
		rep(i, n - 1) {
			int p; int c;
			scanf("%d%d", &p, &c), -- p;
			gw[p].emplace_back(i + 1, c);
		}
		int ans = n - solve(0, 0, 0, a, gw);
		printf("%d\n", ans);
	}
	return 0;
}