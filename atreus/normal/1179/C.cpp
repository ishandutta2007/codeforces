#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;
const int maxN = 1e6 + 10;

int a[maxn], b[maxn], seg[4 * maxN], laz[4 * maxN];

void propagate(int, int, int);

int get(int id, int L, int R){
	if (seg[id] <= 0)
		return -1;
	if (L + 1 == R)
		return L;
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	int k = get(2 * id + 1, mid, R);
	if (k != -1)
		return k;
	return get(2 * id + 0, L, mid);
}

void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] += val;
		laz[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (laz[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, laz[id]);
	add(2 * id + 1, mid, R, mid, R, laz[id]);
	laz[id] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	scanf("%d%d", &n, &m);
	int N = 1000 * 1000 + 1;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		add(1, 1, N, 1, a[i] + 1, +1);
	}
	for (int i = 1; i <= m; i++){
		scanf("%d", &b[i]);
		add(1, 1, N, 1, b[i] + 1, -1);
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++){
		int type, idx, val;
		scanf("%d%d%d", &type, &idx, &val);
		if (type == 1){
			add(1, 1, N, 1, a[idx] + 1, -1);
			a[idx] = val;
			add(1, 1, N, 1, a[idx] + 1, +1);
		}
		else{
			add(1, 1, N, 1, b[idx] + 1, +1);
			b[idx] = val;
			add(1, 1, N, 1, b[idx] + 1, -1);
		}
		if (seg[1] <= 0){
			printf("-1\n");
			continue;
		}
		printf("%d\n", get(1, 1, N));
	}
}