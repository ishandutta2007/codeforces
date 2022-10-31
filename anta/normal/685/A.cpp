#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int getlen(int x) {
	int r = 0;
	do {
		++ r;
		x /= 7;
	} while(x > 0);
	return r;
}

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		int a = getlen(n - 1), b = getlen(m - 1);
		if(a + b > 7) {
			puts("0");
			continue;
		}
		vi perm(7);
		rep(i, 7) perm[i] = i;
		set<pair<int, int>> s;
		do {
			int x = 0, y = 0;
			rep(i, a)
				x = x * 7 + perm[i];
			rep(i, b)
				y = y * 7 + perm[a + i];
			if(x < n && y < m)
				s.insert(make_pair(x, y));
		} while(next_permutation(perm.begin(), perm.end()));
		int ans = (int)s.size();
		printf("%d\n", ans);
	}
	return 0;
}