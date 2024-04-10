#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 300000
#define INF 101111111111111
using namespace std;
ll mlog2(ll a){
	ll c = 0;
	while(a) a>>=1, c++;
	return c-1;
}
ll a[N];
pll t[3*N];
ll n;
pll cmin(pll a, pll b){
	return (a.x == b.x ? a : (a.x < b.x ? a : b));
}
void build(ll v, ll tl, ll tr){
	if(tl == tr) t[v].x = a[tl], t[v].y = tl;
	else{
		ll tm = (tl+tr)>>1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = cmin(t[v*2], t[v*2+1]);
	}
}
void update(ll v, ll val, bool f= true){
	if(f){
		t[v].x = val;
	}else{
		t[v] = cmin(t[v*2], t[v*2+1]);
	}
	if(v!=1) update(v/2, val, 0);
}
pll mmin(ll v, ll tl, ll tr, ll l, ll r){
	ll tm = (tl+tr)>>1;
	pll res = {INF, -1};
	if(l <= tl && r >= tr) return t[v];
	if(l <= tm && r >= tl) res = cmin(res, mmin(v*2, tl, tm, l, r));
	if(l <= tr && r >  tm) res = cmin(res, mmin(v*2+1, tm+1, tr, l, r));
	return res;
}
pll getmin(ll l, ll r){
	return mmin(1, 1, n, l, r);
}
int main(){
	FAST;
	cin >> n;
	ll l = mlog2(n);
	ll f = 0;
	for(ll i = 1;i<=n;i++) {cin >> a[i]; if(a[i] == -1) f = i, a[i] = INF;}
	if(f == n) cout << 0 << endl;
	else{
		build(1, 1, n);
		ll res = a[n];
		for(ll i = n>>1;i>=1;i>>=1){
			if(f < i){
				pll mp = getmin(i, n-1);
				update(n+mp.y-1, INF, 1);
				res+=mp.x;
			}
			else break;
		}
		cout << res << endl;
	}
}