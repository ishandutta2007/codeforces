#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);
		sort(all(a));
		int A = *max_element(all(a));
		vector<double> prob(A * 2 + 1);
		rep(i, n) rep(j, n) if(i != j) {
			int diff = a[i] - a[j];
			prob[A + diff] += 1;
		}
		rer(s, -A, A) prob[A + s] /= n * (n - 1);
		int B = A * 3;
		vector<vector<double> > dp(3 + 1, vector<double>(B * 2 + 1));
		dp[0][B + 0] = 1;
		rep(k, 3) rer(s, -B, B) {
			double x = dp[k][B + s];
			if(x < 1e-99) continue;
			if(k == 0 || k == 1) {
				rer(a, -A, -1)
					dp[k + 1][B + (s + a)] += prob[A + a] * x;
			} else {
				rer(a, 1, A)
					dp[k + 1][B + (s + a)] += prob[A + a] * x;
			}
		}
		double ans = 0;
		rer(s, 1, B)
			ans += dp[3][B + s];
		ans *= 8;
		printf("%.10f\n", ans);
	}
	return 0;
}