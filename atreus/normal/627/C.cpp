/**
 *    author:  Atreus
 *    created: 15.01.2019 17:29:54     
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxm = 2e5 + 10;

struct station{
	ll position;
	ll cost;
	station(){
	}
	station(int pos, int cos){
		position = pos;
		cost = cos;
	}
	bool operator < (const station &other) const{
		return position < other.position;
	}
} st[maxm];

ll n, m;

int seg[4 * maxm];

int merge(int fi, int se){
	if (st[fi].cost <= st[se].cost)
		return fi;
	return se;
}

int get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (mid >= r)
		return get(2 * id + 0, L, mid, l, r);
	if (mid <= l)
		return get(2 * id + 1, mid, R, l, r);
	return merge(get(2 * id + 0, L, mid, l, mid), get(2 * id + 1, mid, R, mid, r));
}

void build(int id, int L, int R){
	if (L + 1 == R){
		seg[id] = L;
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

ll dp(int from, int to){
	if (st[to].position - st[from].position <= n)
		return 1ll * (st[to].position - st[from].position) * st[from].cost;
	if (from + 1 == to){
		cout << -1 << endl;
		exit(0);
	}
	int idx = get(1, 0, m, from + 1, to);
	if (st[idx].position - st[from].position >= n)
		return dp(from, idx) + dp(idx, to);
	ll now = n - (st[idx].position - st[from].position);
	if (st[to].position - st[idx].position <= n)
		return 1ll * n * st[from].cost + (st[to].position - st[from].position - n) * st[idx].cost;
	return 1ll * n * st[from].cost + dp(idx, to) - (n - (st[idx].position - st[from].position)) * st[idx].cost;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll d;
	cin >> d >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> st[i].position >> st[i].cost;
	st[m ++] = station(0, 0);
	st[m ++] = station(d, 0);
	sort(st, st + m);
	build(1, 0, m);
	cout << dp(0, m - 1) << endl;
}