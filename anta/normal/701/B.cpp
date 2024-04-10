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
		vector<int> row(n), col(n);
		int R = n, C = n;
		ll ans = (ll)n * n;
		rep(i, m) {
			int r; int c;
			scanf("%d%d", &r, &c), -- r, -- c;
			++ row[r], ++ col[c];
			if(row[r] == 1)
				ans -= C;
			if(col[c] == 1)
				ans -= R;
			if(row[r] == 1 && col[c] == 1)
				++ ans;
			if(row[r] == 1) -- R;
			if(col[c] == 1) -- C;
			if(i != 0) putchar(' ');
			printf("%lld", ans);
		}
		puts("");
	}
	return 0;
}