#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


map <ll, vector <ll> > mp;

ll p[MAXN], p1[MAXN];

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)p[v] = val; else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
    }
}

void mod(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)p1[v] = val; else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)mod(v << 1, tl, tm, pos, val); else mod((v << 1) + 1, tm + 1, tr, pos, val);
        p1[v] = max(p1[v << 1], p1[(v << 1) + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return -1e18;
    if(tl == l && tr == r)return p[v];
    ll tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll get1(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return -1e18;
    if(tl == l && tr == r)return p1[v];
    ll tm = (tl + tr) >> 1;
    return max(get1(v << 1, tl, tm, l, min(r, tm)), get1((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for(int i = 0; i < MAXN; i++)p[i] = -1e18;
    for(int i = 0; i < MAXN; i++)p1[i] = -1e18;

    ll n, a;
    cin >> n >> a;

    vector <ll> d(n + 1), c(n + 1), val(n + 1);

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> d[i] >> c[i];
        val[i] = a - c[i];
        ans = max(ans, val[i]);
    }

    for(int i = 1; i < n; i++){
        mp[-sqr(d[i + 1] - d[i])].p_b(i);
    }

    set <ll> pos;

    vector <ll> pref(n + 10), pref1(n + 10);

    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + val[i];
    for(int i = n; i >= 1; i--)pref1[i] = pref1[i + 1] + val[i];

    for(int i = 1; i <= n; i++){
        modify(1, 1, n, i, pref[i]);
        mod(1, 1, n, i, pref1[i]);
    }

    //cout << "\n";

    for(auto i : mp){
        vector <ll> c;
        c = i.se;

        for(auto j : c){
            set <ll> :: iterator it;
            it = pos.upper_bound(j);
            ll le, ri;
            if(it == pos.end())ri = n; else ri = *it;
            it = pos.lower_bound(j);
            ll sc = i.fi;
            sc += max(get(1, 1, n, j + 1, ri) - pref[j - 1], 0ll);

            if(pos.empty() || it == pos.begin())le = 1; else{
                --it;
                le = *it + 1;
            }
            //cout << le << " : " << ri << "\n";
            sc += max(get1(1, 1, n, le, j) - pref1[j], 0ll);
            //cout << j << " " << sc << "\n";
            ans = max(ans, sc);
        }

        for(auto j : c){
            pos.insert(j);
        }

    }

    cout << ans << "\n";


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}