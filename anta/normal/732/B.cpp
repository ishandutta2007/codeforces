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
	int n; int k;
	while(~scanf("%d%d", &n, &k)) {
		vector<int> a(n + 1);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		int ans = 0;
		rep(i, n - 1) {
			int x = a[i] + a[i + 1];
			if(x < k) {
				ans += k - x;
				a[i + 1] += k - x;
			}
		}
		printf("%d\n", ans);
		for(int i = 0; i < n; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
	}
	return 0;
}