#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool isPrime(int n) {
	for(int d = 2; d * d <= n; ++ d) if(n % d == 0)
		return false;
	return true;
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		int ans;
		if(isPrime(n)) {
			ans = 1;
		} else if(n % 2 == 0 || isPrime(n - 2)) {
			ans = 2;
		} else {
			ans = 3;
		}
		printf("%d\n", ans);
	}
	return 0;
}