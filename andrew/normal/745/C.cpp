#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

vector <bool> fl;
vector <ll> v[MAXN];

ll kol;

void dfs(ll x){
    if(fl[x])return;
    kol++;
    fl[x] = 1;
    for(auto to : v[x])dfs(to);
}

ll f(ll x){
    return x * (x - 1) >> 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> c(k);
    ll old = m;
    fl.resize(n + 1);
    for(int i = 0; i < k; i++)cin >> c[i];
    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    ll rt = n;

    vector <ll> d;

    for(auto i : c){
        kol = 0;
        dfs(i);
        d.p_b(kol);
        rt -= kol;
    }


    ll res = 0;

    sort(all(d));

    res += f(d.back() + rt);

    d.pop_back();
    for(auto i : d)res += f(i);
    res -= old;
    cout << res << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}