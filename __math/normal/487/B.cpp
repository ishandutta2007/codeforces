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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

class mnQuery {
public:
	vector<int> dat;
	int n;

	mnQuery(int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), ten(8));
	}

	void propagate(int i) {
		dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

	//k(0-indexed)valXV
	void update(int k, int val) {
		k += n - 1;
		dat[k] = val;
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	//[a,b)l
	int query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return ten(8); //O
		if (a <= l && r <= b) return dat[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1; //q_
		int lval = query(a, b, nl, l, md);
		int rval = query(a, b, nr, md, r);

		return min(lval, rval); //calc
	}
};

static const Pii dflt(INT_MAX, INT_MIN);
class minmax_query {
public:
	vector<Pii> dat;
	int n;

	minmax_query(int* d, int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), dflt);

		for (int i = 0; i < size; i++) {
			dat[n - 1 + i].first = d[i];
			dat[n - 1 + i].second = d[i];
		}
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	Pii combain(Pii l, Pii r){
		return Pii(min(l.first, r.first), max(l.second, r.second));
	}

	void propagate(int i) {
		dat[i] = combain(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

	//[a,b)l
	Pii query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	Pii query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return dflt; //O
		if (a <= l && r <= b) return dat[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1; //q_
		Pii lval = query(a, b, nl, l, md);
		Pii rval = query(a, b, nr, md, r);

		return combain(lval, rval); //calc
	}
};

int n, s, l;
int a[ten(5) + 1];

int lft[ten(5) + 1];

int main(){
	scanf("%d%d%d", &n, &s, &l);
	FOR(i, n) scanf("%d", a + i);

	minmax_query nx(a,n);

	int li = 0;
	FOR(i, n){
		while (li < i) {
			auto pi = nx.query(li, i + 1);
			if (ll(pi.second) - pi.first <= s) break;
			li++;

		}
		lft[i] = li;
	}

	mnQuery seg(n + 10);
	seg.update(0, 0);
	FOR(i, n){
		int segl = lft[i];
		int segr = i - l + 2;
		if (segl < segr) {
			int mn_val = seg.query(segl, segr);
			seg.update(i + 1, mn_val + 1);
		}
	}

	int ans = seg.query(n, n + 1);
	if (ans > ten(6)) ans = -1;
	cout << ans << endl;

}