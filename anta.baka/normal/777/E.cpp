#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct block {
	int rin, rout, h;
	int insort;
	block(){}
	bool operator < (const block &x) const {
		return rout > x.rout || rout == x.rout && rin > x.rin;
	}
};

int n;
vector<ll> st;

void upd(int v, ll val) {
	st[v += n] = val;
	for(v >>= 1; v; v >>= 1) {
		st[v] = max(st[v * 2], st[v * 2 + 1]);
	}
}

ll get(int l, int r) {
	ll res = 0;
	for(l += n, r += n; l <= r; l = (l+1)>>1, r = (r-1)>>1) {
		if(l & 1) {
			res = max(res, st[l]);
		}
		if(!(r & 1)) {
			res = max(res, st[r]);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vector<block> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].rin >> a[i].rout >> a[i].h;
	}
	sort(a.begin(), a.end());
	vector<pair<int,int>> ord(n);
	for(int i = 0; i < n; i++) {
		ord[i] = {a[i].rin, i};
	}
	sort(ord.begin(), ord.end());
	for(int i = 0; i < n; i++) {
		a[ord[i].second].insort = i;
	}
	st.assign(2 * n, 0);
	for(int i = 0; i < n; i++) {
		int bl = 0, br = n - 1;
		while(bl < br) {
			int bm = (bl + br)>>1;
			if(bl == bm) {
				bm++;
			}
			if(ord[bm].first < a[i].rout) {
				bl = bm;
			} else {
				br = bm - 1;
			}
		}
		ll pr = get(0, bl);
		upd(a[i].insort, pr + a[i].h);
	}
	cout << get(0, n - 1);
}