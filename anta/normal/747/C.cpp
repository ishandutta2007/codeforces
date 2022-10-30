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
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<int> time(n, 0);
		vector<int> cur;
		rep(ii, q) {
			int t; int k; int d;
			scanf("%d%d%d", &t, &k, &d);
			cur.clear();
			rep(i, n) {
				if (k > 0 && time[i] <= t) {
					cur.push_back(i);
					--k;
				}
			}
			if (k == 0) {
				int sum = 0;
				for (int i : cur) {
					sum += i + 1;
					time[i] = t + d;
				}
				printf("%d\n", sum);
			}
			else {
				puts("-1");
			}
		}
	}
	return 0;
}