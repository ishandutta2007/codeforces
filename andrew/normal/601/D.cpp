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
const ll N = 2e5;
const ll mod1 = 1e9 + 7;
const ll mod = 998252377;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <ll> v[MAXN];

char c[MAXN];

ll st[MAXN], st1[MAXN];

ll p[MAXN];

set <pll> S[MAXN];
pll val[MAXN];

string s;
ll kol[MAXN];

ll mul(ll a, ll b){
    return (a * b) % mod;
}

ll mul1(ll a, ll b){
    return (a * b) % mod1;
}

void dfs(ll x, ll deep, ll pr){
    bool fl = 0;

    ll kl = 0, t = 0;

    for(auto to : v[x])if(to != pr){
        fl = 1;
        dfs(to, deep + 1, x);
        if(S[p[to]].size() > kl){
            kl = S[p[to]].size();
            t = to;
        }
    }

    if(!fl){
        p[x] = x;
        kol[x] = 1;
        S[x].insert({mul((s[x - 1] - 'a' + 1), st[deep]), mul1((s[x - 1] - 'a' + 1), st1[deep])});
        return;
    }

    p[x] = p[t];

    ll ra = p[x];

    for(auto to : v[x]){
        if(to == pr || to == t)continue;
        ll rb = p[to];
        for(auto i : S[rb]){
            pll x = i;
            x.fi += val[rb].fi;
            if(x.fi >= mod)x.fi -= mod;
            x.fi -= val[ra].fi;
            if(x.fi < 0)x.fi += mod;
            x.se += val[rb].se;
            if(x.se >= mod1)x.se -= mod1;
            x.se -= val[ra].se;
            if(x.se < 0)x.se += mod1;
            S[ra].insert(x);
        }
        S[rb].clear();
    }

    ll kt = -val[ra].fi;
    if(kt < 0)kt += mod;
    ll kt1 = -val[ra].se;
    if(kt1 < 0)kt1 += mod1;

    S[ra].insert({kt, kt1});
    (val[ra].fi += (s[x - 1] - 'a' + 1) * st[deep]) %= mod;
    (val[ra].se += (s[x - 1] - 'a' + 1) * st1[deep]) %= mod1;
    kol[x] = S[ra].size();
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    st[0] = 1;
    st1[0] = 1;

    for(ll i = 1; i <= 300005; i++){
        st[i] = (st[i - 1] * 31ll) % mod;
        st1[i] = (st1[i - 1] * 31ll) % mod1;
    }

    ll n;
    cin >> n;

    vector <ll> c(n + 1);

    for(int i = 1; i <= n; i++)cin >> c[i];

    cin >> s;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll, 0ll);

    ll mx = -1, sc = 0;

    for(int i = 1; i <= n; i++){
        if(kol[i] + c[i] > mx)mx = kol[i] + c[i], sc = 0;
        if(kol[i] + c[i] == mx)sc++;
    }

    cout << mx << "\n" << sc << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}