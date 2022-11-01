#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, A = 26;
int n, q;
string s;

int seg[N * 4][A];
int cnt[A];
int lazy[N * 4];

void build(int id = 1, int L = 0, int R = n) {
	for (int i = L; i < R; i++) {
		seg[id][s[i] - 'a']++;
	}
	if (R - L == 1) {
		return;
	}
	int md = (R + L) / 2;
	build(id * 2, L, md);
	build(id * 2 + 1, md, R);
}
void shift(int id, int s, int e) {
	int md = (s + e) / 2;
	if (lazy[id] != 0) {
		lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];
	}
	
//	for (int i = 0; i < A; i++) {
//		cout << "78 " << id << " " << i << " " << seg[id][i] << endl;
//	}
	if (lazy[id] == 1) {
		int sm = 0;
		for (int i = 0; i < A; i++) {
			int x = min(seg[id][i], md - s - sm);
			seg[id][i] -= x;
			sm += x;
			seg[id * 2][i] = x;
			seg[id * 2 + 1][i] = seg[id][i];
			seg[id][i] = 0;
		}
	}
	if (lazy[id] == -1) {
		int sm = 0;
		for (int i = A - 1; i >= 0; i--) {
			int x = min(seg[id][i], md - s - sm);
			seg[id][i] -= x;
			sm += x;
			seg[id * 2][i] = x;
			seg[id * 2 + 1][i] = seg[id][i];
			seg[id][i] = 0;
		}		
	}
//	for (int i = 0; i < A; i++) {
//		cout << "79 " << id << " " << i << " " << seg[id * 2][i] << " " << seg[id * 2 + 1][i] << endl;
//	}
	lazy[id] = 0;
}
void get(int l, int r, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		for (int i = 0; i < A; i++) {
			cnt[i] += seg[id][i];
		//	seg[id][i] = 0;
		}
		return;
	}
	shift(id, s, e);
	int md = (s + e) / 2;
	get(l, r, id * 2, s, md);
	get(l, r, id * 2 + 1, md, e);
	for (int i = 0; i < A; i++) {
		seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
	}
}
void update(int l, int r, int as, int id = 1, int s = 0, int e = n) {
	if (r <= s || e <= l) {
		return;
	}
	if (l <= s && e <= r) {
		lazy[id] = as;
		if (as == 1) {
		//	cout << 75 << endl;
			int sm = 0;
			for (int i = 0; i < A; i++) {
				int x = min(cnt[i], e - s - sm);
			//	cout << "76 " << i << " " << x << " " << sm << endl;
				cnt[i] -= x;
				sm += x;
				seg[id][i] = x;
			}
		}
		else {
			int sm = 0;
			for (int i = A - 1; i >= 0; i--) {
				int x = min(cnt[i], e - s - sm);
				cnt[i] -= x;
				sm += x;
				seg[id][i] = x;
			}			
		}
		return;
	}
	shift(id, s, e);
	int md = (s + e) / 2;
	update(l, r, as, id * 2, s, md);
	update(l, r, as, id * 2 + 1, md, e);
	for (int i = 0; i < A; i++) {
		seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
	}	
}

int main() {
	cin >> n >> q >> s;
	build();
	for (int i = 0; i < q; i++) {
		int l, r, as;
		cin >> l >> r >> as;
		if (as == 0) {
			as = -1;
		}
		l--;
		get(l, r);
	//	for (int j = 0; j < A; j++) {
	//		cout << "71 " << j << " " << cnt[j] << endl;
	//	}
		update(l, r, as);
	//	for (int j = 0; j < A; j++) {
	//		cout << "73 " << j << " " << seg[1][j] << endl;
	//	}
	}
	for (int i = 0; i < n; i++) {
		get(i, i + 1);
		for (int j = 0; j < A; j++) {
		//	cout << "72 " << j << " " << cnt[j] << endl;
			if (cnt[j]) {
				cout << (char) ('a' + j);
				cnt[j] = 0;
			}
		}
	}
	
	return 0;
}