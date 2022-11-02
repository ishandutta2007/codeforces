#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
struct node{
	ll a1, a2, a3, a4, sum;
};
node t[400400];
ll d[400400];
ll a[400400];
int n;
node merge(node a, node b){
	node c;
	c.a1 = max(a.a1, b.a1);
	c.a2 = max(a.a2, b.a2);
	c.a3 = max(a.a3, b.a3);
	c.a4 = max(a.a4, b.a4);
	c.sum = a.sum + b.sum;
	return c;
}
void upd(int v, int tl, int tr, int pos){
	if(tl == tr){
		ll C = abs(d[tl]) + abs(d[tl-1]);
		t[v].a1 = d[tl] + d[tl-1] - C;
		t[v].a2 = d[tl] - d[tl-1] - C;
		t[v].a3 = -d[tl] + d[tl-1] - C;
		t[v].a4 = -d[tl] - d[tl-1] - C;
		t[v].sum = abs(d[tl]);
		return;
	}
	int mid = (tl + tr)>>1;
	if(mid >= pos) upd(v * 2, tl, mid, pos);
	else upd(v * 2+1, mid+1, tr, pos);
	t[v] = merge(t[v*2], t[v*2+1]);
}

node get(int v, int tl, int tr, int l, int r){
	if(l <= tl &&tr <= r) return t[v];
	int mid = (tl+tr)>>1;
	if(r <= mid) return get(v * 2, tl, mid, l, r);
	if(mid < l) return get(v*2+1, mid+1, tr, l, r);
	return merge(get(v * 2, tl, mid, l, r), get(v*2+1, mid+1, tr, l, r));
}

void build(int v, int tl, int tr){
	if(tl==tr){
		ll C = abs(d[tl]) + abs(d[tl-1]);
		t[v].a1 = d[tl] + d[tl-1] - C;
		t[v].a2 = d[tl] - d[tl-1] - C;
		t[v].a3 = -d[tl] + d[tl-1] - C;
		t[v].a4 = -d[tl] - d[tl-1] - C;
		t[v].sum = abs(d[tl]);
		return;
	}
	int mid = (tl + tr)>>1;
	build(v*2, tl, mid);
	build(v * 2 + 1, mid+1, tr);
	t[v] = merge(t[v * 2], t[v*2+1]);
}
void solve(){
	scanf("%d", &n);
	for(int i = 1, x; i <= n; i++){
		scanf("%d", &x);
		a[i] = x;
	}
	ll sum = 0;
	for(int i = 1; i < n; i++){
		d[i] = a[i] - a[i+1];
	}
	build(1, 1, n-1);
	int q;
	scanf("%d", &q);
	for(int i = 0, ty, l, r, x; i < q; i++){
		scanf("%d%d%d%d", &ty, &l, &r, &x);
		if(ty == 2){
			d[l-1] -= x;
			d[r] += x;
			upd(1, 1, n-1, l-1);
			upd(1, 1, n-1, l);
			upd(1, 1, n-1, r);
			if(r + 1 < n) upd(1, 1, n-1, r+1);
		}else {
			node G = get(1, 1, n-1, l, r);
			ll sum = t[1].sum;
			ll ans = max(G.a1, max(max(G.a2 + 2ll * x, G.a3 - 2ll * x), G.a4)) + sum;
			printf("%lld\n", ans);
		}
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}