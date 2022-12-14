#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 2e5 + 10;

vector<int> events[maxn], rooks[maxn];
int seg[4 * maxn], lazy[4 * maxn];
bool ans[2 * maxn];
int x[maxn], y[maxn], xl[maxn], xr[maxn], yl[maxn], yr[maxn];

void propagate(int, int, int);

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return maxn;
	if (l <= L and R <= r)
		return seg[id];
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	return min(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void change(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] = val;
		lazy[id] = val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, l, r, val);
	change(2 * id + 1, mid, R, l, r, val);
	seg[id] = min(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (lazy[id] == -1)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id]);
	change(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = -1;
}

void findgoods(int n, int m, int k, int q){
	for (int i = 1; i <= n; i++){
		events[i].clear();
		rooks[i].clear();
	}
	for (int i = 0; i < q; i++)
		events[xr[i]].push_back(i);
	for (int i = 0; i < k; i++)
		rooks[x[i]].push_back(y[i]);
	memset(seg, -1, sizeof seg);
	memset(lazy, -1, sizeof lazy);
	for (int i = 1; i <= n; i++){
		for (auto j : rooks[i])
			change(1, 1, m + 1, j, j + 1, i);
		for (auto j : events[i]){
			int l = yl[j], r = yr[j], mnx = xl[j];
			int k = get(1, 1, m + 1, l, r + 1);
			if (k >= mnx)
				ans[j] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < q; i++)
		cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
	findgoods(n, m, k, q);
	for (int i = 0; i < k; i++)
		swap(x[i], y[i]);
	for (int i = 0; i < q; i++){
		swap(xl[i], yl[i]);
		swap(xr[i], yr[i]);
	}
	swap(n, m);
	findgoods(n, m, k, q);
	for (int i = 0; i < q; i++){
		if (ans[i])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}