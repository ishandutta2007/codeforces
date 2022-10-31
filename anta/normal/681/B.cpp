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
		const int X = 1234567, Y = 123456, Z = 1234;
		bool ans = false;
		for(int a = 0; a * X <= n; ++ a) {
			int m = n - a * X;
			for(int b = 0; b * Y <= m; ++ b) {
				if((m - b * Y) % Z == 0) {
					ans = true;
				}
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}