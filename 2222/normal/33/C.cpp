#include <algorithm>
#include <iostream>
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

int a[111111], n;
int p[111111], q[111111], f[111111], g[111111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) {
		scanf("%d", a + i);
		p[i] = a[i];
		if (i) p[i] += p[i - 1];
		f[i] = max(p[i], -p[i]);
		if (i) f[i] = max(f[i], f[i - 1] + a[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		q[i] = a[i];
		q[i] += q[i + 1];
		g[i] = max(q[i], -q[i]);
		if (i + 1 < n) g[i] = max(g[i], g[i + 1] + a[i]);
	}
	int res = f[n - 1];
	REP (i, n - 1) res = max(res, f[i] + g[i + 1]);
	cout << res << endl;
	return 0;
}