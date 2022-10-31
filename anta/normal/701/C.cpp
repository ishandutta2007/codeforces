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
	int n;
	while(~scanf("%d", &n)) {
		char s[100001];
		scanf("%s", s);
		int cnt[128] = {};
		rep(i, n) ++ cnt[s[i]];
		int A = 0;
		rep(a, 128) A += cnt[a] != 0;
		rep(a, 128) cnt[a] = 0;
		int j = 0, x = 0;
		int ans = INF;
		rep(i, n) {
			for(; j < n && x < A; ++ j)
				x += ++ cnt[s[j]] == 1;
			if(x == A)
				amin(ans, j - i);
			x -= -- cnt[s[i]] == 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}