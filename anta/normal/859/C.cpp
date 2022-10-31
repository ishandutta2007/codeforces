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
	int N;
	while (~scanf("%d", &N)) {
		vector<int> A(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &A[i]);
		vector<int> dp(N+1);
		dp[N] = 0;
		for (int i = N - 1; i >= 0; -- i) {
			int x = -INF;
			amax(x, A[i] - dp[i + 1]);
			amax(x, -A[i] + dp[i + 1]);
			dp[i] = x;
		}
		int ans = dp[0];
		int total = accumulate(A.begin(), A.end(), 0);
		printf("%d %d\n", (total - ans) / 2, (total + ans) / 2);
	}
	return 0;
}