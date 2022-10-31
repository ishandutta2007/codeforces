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
	int n; int m; int q;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		vector<vector<int> > v(n, vector<int>(m));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j)
			scanf("%d", &v[i][j]);
		int H = n + 2, W = m + 2;
		vector<int> down(H * W), right(H * W);
		rep(i, H) rep(j, W) {
			down[i * W + j] = i == n + 1 ? -1 : (i + 1) * W + j;
			right[i * W + j] = j == m + 1 ? -1 : i * W + (j + 1);
		}

		auto getBorder = [&](int r, int c, int h, int w, int border[4][1000]) {
			{
				int i = 0 * W + c;
				rep(k, r)
					i = down[i];
				rep(k, w) {
					i = right[i];
					border[0][k] = i;
				}
				rep(k, h) {
					i = down[i];
					border[3][k] = i;
				}
			}
			{
				int i = r * W + 0;
				rep(k, c)
					i = right[i];
				rep(k, h) {
					i = down[i];
					border[2][k] = i;
				}
				rep(k, w) {
					i = right[i];
					border[1][k] = i;
				}
			}
		};

		int border1[4][1000], border2[4][1000];
		rep(ii, q) {
			int a; int b; int c; int d;
			scanf("%d%d%d%d", &a, &b, &c, &d), -- a, -- b, -- c, -- d;
			int h; int w;
			scanf("%d%d", &h, &w);
			getBorder(a, b, h, w, border1);
			getBorder(c, d, h, w, border2);

			rep(k, w)
				swap(down[border1[0][k]], down[border2[0][k]]);
			rep(k, w)
				swap(down[border1[1][k]], down[border2[1][k]]);
			rep(k, h)
				swap(right[border1[2][k]], right[border2[2][k]]);
			rep(k, h)
				swap(right[border1[3][k]], right[border2[3][k]]);
		}

		vector<vi> ans(n, vi(m, -1));
		rep(k, n) {
			int i = (k + 1) * W + 0;
			rep(l, m) {
				i = right[i];
				ans[k][l] = v[i / W - 1][i % W - 1];
			}
		}

		rep(i, n) {
			for(int j = 0; j < m; ++ j) {
				if(j != 0) putchar(' ');
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}