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
	int B; int n;
	while (~scanf("%d%d", &B, &n)) {
		const int X = 2000;
		vector<bool> v(X + 1);
		rep(i, n) {
			int a;
			scanf("%d", &a);
			v[a] = true;
		}
		vector<int> dist(X * 2 + 1, INF);
		vi q, nq;
		rer(i, 0, X) if (v[i]) {
			int d = i - B;
			dist[X + d] = 1;
			nq.push_back(d);
		}
		nq.push_back(0);
		while (!nq.empty()) {
			q.swap(nq);
			while (!q.empty()) {
				int j = q.back();
				q.pop_back();
				rer(i, 0, X) if (v[i]) {
					int d = i - B;
					int nj = j + d;
					if (-X <= nj && nj <= X && dist[X + nj] == INF) {
						dist[X + nj] = dist[X + j] + 1;
						nq.push_back(nj);
					}
				}
			}
		}
		int ans = dist[X];
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}