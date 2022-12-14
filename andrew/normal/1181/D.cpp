#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ordered_set <ll> s;

vector <pll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;
    vector <pll> p(m + 1);

    for(int i = 1; i <= m; i++)p[i].se = i;
    ll old = n;
    while(n--){
        ll x;
        cin >> x;
        p[x].fi++;
    }

    sort(p.begin() + 1, p.end());

    vector <ll> pref(m + 1), answer(m + 1);

    answer[0] = 1e18;

    for(int i = 1; i <= m; i++){
        pref[i] = pref[i - 1] + p[i].fi;
        answer[i] = min(answer[i - 1], p[i].se);
    }

    ll con = 5e18;
    ll Q = q;

    vector <ll> ans(Q + 1);
    ll step = 0;

    while(q--){
        step++;
        ll l = 0, r = 1e18 + 5;
        ll k;
        cin >> k;
        k -= old;
        while(l < r){
            ll c = (l + r) >> 1;
            pll kek = {c, 1e18};
            ll pos = upper_bound(all(p), kek) - p.begin();
            pos--;
            ll ku;
            if(c == 0)ku = 0; else
            if(con / c < pos)ku = con; else ku = c * pos;
            ku -= pref[pos];
            ku += pos;
            if(ku < k)l = c + 1; else r = c;
        }

        if(l){
            pll kek = {l, 1e18};
            ll pos = upper_bound(all(p), kek) - p.begin();
            pos--;
            ll ku;
            if(con / l < pos)ku = con; else ku = l * pos;
            ku -= pref[pos];
            k -= ku;
        }
        pll kek = {l, 1e18};
        ll pos = upper_bound(all(p), kek) - p.begin();
        pos--;
        v[pos].p_b({step, k});
    }

    for(int i = 1; i <= m; i++){
        s.insert(p[i].se);
        for(auto j : v[i]){
            ans[j.fi] = *s.find_by_order(j.se - 1);
        }
    }

    for(int i = 1; i <= Q; i++)cout << ans[i] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}