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
		if(n <= 2) {
			puts("-1");
		} else {
			int x, y;
			if(n % 2 == 0) {
				x = 1;
				y = n / 2;
			} else {
				x = (n - 1) / 2;
				y = x + 1;
			}
			ll a = (ll)y * y - (ll)x * x;
			ll b = 2LL * y * x;
			ll c = (ll)y * y + (ll)x * x;
			if(n % 2 == 0)
				printf("%lld %lld\n", a, c);
			else
				printf("%lld %lld\n", b, c);
		}
	}
	return 0;
}