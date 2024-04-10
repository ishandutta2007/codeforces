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
	int n; int k;
	while (~scanf("%d%d", &n, &k)) {
		vector<int> ans(n, -1);
		rep(i, k - 1)
			ans[i] = i;
		rep(i, n - k + 1) {
			char buf[101];
			scanf("%s", buf);
			ans[k - 1 + i] = *buf == 'N' ? ans[i] : k - 1 + i;
		}
		rep(i, n) {
			string s;
			s += char('A' + ans[i] / 26);
			s += char('a' + ans[i] % 26);
			printf("%s ", s.c_str());
		}
		puts("");
	}
	return 0;
}