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
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<int> row(n), col(m);
		vector<vector<bool>> a(n, vector<bool>(m));
		rep(i, n) {
			char s[1001];
			scanf("%s", s);
			rep(j, m) if(s[j] == '*') {
				a[i][j] = true;
				++ row[i], ++ col[j];
			}
		}
		int total = accumulate(row.begin(), row.end(), 0);
		pii ans(-1, -1);
		rep(i, n) rep(j, m) {
			if(row[i] + col[j] - (a[i][j] ? 1 : 0) == total) {
				ans = { i, j };
			}
		}
		if(ans.first == -1) {
			puts("NO");
		} else {
			puts("YES");
			printf("%d %d\n", ans.first + 1, ans.second + 1);
		}

	}
	return 0;
}