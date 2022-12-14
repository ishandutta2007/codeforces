#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const int maxn = 1e5 + 10;
const int maxl = 40;

int newint = 1;

int k;

int seg[maxn * maxl], lc[maxn * maxl], rc[maxn * maxl];

int get(int id, int L, int R, int l, int r){
	if (L == l and R == r){
		if (seg[id] <= k){
			 k -= seg[id];
			 return -1;
		}
		if (L + 1 == R){
			k -= seg[id];
			return L;
		}
		int mid = (L + R) >> 1;
		if (seg[lc[id]] > k)
			return get(lc[id], L, mid, l, mid);
		k -= seg[lc[id]];
		return get(rc[id], mid, R, mid, r);
	}
	int mid = (L + R) >> 1;
	if (l < mid){
		int ret = get(lc[id], L, mid, l, min(mid, r));
		if (k < 0)
			return ret;
	}
	return get(rc[id], mid, R, max(l, mid), r);
}

int add(int id, int L, int R, int idx, int val){
	int node = newint ++;
	seg[node] = seg[id] + val;
	if (L + 1 == R)
		return node;
	int mid = (L + R) >> 1;
	lc[node] = lc[id], rc[node] = rc[id];
	if (idx < mid)
		lc[node] = add(lc[id], L, mid, idx, val);
	else
		rc[node] = add(rc[id], mid, R, idx, val);
	return node;
}

int a[maxn], last[maxn], root[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	memset(last, -1, sizeof last);
	for (int i = n - 1; i >= 0; i--){
		root[i] = root[i + 1];
		if (last[a[i]] != -1)
			root[i] = add(root[i], 0, n, last[a[i]], -1);
		root[i] = add(root[i], 0, n, i, +1);
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		int l = 0, cnt = 0;
		while (l < n){
			cnt ++;
			k = i;
			l = get(root[l], 0, n, l, n);
			if (k >= 0)
				break;
		}
		cout << cnt << " ";
	}
	cout << endl;
}