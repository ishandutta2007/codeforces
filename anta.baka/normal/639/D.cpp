#include <stdio.h>
#include <vector>
#include <algorithm>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
vector<pll> t;
vector<ll> tadd;
 
inline void tclear(int v, int vl, int vr) {
	tadd[v] = 0;
	if(vl == vr) {
		t[v] = mp(0, vl);
		return;
	}
	int vm = (vl + vr) >> 1;
	tclear(v*2+1, vl, vm);
	tclear(v*2+2, vm+1, vr);
	t[v] = max(t[v*2+1], t[v*2+2]);
}
 
inline void push(int v, int vl, int vr) {
	if(tadd[v] != 0) {
		if(vl != vr) {
			tadd[v*2+1] += tadd[v];
			tadd[v*2+2] += tadd[v];
		}
		t[v].first += tadd[v];
		tadd[v] = 0;
	}
}
 
inline void add(int v, int vl, int vr, int l, int r, ll val) {
	push(v, vl, vr);
	if(r < vl || vr < l)
		return;
	if(l <= vl && vr <= r) {
		tadd[v] += val;
		push(v, vl, vr);
		return;
	}
	int vm = (vl + vr) >> 1;
	add(v*2+1, vl, vm, l, r, val);
	add(v*2+2, vm+1, vr, l, r, val);
	t[v] = max(t[v*2+1], t[v*2+2]);
}
 
inline pll get(int v, int vl, int vr, int l, int r) {
	push(v, vl, vr);
	if(r < vl || vr < l)
		return mp(0, 0);
	if(l <= vl && vr <= r)
		return t[v];
	int vm = (vl + vr) >> 1;
	return max(get(v*2+1, vl, vm, l, r), get(v*2+2, vm+1, vr, l, r));
}

inline ll f(ll n, int mod) {
    int q = n % 5;
    if(q < 0)
        q = 5 + q;
    if(q <= mod)
        return n + mod - q;
    return n + 5 - q + mod;
}

int main() {
	int n, k;
	ll b, c;
	scanf("%d%d%I64d%I64d", &n, &k, &b, &c);
	b = min(b, 5 * c);
	vector<ll> a(n);
	for(int i = 0; i < n; i++)
	    scanf("%I64d", &a[i]);
	sort(all(a));
	t.resize(4 * k);
	tadd.resize(4 * k);
	tclear(0, 0, k-1);
	ll ans = 1e17;
	for(int i = 0; i < 5; i++) {
		ll sum = 0, prf = f(a[k-1], i);
		tclear(0, 0, k-1);
		for(int j = 0; j < k; j++) {
			ll plus = b * ((prf - a[j]) / 5) + c * ((prf - a[j]) % 5);
			add(0, 0, k-1, j, j, plus);
			sum += plus;
		}
		ans = min(ans, sum);
		for(int j = k; j < n; j++) {
			ll cf = f(a[j], i);
			add(0, 0, k-1, 0, k-1, b * ((cf - prf) / 5));
			sum += b * ((cf - prf) / 5) * k;
			pll bad = get(0, 0, k-1, 0, k-1);
			if(c * ((cf - a[j]) % 5) < bad.first) {
				add(0, 0, k-1, bad.second, bad.second, c * ((cf - a[j]) % 5) - bad.first);
				sum += c * ((cf - a[j]) % 5) - bad.first;
				ans = min(ans, sum);
			}
			prf = cf;
		}
	}
    printf("%I64d", ans);
}