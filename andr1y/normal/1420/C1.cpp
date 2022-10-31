#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll t[4*N][2][2]; // v, starts plus, minus, ends even odd;
ll a[N];
void build(ll v, ll tl, ll tr){
    if(tl==tr){
        t[v][0][0] = 0;
        t[v][0][1] = a[tl];
        t[v][1][0] = 0;
        t[v][1][1] = -a[tl];
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
    t[v][0][0] = max(t[v+v][0][0]+t[v+v+1][0][0], t[v+v][0][1]+t[v+v+1][1][1]);
    t[v][0][1] = max(t[v+v][0][0]+t[v+v+1][0][1], t[v+v][0][1]+t[v+v+1][1][0]);
    t[v][1][0] = max(t[v+v][1][0]+t[v+v+1][1][0], t[v+v][1][1]+t[v+v+1][0][1]);
    t[v][1][1] = max(t[v+v][1][0]+t[v+v+1][1][1], t[v+v][1][1]+t[v+v+1][0][0]);
}
void upd(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl==tr){
        t[v][0][0] = 0;
        t[v][0][1] = val;
        t[v][1][0] = 0;
        t[v][1][1] = -val;
    }
    ll tm = (tl+tr)>>1;
    if(pos<=tm) upd(v+v, tl, tm, pos, val);
    else upd(v+v+1, tm+1, tr, pos, val);
    t[v][0][0] = max(t[v+v][0][0]+t[v+v+1][0][0], t[v+v][0][1]+t[v+v+1][1][1]);
    t[v][0][1] = max(t[v+v][0][0]+t[v+v+1][0][1], t[v+v][0][1]+t[v+v+1][1][0]);
    t[v][1][0] = max(t[v+v][1][0]+t[v+v+1][1][0], t[v+v][1][1]+t[v+v+1][0][1]);
    t[v][1][1] = max(t[v+v][1][0]+t[v+v+1][1][1], t[v+v][1][1]+t[v+v+1][0][0]);
}
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, q2;
        cin >> n >> q2;
        for(ll i = 1;i<=n;i++) cin >> a[i];
        build(1, 1, n);
        cout<<max(t[1][0][0], t[1][0][1])<<'\n';
        while(q2--){
            ll l, r;
            cin >> l >> r;
            upd(1, 1, n, l, a[r]);
            upd(1, 1, n, r, a[l]);
            swap(a[l], a[r]);
            cout<<max(t[1][0][0], t[1][0][1])<<'\n';
        }
    }
}