#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, ori[N];
struct pony {
	int s, m, r, p, need;
	bool operator < (const pony &v) const {return need > v.need;} // >= -> >
} p[N], o[N];
struct seq {
	int l, r, t;
	bool operator < (const seq &v) const {return l != v.l ? l < v.l : r < v.r;}
};
set <seq> s;
void split(int p) {
	if(p == 0 || p == n) return;
	auto it = --s.upper_bound({p, n + 1, 0});
	if(it -> r == p) return;
	s.insert({it -> l, p, it -> t}), s.insert({p + 1, it -> r, it -> t}), s.erase(it);
}
int node, R[N], ls[N << 5], rs[N << 5];
long long summ[N << 5], sumr[N << 5];
void modify(int pre, int &x, int l, int r, int p, int vm, int vr) {
	ls[x = ++node] = ls[pre], rs[x] = rs[pre];
	summ[x] = summ[pre] + vm, sumr[x] = sumr[pre] + vr;
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(ls[pre], ls[x], l, m, p, vm, vr);
	else modify(rs[pre], rs[x], m + 1, r, p, vm, vr);
}
long long query(int l, int r, int ql, int qr, int x, int y, long long *val) {
	if(ql <= l && r <= qr) return val[y] - val[x];
	int m = l + r >> 1;
	long long ans = 0;
	if(ql <= m) ans += query(l, m, ql, qr, ls[x], ls[y], val);
	if(m < qr) ans += query(m + 1, r, ql, qr, rs[x], rs[y], val);
	return ans;
}
int main() {
	cin >> n, s.insert({1, n, 0});
	for(int i = 1; i <= n; i++) {
		cin >> p[i].s >> p[i].m >> p[i].r, o[i] = p[i];
		p[i].need = !p[i].r ? 1e9 + 7 : p[i].m / p[i].r, p[i].p = i;
	}
	sort(p + 1, p + n + 1), cin >> m;
	for(int i = 1; i <= n; i++) modify(R[i - 1], R[i], 1, n, p[i].p, p[i].m, p[i].r);
	for(int i = 1; i <= m; i++) {
		int t, l, r;
		long long ans = 0;
		cin >> t >> l >> r;
		split(l - 1), split(r);
		while(1) {
			auto it = s.lower_bound({l, 0, 0});
			if(it == s.end() || it -> l > r) break;
			if(!it -> t)
				for(int j = it -> l; j <= it -> r; j++)
					ans += min((long long)o[j].m, o[j].s + 1ll * t * o[j].r);
			else {
				int lb = 0, rb = n, dt = t - it -> t;
				while(lb < rb) {
					int m = lb + rb + 2 >> 1;
					if(dt <= p[m].need) lb = m;
					else rb = m - 1;
				}
				if(lb) ans += dt * query(1, n, it -> l, it -> r, 0, R[lb], sumr);
				if(lb < n) ans += query(1, n, it -> l, it -> r, R[lb], R[n], summ);
			}
			s.erase(it);
		}
		cout << ans << "\n";
		s.insert({l, r, t});
	}
	return 0;
}