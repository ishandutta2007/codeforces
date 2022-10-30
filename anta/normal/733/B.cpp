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
		vector<int> L(n);
		vector<int> R(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d%d", &L[i], &R[i]);
		int sumL = accumulate(L.begin(), L.end(), 0);
		int sumR = accumulate(R.begin(), R.end(), 0);
		pii ans(abs(sumL - sumR), -1);
		rep(i, n) {
			int l = sumL - L[i] + R[i], r = sumR - R[i] + L[i];
			amax(ans, make_pair(abs(l - r), i));
		}
		printf("%d\n", ans.second + 1);
	}
	return 0;
}