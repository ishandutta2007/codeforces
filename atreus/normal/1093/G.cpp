#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 2e5 + 10;

int n, k;
int a[maxn][6];

struct node{
	int mxm[40];
	int mnm[40];
};

node seg[4 * maxn];

node merge(node fi, node se){
	node ret;
	for (int mask = 0; mask < (1 << k); mask++){
		ret.mxm[mask] = max(fi.mxm[mask], se.mxm[mask]);
		ret.mnm[mask] = min(fi.mnm[mask], se.mnm[mask]);
	}
	return ret;
}

node get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (r <= mid)
		return get(2 * id + 0, L, mid, l, r);
	if (l >= mid)
		return get(2 * id + 1, mid, R, l, r);
	return merge(get(2 * id + 0, L, mid, l, mid), get(2 * id + 1, mid, R, mid, r));
}

void change(int id, int L, int R, int idx){
	if (L + 1 == R){
		for (int mask = 0; mask < (1 << k); mask ++){
			int val = 0;
			for (int i = 0; i < k; i++){
				if (mask & (1 << i))
					val += a[idx][i];
				else
					val -= a[idx][i];
			}
			seg[id].mxm[mask] = seg[id].mnm[mask] = val;
		}
		return;
	}
	int mid = (L + R) >> 1;
	if (idx < mid)
		change(2 * id + 0, L, mid, idx);
	else
		change(2 * id + 1, mid, R, idx);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++)
			cin >> a[i][j];
		change(1, 0, n, i);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int type;
		cin >> type;
		if (type == 1){
			int idx;
			cin >> idx;
			idx --;
			for (int j = 0; j < k; j++)
				cin >> a[idx][j];
			change(1, 0, n, idx);
		}
		else{
			int l, r;
			cin >> l >> r;
			l --;
			node me = get(1, 0, n, l, r);
			int answer = 0;
			for (int mask = 0; mask < (1 << k); mask++)
				answer = max(answer, me.mxm[mask] - me.mnm[mask]);
			cout << answer << '\n';
		}
	}
}