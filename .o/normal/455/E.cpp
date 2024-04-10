#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

struct line {
	ll a, b;
	line (ll a = 0, ll b = 0): a(a), b(b) { }
	bool operator< (const line &l) const {
		return a != l.a ? a < l.a : b < l.b;
	}
};

struct CHT {
	vector<line> s;
	int f;

	void add (line l) {
		while(s.size() >= 2) {
			line &p = s[s.size() - 2];
			line &q = s[s.size() - 1];
			if((lf)(p.b - l.b) / (l.a - p.a) < (lf)(q.b - l.b) / (l.a - q.a)) {
				s.pop_back();
			}else {
				break;
			}
		}
		s.push_back(l);
	}

	ll get (int x) {
		while(f+1 < s.size() && s[f].a * x + s[f].b >= s[f+1].a * x + s[f+1].b) ++f;
		return s[f].a * x + s[f].b;
	}
};

const int N_ = 100500, M_ = 100500;
int N, M; ll A[N_]; ll SA[N_];
line lines[N_], tmp[N_];

const int LEAF = 131072;
CHT tree[LEAF + LEAF];

void make_tree (int nd, int nl, int nr) {
	if(nl == nr) {
		tree[nd].add(lines[nl]);
		return;
	}

	int nm = (nl + nr) >> 1;
	make_tree(nd + nd, nl, nm);
	make_tree(nd + nd + 1, nm + 1, nr);

	for(int i = nl, j = nm+1, k = nl; i <= nm || j <= nr; k++) {
		line p = (i <= nm) ? lines[i] : line((ll)1e18);
		line q = (j <= nr) ? lines[j] : line((ll)1e18);
		tmp[k] = (p < q) ? lines[i++] : lines[j++];
	}
	for(int i = nl; i <= nr; i++) {
		lines[i] = tmp[i];
		if(i == nl || lines[i].a != lines[i-1].a) 
			tree[nd].add(lines[i]);
	}

}

ll calc (int nd, int nl, int nr, int ql, int qr, int x) {
	if(nl > qr || nr < ql || nl > nr || ql > qr) return (ll)1e18;
	if(ql <= nl && nr <= qr) return tree[nd].get(x);

	int nm = (nl + nr) >> 1;
	return min(calc(nd + nd,     nl,   nm, ql,            min(nm, qr), x),
			   calc(nd + nd + 1, nm+1, nr, max(nm+1, ql), qr,          x) );
}

int X[M_], Y[M_];
vector<int> queries[N_];
ll ans[M_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", A+i);
		SA[i] = SA[i-1] + A[i];
		lines[i] = line(A[i], (ll)A[i] * i - SA[i]);
	}
	make_tree(1, 1, N);
	for(int i = 1; i <= N; i++) {
		lines[i] = line(A[i], (ll)A[i] * i - SA[i]);
	}

	scanf("%d", &M);
	for(int i = 1; i <= M; i++) {
		int x, y; scanf("%d%d", &x, &y);
		X[i] = x; Y[i] = y;
		queries[y-x].push_back(i);
	}

	for(int p = 0; p <= N; p++) {
		for(auto q : queries[p]) {
			int x = X[q], y = Y[q];
			ans[q] = calc(1, 1, N, y-x+1, y, x-y) + SA[y];
		}
	}
	for(int i = 1; i <= M; i++) {
		printf("%lld\n", ans[i]);
	}
    return 0;
}