#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, k, d, len, lp, a[N];
int laz[N << 2], val[N << 2];
void tag(int x, int v) {laz[x] += v, val[x] += v;}
void down(int x) {if(laz[x]) tag(x << 1, laz[x]), tag(x << 1 | 1, laz[x]), laz[x] = 0;}
void push(int x) {val[x] = min(val[x << 1], val[x << 1 | 1]);}
void modify(int l, int r, int ql, int qr, int x, int v) {
	if(ql > qr) return;
	if(ql <= l && r <= qr) return tag(x, v);
	int m = l + r >> 1; down(x);
	if(ql <= m) modify(l, m, ql, qr, x << 1, v);
	if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
	push(x);
}
int query(int l, int r, int ql, int qr, int x, int v) {
	if(val[x] > v) return -1;
	if(l == r) return l;
	int m = l + r >> 1, res = -1; down(x);
	if(m < qr) res = query(m + 1, r, ql, qr, x << 1 | 1, v);
	if(ql <= m && res == -1) res = query(l, m, ql, qr, x << 1, v);
	return res;
}
int main() {
	cin >> n >> k >> d;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += inf;
	if(d == 0) {
		for(int l = 1, r = 1; l <= n; r = l = r + 1) {
			while(r < n && a[r + 1] == a[r]) r++;
			if(r - l + 1 > len) len = r - l + 1, lp = l;
		}
		cout << lp << " " << lp + len - 1 << endl;
		exit(0);
	}
	for(int l = 1, r = 1; l <= n; r = l = r + 1) {
		while(r < n && a[r + 1] % d == a[r] % d) r++;
		stack <pair <int, int>> mn, mx;
		map <int, int> mp;
		mn.push({r + 1, -1}), mx.push({r + 1, 2 * inf + 1});
		for(int p = r, limit = r; p >= l; p--) {
			int val = a[p] / d;
			modify(1, n, p + 1, r, 1, -1);
			if(mp.find(val) != mp.end()) limit = min(limit, mp[val] - 1);
			while(1) {
				pair <int, int> tp = mx.top();
				if(tp.second > val) break;
				mx.pop(), modify(1, n, tp.first, mx.top().first - 1, 1, val - tp.second);
			}
			while(1) {
				pair <int, int> tp = mn.top();
				if(tp.second < val) break;
				mn.pop(), modify(1, n, tp.first, mn.top().first - 1, 1, tp.second - val);
			}
			int ans = query(1, n, p, limit, 1, k);
			if(ans - p + 1 > len || ans - p + 1 == len && p < lp) lp = p, len = ans - p + 1;
			mp[val] = p, mn.push({p, val}), mx.push({p, val});
		}
	}
	cout << lp << " " << lp + len - 1 << endl;
	return 0;
}

/*
10 0 1
8 5 6 2 3 4 8 10 4 7
*/