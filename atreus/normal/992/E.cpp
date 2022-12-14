/**
 *    author:  Atreus
 *    created: 21.01.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

int n;
int mxm[4 * maxn];

int get(int id, int L, int R, int l, int r, int x){
	if (l >= r)
		return -1;
	if (L == l and R == r){
		if (mxm[id] < x)
			return -1;
		if (L + 1 == R)
			return L;
		int mid = (L + R) >> 1;
		if (mxm[2 * id + 0] >= x)
			return get(2 * id + 0, L, mid, L, mid, x);
		return get(2 * id + 1, mid, R, mid, R, x);
	}
	int mid = (L + R) >> 1;
	int k = get(2 * id + 0, L, mid, l, min(mid, r), x);
	if (k != -1)
		return k;
	return get(2 * id + 1, mid, R, max(l, mid), r, x);
}

void change(int id, int L, int R, int idx, int x){
	if (L + 1 == R){
		mxm[id] = x;
		return;
	}
	int mid = (L + R) >> 1;
	if (idx < mid)
		change(2 * id + 0, L, mid, idx, x);
	else
		change(2 * id + 1, mid, R, idx, x);
	mxm[id] = max(mxm[2 * id + 0], mxm[2 * id + 1]);
}

ll fen[maxn];

void add(int x, int val){
	for (; x <= n; x += x & -x)
		fen[x] += val;
}

ll get(int x){
	ll ret = 0;
	for (; x; x -= x & -x)
		ret += fen[x];
	return ret;
}

ll get(int L, int R){
	return get(R) - get(L - 1);
}

int a[maxn];

int solve(){
	int now = 1;
	while (now < n){
		ll x = get(1, now - 1);
		if (a[now] == x)
			return now;
		x += a[now];
		if (x > int(1e9))
			return -1;
		now = get(1, 1, n + 1, now + 1, n + 1, x);
		if (now == -1)
			return now;
	}
	if (get(1, n - 1) == a[n])
		return n;
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		add(i, a[i]);
		change(1, 1, n + 1, i, a[i]);
	}
	for (int i = 1; i <= q; i++){
		int idx, x;
		cin >> idx >> x;
		add(idx, x - a[idx]);
		a[idx] = x;
		change(1, 1, n + 1, idx, a[idx]);
		cout << solve() << '\n';
	}
}