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
		vector<int> parent(n, -1);
		reu(i, 1, n) {
			int p;
			scanf("%d", &p), -- p;
			parent[i] = p;
		}
		vector<int> size(n, 1);
		for(int i = n - 1; i > 0; -- i)
			size[parent[i]] += size[i];
		vector<double> ans(n);
		ans[0] = 1;
		reu(i, 1, n) {
			int p = parent[i];
			double x = ans[p] + 1;
			x += (size[p] - size[i] - 1) * .5;
			ans[i] = x;
		}
		rep(i, n) {
			if(i != 0) putchar(' ');
			printf("%.1f", ans[i]);
		}
		puts("");
	}
	return 0;
}