#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

void relax(int &x, int y) { x = max(x, y); }

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	if (n < m) swap(n, m);
	vector<int> f(1 << (m + m), -1000000);
	f[0] = 0;
	int msk = (1 | (7 << (m - 1)) | (1 << (m + m)));
	REP (i, n + 1) REP (j, m) {
		vi g(1 << (m + m), -1000000);
		REP (p, sz(f)) if (f[p] >= 0) {
			int q = p;
			if (i < n) q |= 1 << (m + m);
			relax(g[q >> 1], f[p]);
			if (i > 0) {
				int z = q & msk;
				int top = q & 1;
				int left = j > 0 ? q >> (m - 1) & 1 : 0;
				int center = q >> m & 1;
				int right = j + 1 < m ? q >> (m + 1) & 1 : 0;
				int bottom = i < n ? q >> (m + m) & 1 : 0;
				if (left) q ^= 1 << (m - 1);
				if (center) q ^= 1 << m;
				if (right) q ^= 1 << (m + 1);
				if (bottom) q ^= 1 << (m + m);
				relax(g[q >> 1], f[p] + left + top + right + bottom - (1 - center));
			}
		}
		f.swap(g);	
	}
	cout << *max_element(all(f)) << endl;
	return 0;
}