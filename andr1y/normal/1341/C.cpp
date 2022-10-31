//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], pof[N], t[4*N], pk[4*N], p[N], c[N];
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        t[v] = 1;
        pk[tl] = v;
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v+v, tl, tm);
    build(v+v+1, tm+1, tr);
    t[v] = 1;
}
void inc(ll v, ll val){
    t[v]+=val;
    v>>=1;
    while(v){
        t[v]=max(t[v+v], t[v+v+1]);
        v>>=1;
    }
}
ll _f(ll v){
    return v==p[v]?v:p[v]=_f(p[v]);
}
void _u(ll a, ll b){
    a=_f(a), b=_f(b);
    if(a==b) return;
    c[a] = max(c[a], c[b]);
    p[b] = a;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        c[0] = 1;
        c[n+1] = n+1;
        p[n+1] = n+1;
        a[n+1] = 0;
        p[0] = 0;
        for(ll i = 1;i<=n;i++){
            p[i] = i, c[i] = i;
            cin >> a[i];
            pof[a[i]] = i;
        }
        bool ok = 1;
        build(1, 1, n);
        for(ll i = 1;i<=n;i++){
            ll pos = pof[i];
            ll hb = t[pk[pos]];
            ll mxc = t[1];
            if(hb^mxc){
                ok = 0;
                break;
            }
            ll vk = c[_f(pos+1)];
            if(vk != n+1){
                inc(pk[vk], t[pk[pos]]);
            }
            inc(pk[pos], -t[pk[pos]]);
            if(pos>1&&a[pos-1]<a[pos]) _u(pos-1, pos);
            if(pos<=n&&a[pos+1]<a[pos]) _u(pos+1, pos);
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}