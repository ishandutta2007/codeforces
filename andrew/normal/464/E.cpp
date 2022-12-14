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
#define f(x) (1ll << x)
#define hash sosat

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

const ll N = 1e5 + 10000;

const ll mod = 1e9 + 7;

ll p[N + 30], pref[N + 30];

struct node{
    ll kol, val, hash;
    node *l, *r, *old;
    node(node *od) : hash(0), kol(0), val(-1), l(r=nullptr), old(od){}
};

void build(node *v, ll tl, ll tr){
    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        v -> l = new node(nullptr);
        v -> r = new node(nullptr);
        build(v -> l, tl, tm);
        build(v -> r, tm + 1, tr);
    }
}

ll get_S(ll l, ll r){
    ll val = pref[r];
    if(l)val -= pref[l - 1];
    if(val < 0)val += mod;
    return val;
}


node *kek;

node *le(node *v){
    if(v == nullptr)return nullptr;
    return v -> l;
}

node *ri(node *v){
    if(v == nullptr)return nullptr;
    return v -> r;
}

void push(node * v, ll tl, ll tr){
    if(v -> val == -1)return;
    ll tm = (tl + tr) >> 1;

    kek = v -> l;
    node *tk = new node(kek);
    v -> l = tk;
    kek = tk;
    kek -> kol = (tm - tl + 1) * v -> val;
    kek -> hash = (get_S(tl, tm) * v -> val) % mod;
    kek -> val = v -> val;
    kek -> l = le(kek -> old);
    kek -> r = ri(kek -> old);

    kek = v -> r;
    tk = new node(kek);
    v -> r = tk;
    kek = tk;
    kek -> kol = (tr - tm) * v -> val;
    kek -> hash = (get_S(tm + 1, tr) * v -> val) % mod;
    kek -> val = v -> val;
    kek -> l = le(kek -> old);
    kek -> r = ri(kek -> old);

    v -> val = -1;

    return;

}



void inst(node *kek){
    if(kek -> old == nullptr)return;
    kek -> hash = (kek -> old) -> hash;
    kek -> kol = (kek -> old) -> kol;
    kek -> val = (kek -> old) -> val;
    kek -> l = le(kek -> old);
    kek -> r = ri(kek -> old);
}

void modify(node *v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        v -> hash = get_S(tl, tr) * val;
        v -> hash %= mod;
        v -> kol = (tr - tl + 1) * val;
        v -> val = val;
        return;
    }

    ll tm = (tl + tr) >> 1;

    push(v, tl, tr);

    if(l <= min(r, tm)){
        node *tk = new node(v -> l);
        tk -> l = le(v -> l);
        tk -> r = ri(v -> l);
        tk -> val = (v -> l) -> val;
        v -> l = tk;
        modify(v -> l, tl, tm, l, min(r, tm), val);
    }

    if(max(l, tm + 1) <= r){
        node *tk = new node(v -> r);
        tk -> l = le(v -> r);
        tk -> r = ri(v -> r);
        tk -> val = (v -> r) -> val;
        v -> r = tk;
        modify(v -> r, tm + 1, tr, max(l, tm + 1), r, val);
    }

    v -> kol = (v -> l) -> kol + (v -> r) -> kol;
    v -> hash = (v -> l) -> hash + (v -> r) -> hash;
    if(v -> hash > mod)v -> hash %= mod;

}

vector <pll> v[MAXN];

ll poz = 1e18, pr[MAXN];

node *dp[MAXN];
bool f[MAXN];

void dfs(node *v, ll tl, ll tr){
    if(poz != 1e18)return;
    if(v -> kol == tr - tl + 1)return;
    if(tl == tr){
        poz = tl;
        return;
    }
    ll tm = (tl + tr) >> 1;

    push(v, tl, tr);

    dfs(v -> l, tl, tm);
    dfs(v -> r, tm + 1, tr);
}

void find(node *v, ll tl, ll tr, ll l, ll r){
    if(poz != 1e18)return;
    if(l > r)return;
    if(tl == l && tr == r){
        dfs(v, tl, tr);
        return;
    }
    ll tm = (tl + tr) >> 1;

    push(v, tl, tr);

    find(v -> l, tl, tm, l, min(r, tm));
    find(v -> r, tm + 1, tr, max(l, tm + 1), r);

}

bool pos(node *a, node *b, ll tl, ll tr){
    if(tl == tr){
        //if(a -> kol == b -> kol)cout << tl << " " << endl;
        if(a -> kol > b -> kol)return 1;
        return 0;
    }
    ll tm = (tl + tr) >> 1;
    push(a, tl, tr);
    push(b, tl, tr);

    if((a -> r) -> hash != (b -> r) -> hash)return pos(a -> r, b -> r, tm + 1, tr);
    return pos(a -> l, b -> l, tl, tm);

}

struct for_set{
    node *v;
    ll id;
};


inline bool operator == (for_set a, for_set b){
    if(a.v -> hash == b.v -> hash && a.id == b.id)return 1;
    return 0;
}

bool Is_Smaller(node *a, node *b){
    if(a -> hash == b -> hash)return 0;
    bool wh = pos(a, b, 0ll, N);
    if(wh == 1)return 0;
    return 1;
}

inline bool operator > (for_set a, for_set b){
    if(a.v -> hash == b.v -> hash){
        if(a.id > b.id)return 1;
        return 0;
    }
    ll wh = pos(a.v, b.v, 0, N);
    if(wh == 1)return 1;
    return 0;
}

inline bool operator < (for_set a, for_set b){
    if(a.v -> hash == b.v -> hash){
        if(a.id < b.id)return 1;
        return 0;
    }
    ll wh = pos(a.v, b.v, 0, N);
    if(wh == 1)return 0;
    return 1;
}

for_set clr;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    p[0] = 1;
    pref[0] = 1;

    for(int i = 1; i < N + 30; i++){
        p[i] = p[i - 1] * 2;
        p[i] %= mod;
        pref[i] = pref[i - 1] + p[i];
        pref[i] %= mod;
    }
    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].p_b({b, c});
        v[b].p_b({a, c});
    }

    ll s, t;
    cin >> s >> t;
    f[s] = 1;
    dp[s] = new node(nullptr);
    build(dp[s], 0, N);
    set <for_set> st;
    clr.id = s;
    clr.v = dp[s];
    st.insert(clr);

    while(!st.empty()){
        for_set xe = *st.begin();
        st.erase(st.begin());
        if(dp[xe.id] != xe.v)continue;
        for(auto i : v[xe.id]){
            ll to = i.fi, val = i.se;
            node *tk = new node(xe.v);
            inst(tk);
            poz = 1e18;
            find(tk, 0, N, val, N);
            modify(tk, 0, N, val, poz - 1, 0);
            modify(tk, 0, N, poz, poz, 1);
            if(!f[to] || Is_Smaller(tk, dp[to])){
                clr.id = to;
                dp[to] = tk;
                f[to] = 1;
                clr.v = dp[to];
                pr[to] = xe.id;
                st.insert(clr);
            }

        }
    }

    if(!f[t]){
        vout(-1);
    }

    cout << (dp[t] -> hash) << "\n";

    vector <ll> ans;
    ll x = t;

    while(x){
        ans.p_b(x);
        x = pr[x];
    }

    reverse(all(ans));

    cout << ans.size() << "\n";

    for(auto i : ans)cout << i << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}