#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 10;
const int maxl = 40;

pair<int, int> seg[maxn * maxl];
int lc[maxn * maxl], rc[maxn * maxl], pre[maxn], last[maxn], root[maxn], a[maxn];

int newint = 1, n;

pair<int, int> get(int id, int L, int R, int l, int r){
	if (L >= r or R <= l)
		return {n + 1, 0};
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return min(get(lc[id], L, mid, l, r), get(rc[id], mid, R, l, r));
}

int change(int id, int L, int R, int idx, int val){
	if (idx >= R or idx < L)
		return id;
	int me = newint ++;
	if (L + 1 == R){
		seg[me] = {val, L};
		return me;
	}
	int mid = (L + R) >> 1;
	lc[me] = change(lc[id], L, mid, idx, val);
	rc[me] = change(rc[id], mid, R, idx, val);
	seg[me] = min(seg[lc[me]], seg[rc[me]]);
	return me;
}

int main(){
	scanf("%d", &n);
	memset(last, -1, sizeof last);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	seg[0] = {n + 1, 0};
	for (int i = 1; i <= n; i++){
		root[i] = root[i - 1];
		if (pre[i] != -1)
			root[i] = change(root[i - 1], 1, n + 1, pre[i], n + 1);
		root[i] = change(root[i], 1, n + 1, i, pre[i]);
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int l, r;
		scanf("%d%d", &l, &r);
		auto it = get(root[r], 1, n + 1, l, r + 1);
		if (it.first < l)
			printf("%d\n", a[it.second]);
		else
			printf("0\n");
	}
}