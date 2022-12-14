#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
ll N;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <pll> t[3 * MAXN], t1[3 * MAXN];

ll last[MAXN];

ll pr[3 * MAXN], root[MAXN];

pll Val;

bool bad(pll a, pll b, pll c) {
    return a.fi * (b.se - c.se) + b.fi * (c.se - a.se) + c.fi * (a.se - b.se) >= 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return;
    if(tl == l && tr == r){
        t[v].p_b(Val);
        return;
    }
    ll tm = (tl + tr) >> 1;
    modify(v << 1, tl, tm, l, min(r, tm));
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}


void build(ll v, ll tl, ll tr){

    map <ll, ll> mp;

    for(auto i : t[v]){
        if(mp.find(i.fi) == mp.end())mp[i.fi] = i.se;
        else mp[i.fi] = max(mp[i.fi], i.se);
    }


    for(auto i : mp){
        while(t1[v].size() > 1 && bad(t1[v][t1[v].size() - 2], t1[v][t1[v].size() - 1], i))t1[v].pop_back();
        t1[v].p_b(i);
    }


    mp.clear();

    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        pr[v << 1] = v;
        pr[(v << 1) + 1] = v;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
    }else root[tl] = v;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> t(n + 1);

    vector <pll> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> t[i];
        if(t[i] == 1){
            cin >> a[i].fi >> a[i].se;
            last[i] = n;
        }else if(t[i] == 2){
            cin >> a[i].fi;
            last[a[i].fi] = i - 1;
        }else{
            cin >> a[i].fi;
        }
    }

    for(int i = 1; i <= n; i++)if(t[i] == 1){
        Val = a[i];
        modify(1, 1, n, i, last[i]);
    }

    build(1, 1, n);

    for(int i = 1; i <= n; i++)if(t[i] == 3){
        ll q = a[i].fi;
        ll ans = -3e18;
        ll x = root[i];

        while(x){
            if(!t1[x].empty()){
                ll l = 0, r = t1[x].size() - 1;
                while(r - l > 3){
                    ll c = (l + r) >> 1;
                    if(t1[x][c].fi * q + t1[x][c].se < t1[x][c + 1].fi * q + t1[x][c + 1].se)l = c; else r = c;
                }
                for(int i = l; i <= r; i++)ans = max(ans, t1[x][i].fi * q + t1[x][i].se);
            }
            x = pr[x];
        }

        if(ans == -3e18)cout << "EMPTY SET\n"; else cout << ans << "\n";

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}