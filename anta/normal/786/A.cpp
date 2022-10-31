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
		int k1;
		scanf("%d", &k1);
		vector<int> a1(k1);
		for (int i = 0; i < k1; ++ i)
			scanf("%d", &a1[i]);
		int k2;
		scanf("%d", &k2);
		vector<int> a2(k2);
		for (int i = 0; i < k2; ++ i)
			scanf("%d", &a2[i]);
		vector<int> ans(n * 2, 0);
		{
			vector<bool> canwin(n * 2);
			vector<int> stk;
			vector<bool> vis(n * 2);
			vis[0 * 2 + 0] = true;
			vis[0 * 2 + 1] = true;
			stk.push_back(0 * 2 + 0);
			stk.push_back(0 * 2 + 1);
			vector<int> remDeg(n * 2, 0);
			rep(i, n) {
				remDeg[i * 2 + 0] = k1;
				remDeg[i * 2 + 1] = k2;
			}
			while (!stk.empty()) {
				int u = stk.back(); stk.pop_back();
				if (!canwin[u]) {
					for(int d : u % 2 == 0 ? a2 : a1) {
						int v = (u / 2 + (n - d)) % n * 2 + (1 - u % 2);
						if (vis[v]) continue;
						vis[v] = true;
						canwin[v] = true;
						stk.push_back(v);
					}
				} else {
					for (int d : u % 2 == 0 ? a2 : a1) {
						int v = (u / 2 + (n - d)) % n * 2 + (1 - u % 2);
						if (-- remDeg[v] == 0) {
							if (vis[v]) continue;
							vis[v] = true;
							canwin[v] = false;
							stk.push_back(v);
						}
					}
				}
			}
			rep(i, n) rep(p, 2) {
				int u = i * 2 + p;
				ans[u] = !vis[u] ? 0 : canwin[u] ? 2 : 1;
			}
		}
		const char *strs[4] = { "Loop", "Lose", "Win", "???" };
		rep(j, 2) {
			reu(i, 1, n) {
				if (i != 1)
					putchar(' ');
				printf("%s", strs[ans[i * 2 + j]]);
			}
			puts("");
		}
	}
	return 0;
}