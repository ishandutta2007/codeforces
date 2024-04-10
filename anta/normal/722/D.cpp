#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool solve(int mid, const vi &y, vi &xs) {
	int n = (int)y.size();
	bool ok = true;
	set<int> s;
	rep(i, n) {
		int x = y[i];
		bool ook = false;
		while(x > 0) {
			if(x <= mid && !s.count(x)) {
				ook = true;
				s.insert(x);
				break;
			}
			x >>= 1;
		}
		if(!(ok &= ook)) break;
	}
	if(ok)
		xs.assign(s.begin(), s.end());
	return ok;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> y(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &y[i]);
		int lo = 0, up = *max_element(y.begin(), y.end());
		vi xs;
		while(up - lo > 0) {
			int mid = (lo + up) / 2;
			bool ok = solve(mid, y, xs);
			if(ok)
				up = mid;
			else
				lo = mid + 1;
		}
		solve(up, y, xs);
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", xs[i]);
		}
		puts("");
	}
	return 0;
}