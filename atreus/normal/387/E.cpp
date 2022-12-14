/**
 *    author:  Atreus
 *    created: 17.01.2019 22:32:36
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;
const int inf = 1e6 + 1;

struct node{
	int idx;
	int sum;
};

node seg[4 * maxn];

int n, a[maxn];
bool mark[maxn];

node merge(node fi, node se){
	node ret;
	if (a[fi.idx] < a[se.idx])
		ret.idx = fi.idx;
	else
		ret.idx = se.idx;
	ret.sum = fi.sum + se.sum;
	return ret;
}

node get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (mid >= r)
		return get(2 * id + 0, L, mid, l, r);
	if (mid <= l)
		return get(2 * id + 1, mid, R, l, r);
	return merge(get(2 * id + 0, L, mid, l, mid), get(2 * id + 1, mid, R, mid, r));
}

void change(int id, int L, int R, int idx){
	if (L + 1 == R){
		seg[id].sum --;
		a[L] = inf;
		return;
	}
	int mid = (L + R) >> 1;
	if (mid > idx)
		change(2 * id + 0, L, mid, idx);
	else
		change(2 * id + 1, mid, R, idx);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

void build(int id, int L, int R){
	seg[id].sum = R - L;
	if (L + 1 == R){
		seg[id].idx = L;
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

ll answer = 0;

void convert(int L, int R){
	if (L >= R)
		return;
	node x = get(1, 1, n + 1, L, R);
	if (x.sum == 0)
		return;
	if (mark[a[x.idx]]){
		convert(L, x.idx);
		convert(x.idx + 1, R);
		return;
	}
	answer += x.sum;
	change(1, 1, n + 1, x.idx);
	convert(L, R);
}

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		mark[x] = 1;
	}
	build(1, 1, n + 1);
	convert(1, n + 1);
	cout << answer << endl;
}