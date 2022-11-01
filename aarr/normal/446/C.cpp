#include <iostream>
using namespace std;

const int N = 300 * 1000 + 15, mod = 1000 * 1000 * 1000 + 9;
int n, q;

int f[N];
int ps[N];
int a[N];
long long seg[N * 4];
long long l1[N * 4];
long long l2[N * 4];
void relax(int id, int s, int e) {
	int md = (s + e) / 2;
	l1[id * 2] += l1[id];
	l2[id * 2] += l2[id];
	l1[id * 2] %= mod;
	l2[id * 2] %= mod;
	l1[id * 2 + 1] += 1ll * l1[id] * f[md - s - 1];
	l1[id * 2 + 1] += 1ll * l2[id] * f[md - s];
	l1[id * 2 + 1] %= mod;
	l2[id * 2 + 1] += 1ll * l1[id] * f[md - s];
	l2[id * 2 + 1] += 1ll * l2[id] * f[md - s + 1];
	l2[id * 2 + 1] %= mod;
	long long x = 0, y = 0;
	x += 1ll * l1[id] * ps[md - s - 1];
	x += 1ll * l2[id] * ps[md - s];
	x %= mod;
	y += 1ll * l1[id] * ps[e - s - 1];
	y += 1ll * l2[id] * ps[e - s];
	y %= mod;
	seg[id * 2] += x;
	seg[id * 2] %= mod;
	seg[id * 2 + 1] += y + mod - x;
	seg[id * 2 + 1] %= mod;
	
	//cout << "73 " << id << " " << s << " " << e << " " << x << " " << y << endl;
	l1[id] = 0;
	l2[id] = 0;
}
void build(int id = 1, int s = 0, int e = n) {
	if (e - s == 1) {
		seg[id] = a[s];
		return;
	}
	int md = (s + e) / 2;
	build(id * 2, s, md);
	build(id * 2 + 1, md, e);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void kft(int id = 1, int s = 0, int e = n) {
	if (e - s == 1) {
		return;
	}
	relax(id, s, e);
	int md = (s + e) / 2;
	kft(id * 2, s, md);
	kft(id * 2 + 1, md, e);
}
void update(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return;
	}
	if (l <= s && e <= r) {
		l1[id] += f[s - l];
		l2[id] += f[s - l + 1];
		seg[id] += ps[e - l] - ps[s - l] + mod;
		l1[id] %= mod;
		l2[id] %= mod;
		seg[id] %= mod;
		return;
	}
	relax(id, s, e);
	int md = (s + e) / 2;
	update(l, r, id * 2, s, md);
	update(l, r, id * 2 + 1, md, e);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	seg[id] %= mod;
}
long long get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (e <= l || r <= s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return seg[id];
	}
	relax(id, s, e);
	long long ans = 0;
	int md = (s + e) / 2;
	ans += get(l, r, id * 2, s, md);
	ans += get(l, r, id * 2 + 1, md, e);
	ans %= mod;
//	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	f[1] = 1;
	ps[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
		ps[i] = ps[i - 1] + f[i];
		ps[i] %= mod;
		//cout << i << " " << f[i] << " " << ps[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build();
	for (int i = 0; i < q; i++) {
		int qt, l, r;
		cin >> qt >> l >> r;
		l--;
		if (qt == 1) {
			update(l, r);
		}
		else {
			cout << get(l, r) << '\n';
		}
	//	kft();
		//for (int j = 1; j <= 7; j++) {
		//	cout << j << " " << l1[j] << " " << l2[j] << " " << seg[j] << endl;
		//}
	}
	return 0;
}