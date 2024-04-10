#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;

int a[maxn], pos[maxn], fen[maxn];
ll f[maxn];

ll seg[2][4 * maxn], lazy[2][4 * maxn];
int act[2][4 * maxn];

void shift(int, int, int, bool);

ll get(int id, int L, int R, int l, int r, bool w){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[w][id];
	shift(id, L, R, w);
	int mid = (L + R) >> 1;
	return get(2 * id + 0, L, mid, l, r, w) + get(2 * id + 1, mid, R, l, r, w);
}

void chng(int id, int L, int R, int idx, bool w){
	if (idx < L or R <= idx)
		return;
	act[w][id] --;
	if (L + 1 == R){
		seg[w][id] = 0;
		return;
	}
	shift(id, L, R, w);
	int mid = (L + R) >> 1;
	chng(2 * id + 0, L, mid, idx, w);
	chng(2 * id + 1, mid, R, idx, w);
	seg[w][id] = seg[w][2 * id + 0] + seg[w][2 * id + 1];
}

void add(int id, int L, int R, int l, int r, int val, bool w){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[w][id] += 1ll * act[w][id] * val;
		lazy[w][id] += val;
		return;
	}
	shift(id, L, R, w);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val, w);
	add(2 * id + 1, mid, R, l, r, val, w);
	seg[w][id] = seg[w][2 * id + 0] + seg[w][2 * id + 1];
}

void shift(int id, int L, int R, bool w){
	if (lazy[w][id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, lazy[w][id], w);
	add(2 * id + 1, mid, R, mid, R, lazy[w][id], w);
	lazy[w][id] = 0;
}

void build(int id, int L, int R){
	act[0][id] = act[1][id] = R - L;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
}

int get(int i){
	int ret = 0;
	for (; i; i -= i & -i)
		ret += fen[i];
	return ret;
}

void add(int i, int x){
	for (; i < maxn; i += i & -i)
		fen[i] += x;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	build(1, 1, n + 1);
	ll inv = 0;
	for (int i = 1; i <= n; i++){ // 0 : right and 1 : left
		inv += (i - 1) - get(pos[i]);
		add(pos[i], 1);
		add(1, 1, n + 1, 1, pos[i] + 1, +1, 0);
		add(1, 1, n + 1, pos[i], n + 1, +1, 1);
		chng(1, 1, n + 1, pos[i], 0);
		chng(1, 1, n + 1, pos[i], 1);
		int idx = 0;
		int now = (i - 1) / 2;
		for (int i = 17; i >= 0; i--){
			if (idx + (1 << i) < maxn and fen[idx + (1 << i)] <= now){
				idx += (1 << i);
				now -= fen[idx];
			}
		}
		idx ++;
		cout << get(1, 1, n + 1, 1, idx + 1, 1) + get(1, 1, n + 1, idx, n + 1, 0) + inv << " ";
	}
	cout << endl;
}