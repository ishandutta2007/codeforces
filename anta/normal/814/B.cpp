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
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> b(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &b[i]);
		vector<int> indices;
		rep(kk, 2) {
			vector<int> vis(n + 1, -1);
			rep(i, n) {
				int x = a[i];
				if (vis[x] != -1) {
					indices.push_back(vis[x]);
					indices.push_back(i);
				}
				vis[x] = i;
			}
			a.swap(b);
		}
		sort(indices.begin(), indices.end());
		indices.erase(unique(indices.begin(), indices.end()), indices.end());
		vector<int> ans(n, -1);
		for(int i : indices) for(int j : indices) {
			vector<int> p(n, -1);
			vector<bool> used(n + 1);
			rep(k, n) {
				if (k != i && k != j) {
					p[k] = a[k];
					used[p[k]] = true;
				}
			}
			vector<int> unused;
			rer(k, 1, n) if (!used[k])
				unused.push_back(k);
			if ((int)unused.size() > 2) continue;
			sort(unused.begin(), unused.end());
			do {
				int m = 0;
				rep(k, n) if (k == i || k == j)
					p[k] = unused[m ++];
				vector<bool> vis(n + 1);
				vis[0] = true;
				rep(k, n)
					vis[p[k]] = true;
				if (count(vis.begin(), vis.end(), false) != 0)
					continue;
				int ca = 0, cb = 0;
				rep(k, n) {
					ca += a[k] != p[k];
					cb += b[k] != p[k];
				}
				if (ca == 1 && cb == 1) {
					ans = p;
					goto okok;
				}
			} while (next_permutation(unused.begin(), unused.end()));
		}
		if (0) {
		okok:
			for (int i = 0; i < (int)ans.size(); ++ i) {
				if (i != 0) putchar(' ');
				printf("%d", ans[i]);
			}
			puts("");
		} else {
			abort();
		}
	}
	return 0;
}