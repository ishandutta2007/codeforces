/*
 _  _    _  _  ____  _  _  ____    _  _  ____  ____    ____  ____   __  ____   __   ____  _  _ 
( \/ )  ( \/ )(  __)/ )( \/ _  )  / )( \(  __)(_  _)  /    \(  _ \ /  \(  __) /  \ (  __)( \/ )
 )  /   / \/ \ ) _) ) __ (\    \  ) __ ( ) _)   )(    ) /\ ( ) __/(  O )) _ \/ /\ \ ) _) / \/ \
(__/    \_)(_/(____)\_)(_/(_/__/  \_)(_/(____) (__)   \_)(_/(__)   \__/(____/\_)(_/(____)\_)(_/
 __ _  ____   __   _  _  ____    _  _   __  ____  _ u_    ____   __   _ _   __ _  _ __         
(  / )(  _ \ /  \ ( \/ )(  __)  ( \/ ) /  \(  __)/ )  )  (  __) / _\ ( ) ))(  / )/ )  )        
 )  (  ) __/(  O )/ \/ \ ) _)   / \/ \(  O )) _) \    \   ) _ \/    \/( ( \ )  ( \    \        
(__\_)(__)   \__/ \_)(_/(____)  \_)(_/ \__/(____)(__(_/  (____/\_/\_/\____/(__\_)(__(_/        
  __   __    __    __       ____                                                               
 /  \ /  \  /  \  /  \  ___(__  )                                                              
(_/ /(  0 )(  0 )(  0 )(___) / /                                                               
 (__) \__/  \__/  \__/      (_/                                                                
 ____    _  _  _  _  ____  ____    ____  ____   __    ___  ____  _ __                          
/ _  )  ( \/ )( \/ )(  __)(  _ \  /    \(  _ \ /  \  / __)(_  _)/ )  )                         
\    \   )  / / \/ \ ) _)  ) __/  ) /\ ( ) __/(  O )( (__   )(  \    \ _  _  _                 
(_/__/  (__/  \_)(_/(____)(__)    \_)(_/(__)   \__/  \___) (__) (__(_/(_)(_)(_)                

(c) 255.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;

ll a[N], sa[N], t[4*N], w[4*N];

void build(ll v, ll tl, ll tr){
    w[v] = 0;
    if(tl+1==tr){
        t[v] = sa[tl];
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v+v+1, tl, tm);
    build(v+v+2, tm, tr);
    t[v] = min(t[v+v+1], t[v+v+2]);
}
void push(ll v){
    if(w[v]){
        t[v+v+1] += w[v];
        t[v+v+2] += w[v];
        w[v+v+1] += w[v];
        w[v+v+2] += w[v];
        w[v]=0;
    }
}
void upd(ll v, ll tl, ll tr, ll ql, ll qr, ll qv){
    if(tl>=ql&&tr<=qr){
        t[v]+=qv;
        w[v]+=qv;
        return;
    }
    ll tm = (tl+tr)>>1;
    push(v);
    if(tl < qr && ql < tm) upd(v+v+1, tl, tm, ql, qr, qv);
    if(tm < qr && ql < tr) upd(v+v+2, tm, tr, ql, qr, qv);
    t[v] = min(t[v+v+1], t[v+v+2]);
}

vector<ll> b[N];
ll sb[N], n, cb[N];

ll ffh(ll s, ll k){
    ll l = -1, r = n;
    while(r-l>1){
        ll m = (l+r)>>1;
        if(a[m] * k >= s) r=m;
        else l=m;
    }
    return r;
}

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            sa[i] = n-i;
        }
        sa[n]=0;
        sort(a, a+n);
        a[n]=inf;
        build(0, 0, n+1);
        for(ll i = 0;i<m;i++){
            b[i].clear();
            ll sz;
            cin >> sz;
            b[i].resize(sz);
            sb[i]=0;
            for(ll j = 0;j<sz;j++){
                cin >> b[i][j];
                sb[i]+=b[i][j];
            }
            cb[i] = ffh(sb[i], sz);
            upd(0, 0, n+1, 0, cb[i]+1, -1);
        }
        string res="";
        for(ll i = 0;i<m;i++){
            for(auto &j : b[i]){
                upd(0, 0, n+1, 0, cb[i]+1, 1);
                ll x = ffh(sb[i]-j, b[i].size()-1);
                upd(0, 0, n+1, 0, x+1, -1);
                if(t[0]>=0) res.push_back('1');
                else res.push_back('0');
                upd(0, 0, n+1, 0, x+1, 1);
                upd(0, 0, n+1, 0, cb[i]+1, -1);
            }
        }
        cout<<res<<'\n';
    }
}