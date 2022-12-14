/**
 *    author:  Atreus
 *    created: 17.01.2019 18:19:03     
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

int vec[33], m;

void ins(int x){
	for (int i = 0; i < m; i++){
		int rb = vec[i] & -vec[i];
		if (x & rb)
			x ^= vec[i];
	}
	if (x == 0)
		return;
	for (int i = 0; i < m; i++){
		int rb = x & -x;
		if (vec[i] & rb)
			vec[i] ^= x;
	}
	vec[m ++] = x;
}

void merge(vector <int> &to, vector <int> &fr1, vector <int> &fr2){
	m = 0;
	for (auto it : fr1)
		ins(it);
	for (auto it : fr2)
		ins(it);
	to.clear();
	for (int i = 0; i < m; i++)
		to.push_back(vec[i]);
	return;
}

vector <int> seg[4 * maxn];

void get(int id, int L, int R, int l, int r){
	if (L == l and R == r){
		for (auto it : seg[id])
			ins(it);
		return;
	}
	int mid = (L + R) >> 1;
	if (mid > l)
		get(2 * id + 0, L, mid, l, min(mid, r));
	if (mid < r)
		get(2 * id + 1, mid, R, max(l, mid), r);
}

int b[maxn], a[maxn];

void change(int id, int L, int R, int idx, int x){
	if (L + 1 == R){
		seg[id].clear();
		b[L] ^= x;
		if (b[L] != 0)
			seg[id].push_back(b[L]);
		return;
	}
	int mid = (L + R) >> 1;
	if (mid > idx)
		change(2 * id + 0, L, mid, idx, x);
	else
		change(2 * id + 1, mid, R, idx, x);
	merge(seg[id], seg[2 * id + 0], seg[2 * id + 1]);
}

void build(int id, int L, int R){
	if (L + 1 == R){
		if (b[L] != 0)
			seg[id].push_back(b[L]);
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	merge(seg[id], seg[2 * id + 0], seg[2 * id + 1]);
}

int n;

int fen[maxn];

void add(int idx, int x){
	for (; idx <= n; idx += idx & -idx)
		fen[idx] ^= x;
}

int get_fen(int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret ^= fen[idx];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i - 1){
			b[i] = a[i] ^ a[i - 1];
		}
	}
	build(1, 1, n + 1);
	for (int i = 1; i <= q; i++){
		int type;
		cin >> type;
		if (type == 1){
			int l, r, k;
			cin >> l >> r >> k;
			if (l - 1)
				change(1, 1, n + 1, l, k);
			if (r != n)
				change(1, 1, n + 1, r + 1, k);
			add(l, k);
			add(r + 1, k);
		}
		else{
			int l, r;
			cin >> l >> r;
			m = 0;
			if (l != r)
				get(1, 1, n + 1, l + 1, r + 1);
			ins(a[l] ^ get_fen(l));
			cout << (1 << m) << '\n';
		}
	}
}