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
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		int m;
		scanf("%d", &m);
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		struct Query {
			int ty, l, r;
		};
		vector<Query> queries(q);
		for (int ii = 0; ii < q; ++ ii) {
			int ty;
			scanf("%d", &ty);
			int l; int r;
			scanf("%d%d", &l, &r), -- l;
			queries[ii] = { ty, l, r };
		}
		vector<int> b(m);
		for (int i = 0; i < m; ++ i)
			scanf("%d", &b[i]), -- b[i];
		vector<int> ans;
		for (int i : b) {
			for (int qi = q - 1; qi >= 0; -- qi) {
				const auto &t = queries[qi];
				if (t.l <= i && i < t.r) {
					if (t.ty == 1) {
						i = i == t.l ? t.r - 1 : i - 1;
					} else {
						i = t.r - 1 - i + t.l;
					}
				}
			}
			ans.push_back(a[i]);
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}