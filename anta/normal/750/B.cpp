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
	int n;
	while (~scanf("%d", &n)) {
		const int X = 20000;
		int sum = 0;
		bool ans = true;
		rep(i, n) {
			int x;
			scanf("%d", &x);
			char buf[101];
			scanf("%s", buf);
			if (sum == 0)
				ans &= *buf == 'S';
			if (sum == X)
				ans &= *buf == 'N';
			if (*buf == 'N') {
				sum -= x;
			} else if (*buf == 'S') {
				sum += x;
			}
			ans &= 0 <= sum && sum <= X;
		}
		ans &= sum == 0;
		puts(ans ? "YES" : "NO");
	}
	return 0;
}