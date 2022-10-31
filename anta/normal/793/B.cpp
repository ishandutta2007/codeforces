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
	int n; int m;
	while (~scanf("%d%d", &n, &m)) {
		vector<string> S(n);
		rep(i, n) {
			char buf[1001];
			scanf("%s", buf);
			S[i] = buf;
		}
		vi q, nq;
		rep(i, n) rep(j, m) if (S[i][j] == 'S') {
			rep(d, 4)
				nq.push_back((i * m + j) * 4 + d);
		}
		static const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
		bool ans = false;
		rep(k, 3) {
			q.swap(nq);
			vector<bool> vis(n * m * 4);
			while (!q.empty()) {
				int s = q.back();
				q.pop_back();
				if (vis[s]) continue;
				vis[s] = true;
				int i = s / 4 / m, j = s / 4 % m, d = s % 4;
				if (k == 2)
					ans |= S[i][j] == 'T';
				int yy = i + dy[d], xx = j + dx[d];
				if (!(yy < 0 || yy >= n || xx < 0 || xx >= m || S[yy][xx] == '*'))
					q.push_back((yy * m + xx) * 4 + d);
				rep(e, 4)
					nq.push_back((i * m + j) * 4 + e);
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}