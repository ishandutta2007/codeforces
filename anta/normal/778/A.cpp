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
	char S[200001];
	while (~scanf("%s", S)) {
		char P[200001];
		scanf("%s", P);
		int n = (int)strlen(S);
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]), -- a[i];
		vector<int> ix(n, -1);
		rep(i, n) ix[a[i]] = i;
		int lo = 0, up = n;
		while (up - lo > 0) {
			int mid = (lo + up + 1) / 2;
			int j = 0;
			rep(i, n) {
				if (mid <= ix[i]) {
					if (S[i] == P[j])
						++ j;
				}
			}
			if (P[j] == 0)
				lo = mid;
			else
				up = mid - 1;
		}
		int ans = lo;
		printf("%d\n", ans);
	}
	return 0;
}