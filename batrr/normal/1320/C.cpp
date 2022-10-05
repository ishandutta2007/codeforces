#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 1000100;
 
int n, m, k;
ll a[N], b[N], t[N << 2], u[N << 2];
vector< pii > c[N];
void upd(int v, int tl, int tr, int l, int r, ll x){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		u[v] += x;
		t[v] += x;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r, x);
	upd(v << 1 | 1, tm + 1, tr, l, r, x);
	t[v] = max(t[v << 1], t[v << 1 | 1]) + u[v];
}
int main()
{
	for(int i = 0; i < N; i++)
		a[i] = b[i] = 1e18;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		a[x] = min(a[x], (ll)y);
	}
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		b[x] = min(b[x], (ll)y);
	}
	for(int i = N - 2; i >= 0; i--){     
		a[i] = min(a[i], a[i + 1]);
    	b[i] = min(b[i], b[i + 1]);
	}
	for(int i = 1; i <= k; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x++, y++;
		c[x].pb({y, z});		
	}
	ll ans = -1e18;
	for(int i = 0; i < N; i++)
		upd(1, 0, N - 1, i, i, -b[i]);
	for(int i = 0; i < N; i++){
		for(auto it : c[i])
			upd(1, 0, N - 1, it.f, N - 1, it.s);
		ans = max(ans, t[1] - a[i]);
	}
	printf("%lld", ans);
}