#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const signed int inf = (signed) (~0u >> 1);

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

typedef class Place {
	public:
		int s, len, t, id;

		boolean operator < (Place b) const {
			return s < b.s;
		}

		void read() {
			scanf("%d%d%d", &s, &len, &t);
		}
} Place;

typedef class Segment {
	public:
		int l, r;

		Segment() {	}
		Segment(int l, int r) : l(l), r(r) {	}

		boolean in(int x) {
			return l <= x && x <= r;
		}
} Segment;

typedef class Decision {
	public:
		int s, id;
		Decision* prev;

		Decision() {	}
		Decision(int s, int id, Decision* prev) : s(s), id(id), prev(prev) {	}
} Decision;

boolean upd(int& a, int b) {
	return (a > b && ((a = b) || 1));
}

const int N = 22, S = 1 << N;

#define pii pair<int, int>

int n,  _;
int f[S];
Place p[N];
Segment ss[N];
Decision g[S];
vector<pii> vs;
pair<int, int> _dec[N];

int find(int require) {
/*	int l = 0, r = vs.size() - 1, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (vs[mid].first >= require)
			r = mid - 1;
		else
			l = mid + 1;
	} */
	for (int i = 0; i < (signed) vs.size(); i++) {
		if (vs[i].first >= require) {
			return vs[i].second;
		}
 	}
	assert(false);
//	return (r == (signed) vs.size()) ? (inf) : (vs[r].second);
}

inline void init() {
	scanf("%d%d", &n, &_);
	for (int i = 0; i < n; i++) {
		p[i].read();
		p[i].id = i;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		ss[i] = Segment(p[i].s, p[i].s + p[i].len - 1);
	}
}

inline void solve() {
	int all = (1 << n);
	pfill(f, f + all, inf);
	f[0] = 0;
	for (int s = 0; s < all - 1; s++) {
		if (f[s] == inf) {
			continue;
		}
		if (_ == 1 && f[all - 1] != inf) {
			break;
		}
		if (_ == 2 && f[(all - 1) ^ s] != inf) {
			break;
		}
		int V = f[s];
		for (int i = 0; i < n; i++) {
			if (ss[i].in(V)) {
				V = ss[i].r + 1;
			}
		}
		int lst = 0;
		vs.clear();
		for (int i = 0, L, len; i < n; i++) {
			if (s & (1 << i)) {
				L = max(lst + 1, V);
				if (L < ss[i].l) {
					len = ss[i].l - L - 1;
					if (len && (vs.empty() || vs.back().first < len)) {
						vs.push_back(pii(len, L));
					}
				}
				lst = ss[i].r;
			} else if (ss[i].l == lst + 1) {
				lst = ss[i].r;
			}
		}
		vs.push_back(pii(inf, lst + 1));
		for (int i = 0, cmp; i < n; i++) {
			if (!(s & (1 << i))) {
				cmp = find(p[i].t);
				if (cmp + p[i].t < p[i].s && upd(f[s | (1 << i)], cmp + p[i].t)) {
					g[s | (1 << i)] = Decision(cmp, p[i].id, g + s);
				}
			}
		}
	}
	if (_ == 1) {
		if (f[all - 1] == inf) {
			puts("NO");
			return;
		} else {
			puts("YES");
			for (Decision* d = g + (all - 1); d != g; d = d->prev) {
				_dec[d->id] = pair<int, int>(1, d->s);
			}
		}
	} else {
		boolean flag = true;
		all -= 1;
		for (int s = 0; s <= all && flag; s++) {
			if (f[s] != inf && f[all ^ s] != inf) {
				for (Decision *d = g + s; d != g; d = d->prev) {
					_dec[d->id] = pair<int, int>(1, d->s);
				}
				for (Decision *d = g + (all ^ s); d != g; d = d->prev) {
					_dec[d->id] = pair<int, int>(2, d->s);
				}
				flag = false;
			}
		}
		puts((flag) ? ("NO") : ("YES"));
		if (flag) {
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", _dec[i].first, _dec[i].second);
	}
}

int main() {
	init();
	solve();
	return 0;
}