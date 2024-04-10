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
	int n; int e;
	while(~scanf("%d%d", &n, &e)) {
		vector<vector<int> > graph(n);
		for(int i = 0; i < e; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		vector<vi> lists(n);
		int T = 0;
		rep(i, n) {
			int l;
			scanf("%d", &l);
			lists[i].resize(l);
			rep(j, l) {
				int t;
				scanf("%d", &t), -- t;
				lists[i][j] = t;
				amax(T, t + 1);
			}
		}
		mt19937 re(random_device{}());
		vector<bool> conference(T);
		vector<array<int, 2>> teams(n);
		while(1) {
			rep(i, T)
				conference[i] = (re() & 1) != 0;
			bool ok = true;
			rep(i, n) {
				teams[i] = { {-1, -1} };
				for(int t : lists[i])
					teams[i][conference[t]] = t;
				if(teams[i][0] == -1 || teams[i][1] == -1) {
					ok = false;
					break;
				}
			}
			if(ok)
				break;
		}
		vector<int> ans(n, -1);
		rep(i, n) {
			int cnt[2] = {};
			for(int j : graph[i]) if(j < i)
				++ cnt[conference[ans[j]]];
			ans[i] = teams[i][cnt[0] > cnt[1] ? 1 : 0];
		}

		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
		for(int i = 0; i < T; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", conference[i] ? 2 : 1);
		}
		puts("");
	}
	return 0;
}