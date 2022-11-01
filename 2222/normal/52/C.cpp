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

ll f[1 << 19], s[1 << 19], d[1 << 19];

void upd(int x) {
	if (ll z = d[x]) {
		d[x] = 0;
		f[x] += z;
		s[x] += z;
		x *= 2;
		d[x] += z;
		d[x + 1] += z;
	}
}

void inc(int i, int j, int v, int r = 1, int w = 1 << 18) {
	if (i >= w || j < 0) return;
	if (i <= 0 && j >= w - 1) {
		d[r] += v;
	} else {
		upd(r);
		int z = r * 2;
		w /= 2;
		inc(i, j, v, z, w);
		inc(i - w, j - w, v, z + 1, w);
		f[r] = min(f[z] + d[z], f[z + 1] + d[z + 1]);
	}
}

ll rmq(int i, int j, int r = 1, int w = 1 << 18) {
	if (i >= w || j < 0) return -1ull/2;
	if (i <= 0 && j >= w - 1)
		return f[r] + d[r];
	upd(r);
	int z = r * 2;
	w /= 2;
	return min(rmq(i, j, z, w), rmq(i - w, j - w, z + 1, w));
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n, m;
	cin >> n;
	REP (i, n) {
		int x;
		scanf("%d", &x);
		inc(i, i, x);
	}
	scanf("%d\n", &m);
	REP (i, m) {
		string s;
		getline(cin, s);
		int x, y, z; 
		if (sscanf(s.data(), "%d%d%d", &x, &y, &z) == 3) {
			if (x <= y) inc(x, y, z);
			else inc(x, n - 1, z), inc(0, y, z);
		} else {
			ll res = -1u/2;
			if (x <= y) res = rmq(x, y);
			else res = min(rmq(x, n - 1), rmq(0, y));
			printf("%I64d\n", res);
		}
	}
	return 0;
}