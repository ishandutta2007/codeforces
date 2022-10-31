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
	char S[5001];
	while (~scanf("%s", S)) {
		int n = (int)strlen(S);
		vector<vector<bool>> palin(n + 1, vector<bool>(n + 1));
		rep(i, n) palin[i][i + 1] = true;
		rer(len, 2, n) rer(i, 0, n - len) {
			int j = i + len;
			palin[i][j] = S[i] == S[j - 1] && (len == 2 || palin[i + 1][j - 1]);
		}
		vector<vector<bool>> dp, ndp = palin;
		vector<int> ans(n, 0);
		for (int k = 0; 1 << k <= n; ++ k) {
			dp.swap(ndp);
			int cnt = 0;
			rep(i, n) rer(j, i + 1, n)
				cnt += dp[i][j];
			ans[k] = cnt;
			ndp.assign(n + 1, vector<bool>(n + 1));
			rep(i, n) rer(j, i + 2, n) {
				int h = (j - i) / 2;
				ndp[i][j] = palin[i][j] && dp[i][i + h] && dp[j - h][j];
			}
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}