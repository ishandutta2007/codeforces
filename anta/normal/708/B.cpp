#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

ll calc(int x) {
	return (ll)x * (x - 1) / 2;
}

int main() {
	int a00; int a01; int a10; int a11;
	while(~scanf("%d%d%d%d", &a00, &a01, &a10, &a11)) {
		int x0 = 0, y0 = 0;
		while(calc(x0) < a00) ++ x0;
		while(calc(y0) < a11) ++ y0;
		string ans;
		rer(x, x0, x0 + 1) rer(y, y0, y0 + 1) {
			if(calc(x) != a00 || calc(y) != a11) continue;
			int z = x + y;
			if((ll)a00 + a01 + a10 + a11 != calc(z)) continue;
			if((ll)x * y < a01) continue;
			int rem = a01;
			vector<int> v(y);
			rep(i, y) {
				v[i] = min(rem, x);
				rem -= v[i];
			}
			assert(rem == 0);
			int prev = x;
			rep(i, y) {
				while(prev > v[i]) {
					ans += '0';
					-- prev;
				}
				ans += '1';
			}
			while(prev > 0) {
				ans += '0';
				-- prev;
			}
			reverse(ans.begin(), ans.end());
			break;
		}
		if(ans.empty()) {
			puts("Impossible");
		} else {
			puts(ans.c_str());
		}
	}
	return 0;
}