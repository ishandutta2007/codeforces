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
		vector<int> f(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &f[i]), -- f[i];
		vector<vi> v(n);
		rep(i, n)
			v[f[i]].push_back(i);
		vector<int> g(n, -1);
		vector<int> h;
		bool ok = true;
		rep(i, n) if (!v[i].empty()) {
			ok &= f[i] == i;
			g[i] = (int)h.size();
			h.push_back(i);
		}
		rep(i, n) if (v[i].empty())
			g[i] = g[f[i]];

		if (!ok) {
			puts("-1");
		} else {
			int m = (int)h.size();
			rep(i, m)
				assert(g[h[i]] == i);
			rep(i, n)
				assert(h[g[i]] == f[i]);

			printf("%d\n", m);
			for (int i = 0; i < n; ++ i) {
				if (i != 0) putchar(' ');
				printf("%d", g[i] + 1);
			}
			puts("");
			for (int i = 0; i < m; ++ i) {
				if (i != 0) putchar(' ');
				printf("%d", h[i] + 1);
			}
			puts("");
		}
	}
	return 0;
}