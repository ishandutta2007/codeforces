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
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	vector<int> b(m);
	rep(i, m) scanf("%d", &b[i]);
	int A = *max_element(all(a)) + 1;
	int powAs[6];
	powAs[0] = 1;
	rep(i, n) powAs[i+1] = powAs[i] * A;
	int P = powAs[n];
	int S = (m+1) * P * (1 << n);
	vector<int> runs(1 << n, 0);
	rep(i, 1 << n) rep(j, n)
		runs[i] += (i >> j & 3) == 1;
	vector<char> dp(S, -1);
	int initp = 0;
	rep(i, n) initp += powAs[i] * a[i];
	dp[(0 * P + initp) << n | 0] = 0;
	rep(j, m) rep(p, P) {
		char ps[5];
		rep(k, n) ps[k] = p / powAs[k] % A;
		rep(t, 1 << n) if(dp[(j * P + p) << n | t] != -1) {
//			cerr << j; rep(k, n) cerr << (k == 0 ? "; " : ", ") << (int)ps[k]; cerr << "; "; rep(k, n) cerr << ".*"[t >> k & 1]; cerr << endl;
			rep(u, 1 << n) if(runs[u] == b[j]) {
				int newruns = ~t & u;
				int newp = p;
				rep(k, n) if(newruns >> k & 1) {
					if(ps[k] == 0) {
						newp = -1;
						break;
					}else {
						newp -= powAs[k];
					}
				}
				if(newp != -1)
					dp[((j+1) * P + newp) << n | u] = t;
			}
		}
	}
	int t;
	for(t = 0; t < (1 << n); ++ t) {
		if(dp[(m * P + 0) << n | t] != -1)
			break;
	}
	if(t == (1 << n)) {
		cerr << "err" << endl;
		abort();
	}
	int p = 0;
	vector<string> ans(n, string(m, '?'));
	for(int j = m-1; j >= 0; -- j) {
		rep(k, n)
			ans[k][j] = ".*"[t >> k & 1];
		int u = dp[((j+1) * P + p) << n | t];
		rep(k, n) if((~u >> k & 1) && (t >> k & 1)) {
			p += powAs[k];
		}
		t = u;
	}
	if(t != 0 || p != initp) {
		cerr << "err 2" << endl;
		abort();
	}
	rep(i, n)
		cout << ans[i] << endl;
	return 0;
}