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
		vector<int> a(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		vector<int> b(k);
		for (int i = 0; i < k; ++ i)
			scanf("%d", &b[i]);
		sort(b.rbegin(), b.rend());
		int m = 0;
		rep(i, n) if (a[i] == 0)
			a[i] = b[m ++];
		bool ans = true;
		rep(i, n - 1)
			ans &= a[i] < a[i + 1];
		ans = !ans;
		puts(ans ? "Yes" : "No");
	}
	return 0;
}