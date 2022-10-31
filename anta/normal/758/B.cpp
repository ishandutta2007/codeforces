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
	char S[101];
	while (~scanf("%s", S)) {
		int n = (int)strlen(S);
		vector<int> perm(4);
		iota(perm.begin(), perm.end(), 0);
		do {
			bool ok = true;
			rep(i, n) {
				if(S[i] != '!')
					ok &= S[i] == "RBYG"[perm[i % 4]];
			}
			if (ok) break;
		} while (next_permutation(perm.begin(), perm.end()));
		vi ans(4, 0);
		rep(i, n) {
			if (S[i] == '!')
				++ ans[perm[i % 4]];
		}
		for (int i = 0; i < (int)ans.size(); ++ i) {
			if (i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}