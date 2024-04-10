#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Query {
	public:
		int l, r, id;

		boolean operator < (Query b) const {
			return l < b.l;
		}
} Query;

int n, m, q;
int *p, *a;
Query* qs;

deque<int> *pool;
deque<int> **vec;

inline void init() {
	scanf("%d%d%d", &n, &m, &q);
	p = new int[(n + 1)];
	a = new int[(m + 1)];
	qs = new Query[(q + 1)];
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		p[x] = i - 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", a + i);
		a[i] = p[a[i]];
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &qs[i].l, &qs[i].r);
		qs[i].id = i;
	}
}

char *res;
inline void solve() {
	if (n == 1) {
		res = new char[(q + 4)];
		for (int i = 1; i <= q; i++) {
			res[i] = '1';
		} 
		res[q + 1] = 0;
		puts(res + 1);
		return;
	}
	sort(qs + 1, qs + q + 1);
	Query* pq = qs + q;
	res = new char[(q + 4)];
	pool = new deque<int>[(m + 1)];
	vec = new deque<int>*[(n + 1)];
	int R = m + 1;
	for (int i = 0; i < n; i++) {
		vec[i] = NULL;
	}
	for (int i = m; i && pq != qs; i--) {
		int x = a[i], y = (x + 1) % n;
		if (vec[y]) {
			if (vec[x] && vec[x]->size() > vec[y]->size()) {
				for (int i = (signed) vec[y]->size() + 1; i; i--) {
					vec[x]->pop_back();
				}
				while (!vec[y]->empty()) {
					vec[x]->push_back(vec[y]->front());
					vec[y]->pop_front();
				}
				vec[x]->push_back(i);
				vec[y] = NULL;
			} else {
				vec[x] = vec[y];
				vec[y] = NULL;
				vec[x]->push_back(i);
			}
			while ((signed) vec[x]->size() > n) {
				vec[x]->pop_front();
			}
		} else {
			if (vec[x]) {
				vec[x]->pop_back();
				vec[x]->push_back(i);
				goto dispose;
			}
			vec[x] = pool++;
			vec[x]->push_back(i);
		}
		if ((signed) vec[x]->size() == n && vec[x]->front() < R) {
			R = vec[x]->front();
		}
dispose:
		while (pq != qs && pq->l == i) {
			res[pq->id] = '0' + (pq->r >= R);
			pq--;
		}
	}
	res[q + 1] = 0;
	puts(res + 1);
}

int main() {
	init();
	solve();
	return 0;
}