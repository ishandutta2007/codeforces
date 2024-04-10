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
		vector<int> p(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &p[i]), -- p[i];
		vector<int> b(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &b[i]);
		vector<bool> vis(n);
		int cycles = 0, singles = 0;
		rep(i, n) if (!vis[i]) {
			int j = i;
			while (!vis[j]) {
				vis[j] = true;
				j = p[j];
			}
			singles += p[i] == i;
			++ cycles;
		}
		int ans = cycles == 1 ? 0 : cycles;
		if (accumulate(b.begin(), b.end(), 0) % 2 == 0)
			++ ans;
		printf("%d\n", ans);
	}
	return 0;
}