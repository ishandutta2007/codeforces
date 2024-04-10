#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

void oddMagicSquare(int N, vector<vi> &a) {
	int i = 0, j = N / 2;
	a.assign(N, vi(N));
	int sqr = N * N;
	rer(k, 1, sqr) {
		a[i][j] = k;
		-- i, ++ j;
		if(k % N == 0) {
			i += 2;
			-- j;
		} else {
			if(j == N) {
				j -= N;
			} else if(i < 0) {
				i += N;
			}
		}
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<vi> ans;
		oddMagicSquare(n, ans);
		rep(i, n) {
			rep(j, n) {
				if(j != 0) putchar(' ');
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}