#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;
const int bzmax = 19;

typedef class Query {
	public:
		int l, r, id;

		Query(int l, int r, int id) : l(l), r(r), id(id) {	}

		boolean operator < (Query b) const {
			return l > b.l;
		}
} Query;

typedef class Data {
	public:
		int a[bzmax];

		Data() {
			for (int i = 0; i < bzmax; i++) {
				a[i] = N;
			}
		}

		void set(int x, int y) {
			for (int i = 0; i < bzmax; i++) {
				if ((y >> i) & 1) {
					a[i] = x;
				} else {
					a[i] = N;
				}
			} 
		}
} Data;

int n, m;
int a[N];
Data ds[N];
boolean ans[N];
int lst[bzmax];
boolean vis[N];
vector<Query> qs;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		qs.emplace_back(l, r, i);
	}
	for (int i = 0; i < bzmax; i++) {
		lst[i] = N;
	}
	sort(qs.begin(), qs.end());
	vector<Query>::iterator pq = qs.begin();
	for (int r = n; r; r--) {
		ds[r].set(r, a[r]);
		for (int i = 0; i < bzmax; i++) {
			if (((a[r] >> i) & 1) && lst[i] != N && !vis[lst[i]]) {
				for (int j = 0; j < bzmax; j++) {
					ds[r].a[j] = min(ds[lst[i]].a[j], ds[r].a[j]);
				}
				vis[lst[i]] = true;
			}
		}
		for (int i = 0; i < bzmax; i++) {
			if (((a[r] >> i) & 1)) {
				if (lst[i] != N) {
					vis[lst[i]] = false;
				}
				lst[i] = r;
			}
		}
		while (pq != qs.end() && pq->l == r) {
			boolean res = false;
			for (int i = 0; i < bzmax && !res; i++) {
				if ((a[pq->r] >> i) & 1) {
					res = pq->r >= ds[r].a[i];
				}
			}
			ans[pq->id] = res;
			pq++;
		}
	}
	for (int i = 1; i <= m; i++) {
		puts((ans[i]) ? ("Shi") : ("Fou"));
	}
	return 0;
}