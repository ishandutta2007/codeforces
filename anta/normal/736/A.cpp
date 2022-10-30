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
	long long n;
	while(~scanf("%lld", &n)) {
		vector<ll> fib;
		fib.push_back(0);
		fib.push_back(1);
		while(fib.back() <= n) {
			fib.push_back(fib.end()[-1] + fib.end()[-2]);
		}
		int ans = (int)(fib.size() - 4);
		printf("%d\n", ans);
	}
	return 0;
}