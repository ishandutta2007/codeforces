/**
 *    author:  Atreus
 *    created: 21.01.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int seg[4 * maxn], laz[4 * maxn];

void propagate(int, int, int);

int get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	propagate(id, L, R);
	int mid = (L + R) >> 1, ret = 0;
	if (mid > l)
		ret = max(ret, get(2 * id + 0, L, mid, l, min(mid, r)));
	if (mid < r)
		ret = max(ret, get(2 * id + 1, mid, R, max(l, mid), r));
	return ret;
}

void change(int id, int L, int R, int l, int r, int x){
	if (L == l and R == r){
		seg[id] += x;
		laz[id] += x;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change(2 * id + 0, L, mid, l, min(mid, r), x);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, x);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (laz[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, laz[id]);
	change(2 * id + 1, mid, R, mid, R, laz[id]);
	laz[id] = 0;
}

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	a[0] = -1;
	for (int i = 0; i < n; i++){
		int p, t;
		cin >> p >> t;
		if (t == 0){
			change(1, 1, n + 1, 1, p + 1, -1);
		}
		else{
			int x;
			cin >> x;
			a[p] = x;
			change(1, 1, n + 1, 1, p + 1, +1);
		}
		int lo = 0, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (get(1, 1, n + 1, mid, n + 1) >= 1)
				lo = mid;
			else
				hi = mid;
		}
		cout << a[lo] << '\n';
	}
}