#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;
const int maxl = 19;

int a[maxn], p[maxn], sum[maxn], r[maxn];
int seg[maxn*maxl], lc[maxn*maxl], rc[maxn*maxl], newint = 1;

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return 0;
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return get(lc[id], L, mid, l, r) + get(rc[id], mid, R, l, r);
}

int add(int id, int L, int R, int idx){
	if (idx < L or R <= idx)
		return id;
	int me = newint ++;
	seg[me] = seg[id] + 1;
	if (L + 1 == R)
		return me;
	int mid = (L + R) >> 1;
	lc[me] = add(lc[id], L, mid, idx);
	rc[me] = add(rc[id], mid, R, idx);
	return me;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		p[i] = i;
	}
	sort(p+1, p+n+1, [](int x, int y){
		return make_pair(a[x], x) < make_pair(a[y], y);		
	});
	for (int i = 1; i <= n; i++)
		r[p[i]] = add(r[p[i-1]], 1, n+1, p[i]);
	for (int v = 1; v <= n-1; v++){
		for (int k = 1; k <= n-1; k++){
			if (k*(v-1)+2 > n)
				break;
			int ll = k*(v-1)+2, rr = k*v+2;
			sum[k] += get(r[v], 1, n+1, ll, rr);
		}
	}
	for (int i = 1; i <= n-1; i++)
		cout << sum[i] << " \n"[i == n-1];
}