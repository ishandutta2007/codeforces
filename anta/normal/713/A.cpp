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
	int Q;
	while(~scanf("%d", &Q)) {
		vector<int> cnt(1 << 18);
		for(int ii = 0; ii < Q; ++ ii) {
			char ty[10];
			scanf("%s", ty);
			long long x;
			scanf("%lld", &x);
			int k = 0, t = 0;
			while(x > 0) {
				t |= (x % 10 % 2) << (k ++);
				x /= 10;
			}
			if(*ty == '+' || *ty == '-') {
				cnt[t] += *ty == '+' ? 1 : -1;
			}else if(*ty == '?') {
				printf("%d\n", cnt[t]);
			} else abort();
		}
	}
	return 0;
}