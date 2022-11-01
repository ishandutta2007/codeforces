#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

//0-indexed
//       k
//     /   \
// 2k+1     2k+2
// ke (k-1)/2
// //calc AX\[X
class seg_tree {

public:

	vector<int> dat;
	int n;

	void init(int* d, int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), 0);
		for (int i = 0; i < size; i++) dat[n - 1 + i] = d[i];
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void propagate(int i) {
		dat[i] = dat[i * 2 + 1] &  dat[i * 2 + 2];
	}
	
	//[a,b)l
	int query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return 0xFFFFFFFF; //O
		if (a <= l && r <= b) return dat[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1; //q_
		int lval = query(a, b, nl, l, md);
		int rval = query(a, b, nr, md, r);

		return lval & rval;
	}
};

int a[ten(5) + 10][30];
int ans[ten(5) + 10];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	typedef pair < Pii, int > P;
	vector<P> vp;
	FOR(i, m) {
		int l, r, q; scanf("%d%d%d", &l, &r, &q);
		l--;
		FOR(j, 30) {
			if (q&(1 << j)) {
				a[l][j]++;
				a[r][j]--;
			}
		}
		vp.emplace_back(Pii(l, r), q);
	}
	int cur[30] = {};
	FOR(i, n) {
		FOR(j, 30) cur[j] += a[i][j];
		int val = 0;
		FOR(j, 30) if (cur[j]) val |= (1 << j);
		ans[i] = val;
	}

	seg_tree seg;
	seg.init(ans, n);

	bool ok = true;
	FOR(i, m) {
		int x = seg.query(vp[i].first.first, vp[i].first.second);
		if (x != vp[i].second) {
			ok = false;
			break;
		}
	}

	if (ok) {
		puts("YES");
		FOR(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	} else {
		puts("NO");
	}
}