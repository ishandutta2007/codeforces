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
	char S[100001];
	while (~scanf("%s", S)) {
		int cnt[128] = {};
		for (const char *p = S; *p; ++ p)
			++ cnt[*p];
		int div[128] = {};
		for (char c : "Bulbasaur") if (c)
			++ div[c];
		int ans = INF;
		rep(a, 128) if (div[a])
			amin(ans, cnt[a] / div[a]);
		printf("%d\n", ans);
	}
	return 0;
}