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
	int k;
	while (~scanf("%d", &k)) {
		char S[100002];
		scanf("%s", S);
		int rem = k;
		for (const char *p = S; *p; ++ p) {
			int d = *p - '0';
			rem -= d;
		}
		sort(S, S + strlen(S));
		int ans = 0;
		for (const char *p = S; *p; ++ p) {
			if (rem <= 0) break;
			int d = *p - '0';
			rem -= 9 - d;
			++ ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}