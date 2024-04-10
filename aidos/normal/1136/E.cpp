#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = 2e5;
int a[maxn];
ll t[4*maxn];
ll tmax[4*maxn];
ll t2[4*maxn];
int k[maxn];
int n;
void build(int v, int l, int r) {
	if(l == r) {
		tmax[v] = a[l+1] - a[l] - k[l];
		t[v] = tmax[v] * (n-l);
		t2[v] = tmax[v];
	} else {
		int mid = (l + r)/2;
		build(v * 2, l, mid);
		build(v * 2+1, mid+1, r);
		t[v] = t[v*2] + t[v*2+1];
		tmax[v] = max(tmax[v*2], tmax[v*2+1]);
		t2[v] = t2[v*2] + t2[v*2+1];
	}
}
ll get(int v, int tl, int tr, int l, int r) {
	if(r < tl || tr < l) return 0;
	if(l <= tl && tr <= r) return t[v];
	int mid = (tl + tr)/2;
	return get(v*2, tl, mid, l, r) + get(v * 2 + 1, mid+1,tr, l, r);
}
ll get2(int v, int tl, int tr, int l, int r) {
	if(r < tl || tr < l) return 0;
	if(l <= tl && tr <= r) return t2[v];
	int mid = (tl + tr)/2;
	return get2(v*2, tl, mid, l, r) + get2(v * 2 + 1, mid+1,tr, l, r);
}
void upd(int v, int l, int r, int pos, ll val) {
	if(l == r) {
		t[v] += val * (n-l);
		tmax[v] += val;
		t2[v] = tmax[v];
	}
	else {
		int mid = (l + r)/2;
		if(mid >= pos) upd(v * 2, l, mid, pos, val);
		else upd(v*2+1, mid+1, r, pos, val);
		t[v] = t[v*2] + t[v*2+1];
		tmax[v] = max(tmax[v*2], tmax[v*2+1]);
		t2[v] = t2[v*2] + t2[v*2+1];
	}
}
void upd2(int v, int l, int r, int tl, int tr, ll &val) {
	if(tr < l || r < tl) return;
	if(t[v] == 0) return;
	if(val == 0) return;
	if(l == r) {
		ll cur = min(val, tmax[v]);
		t[v] -= cur * (n-l);
		tmax[v] -= cur;
		t2[v] = tmax[v];
		val -= cur;
	}
	else {
		int mid = (l + r)/2;
		upd2(v * 2, l, mid, tl, tr, val);
		upd2(v*2+1, mid+1, r, tl, tr, val);
		t[v] = t[v*2] + t[v*2+1];
		tmax[v] = max(tmax[v*2], tmax[v*2+1]);
		t2[v] = t2[v*2] + t2[v*2+1];
	}
}
ll pref[maxn];
ll pref2[maxn];
ll calc(int pos) {
	if(pos < 1) return 0;
	ll s = get(1, 1, n-1, 1, pos);
	ll s2 = get2(1, 1, n-1, 1, pos);
	s -= s2 * (n-pos-1);
	s += pref[pos];
	s -= pref2[pos] * (n-pos-1);
	return s;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; i++) {
		scanf("%d", &k[i]);
		pref[i] = pref[i-1]+k[i] * 1ll * (n-i);
		pref2[i] = pref2[i-1] + k[i];
	}
	ll x = a[1];
	build(1, 1, n-1);
	int q;
	scanf("%d", &q);

	char tmp[12];
	for(int i = 0; i < q; i++) {
		int l, r;
		scanf("%s%d%d", tmp, &l, &r);
		if(tmp[0] == 's') {
			ll s = calc(r-1) - calc(l-2);

			printf("%lld\n", x * (r-l+1) + s);
		} else {
			if(l < n) {
				upd(1, 1, n-1, l, -r);
				ll s = get2(1, 1, n-1, l, l);
				if(s < 0) {
					s *= -1;
					upd(1, 1, n-1, l, s);
					upd2(1, 1, n-1, l+1, n-1, s);
				}
			}
			if(l > 1) {
				upd(1, 1, n-1, l-1, r);
				ll s = get2(1, 1, n-1, l-1, l-1);
				if(s < 0) {
					s *= -1;
					upd(1, 1, n-1, l-1, s);
					upd2(1, 1, n-1, l, n-1, s);
				}
			}
			if(l == 1) x += r;
		}
		/*for(int t = 1; t <= n; t++) {
			ll s = calc(t-1) - calc(t-2);
			printf("%lld ", x * (1) + s);
		}
		cout << "\n";*/

	}
}