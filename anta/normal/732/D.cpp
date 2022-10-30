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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> d(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &d[i]), -- d[i];
		vector<int> a(m);
		for(int i = 0; i < m; ++ i)
			scanf("%d", &a[i]);
		int lo = 0, up = n + 1;
		while(up - lo > 0) {
			int mid = (lo + up) / 2;
			vector<pair<int, int>> lastDay(m);
			rep(i, m)
				lastDay[i] = { -1, i };
			rep(i, mid) {
				int x = d[i];
				if(x != -1)
					lastDay[x].first = i;
			}
			sort(lastDay.begin(), lastDay.end());
			bool ok = true;
			int margin = 0, last = -1;
			for(auto p : lastDay) {
				margin += p.first - (last + 1);
				int t = a[p.second];
				ok &= t <= margin;
				margin -= t;
				last = p.first;
			}
			if(ok)
				up = mid;
			else
				lo = mid + 1;
		}
		printf("%d\n", up == n + 1 ? -1 : up);
	}
	return 0;
}