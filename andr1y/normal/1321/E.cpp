#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 1e6+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
pll a[200228], b[200228];
ll mnd[N], m2[N];
ll t[4*N], w[4*N];
bool e[4*N];
ll xx[N], x2[N];
ll tls[4*N], trs[N*4];
void push(ll v){
    if(!e[v]){
        w[v+v] += w[v];
        t[v+v] += w[v];
        w[v+v+1] += w[v];
        t[v+v+1] += w[v];
    }
    w[v] = 0;
}
void build(ll v, ll tl, ll tr){
    tls[v] = tl, trs[v] = tr;
    if(tl == tr){
        t[v] = x2[tl];
        e[v] = 1;
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
    t[v] = max(t[v+v], t[v+v+1]);
}
void add(ll v, ll tl, ll tr, ll l, ll r, ll z){
    push(v);
    if(tl >= l && tr <= r){
        t[v] += z;
        w[v]+=z;
        return;
    }
    ll tm = (tl+tr)>>1;
    if(tm >= l && tl <= r) add(v+v, tl, tm, l, r, z);
    if(tr >= l && tm+1<=r) add(v+v+1, tm+1, tr, l, r, z);
    t[v] = max(t[v+v], t[v+v+1]);
}
pair<ll, pll> me[200228];
python solve(){
	FAST;
    ll n, m, p;
    cin >> n >> m >> p;
    ll mai = inf, mbi = inf;
    for(ll i = 0;i<N;i++) mnd[i] = inf, m2[i] = inf;
    for(ll i = 0;i<n;i++){
        cin >> a[i].x >> a[i].y;
         m2[a[i].x] = min(m2[a[i].x], a[i].y);
         mai = min(mai, a[i].y);
    }
    for(ll i =N-2;i>=0;i--) m2[i] = min(m2[i], m2[i+1]);
    for(ll i = 0;i<m;i++){
        cin >> b[i].x >> b[i].y;
        mnd[b[i].x] = min(mnd[b[i].x], b[i].y);
        mbi = min(mbi, b[i].y);
    }
    mnd[0] = 0;
    for(ll i =N-2;i>0;i--) mnd[i] = min(mnd[i], mnd[i+1]);
    for(ll i = 0;i<N-1;i++){
        if(mnd[i] == mnd[i+1]) continue;
        else{
            xx[i+1] += mnd[i];
            xx[i+1] -= mnd[i+1];
        }
    }
    for(ll i = 1;i<N;i++) x2[i] = x2[i-1]+xx[i];
    for(ll i =0;i<p;i++){
        cin >> me[i].x >> me[i].y.x >> me[i].y.y;
    }
    sort(me, me+p, [](pair<ll, pll> a, pair<ll, pll> b){
        return (a.x == b.x ? a.y.x < b.y.x : a.x < b.x);
    });
    build(1, 1, N-1);
    ll mv = -inf;
    for(ll i = 0;i<p;i++){
        while(i+1 < p && me[i+1].x == me[i].x){
                add(1, 1, N-1, me[i].y.x+1, N-1, me[i].y.y);
        ++i;
        }
        add(1, 1, N-1, me[i].y.x+1, N-1, me[i].y.y);
        mv = max(mv, t[1]-m2[me[i].x+1]);
    }
    if(mv != -inf) cout << mv << '\n';
    else cout << -(mai+mbi) << '\n';
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}