#include<bits/stdc++.h>
using namespace std;

struct Query {
	int l, r, type;
	Query(int _type, int _l, int _r) : type(_type), l(_l), r(_r) {}
};

vector<Query> que;

int b[105], a[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q, m;
	cin >> n >> q >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		int type, l, r;
		cin >> type >> l >> r;
		que.push_back(Query(type, l, r));
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int it = que.size() - 1; it >= 0; it--) {
		Query u = que[it];
		int type = u.type;
		int l = u.l;
		int r = u.r;
		for (int i = 1; i <= m; i++) {
			if (b[i] >= l && b[i] <= r) {
				if (type == 1) {
					if (b[i] != l) {
						b[i] = b[i] -1;
					} else {
						b[i] = r;
					}
				} else {
					b[i] = l + r - b[i];
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << a[b[i]] << ' ';
	}
	return 0;
}