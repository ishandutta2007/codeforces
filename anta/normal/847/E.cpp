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
	int n;
	while (~scanf("%d", &n)) {
		char S[100001];
		scanf("%s", S);
		int lo = 0, up = n * 2;
		while (up - lo > 0) {
			int t = (lo + up) / 2;
			int j = 0;
			vector<int> L(n, 0), R(n, 0);
			bool ok = true;
			rep(i, n) if (S[i] == '*') {
				for (; ; ++ j) {
					for (; j < n && S[j] != 'P'; ++ j);
					if (j == n) {
						ok = false;
						break;
					}
					if (i < j) {
						if (j - i <= t) {
							amax(L[j], j - i);
							break;
						}
					} else {
						if (L[j] + (i - j) + min(L[j], i - j) <= t) {
							amax(R[j], i - j);
							break;
						}
					}
				}
			}
			if (ok)
				up = t;
			else
				lo = t + 1;
		}
		int ans = up;
		printf("%d\n", ans);
	}
	return 0;
}