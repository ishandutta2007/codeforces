#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll add(ll a, ll b){
    if(a + b >= mod)return a + b - mod;
    return a + b;
}

ll mul(ll a, ll b){
    return (a * b) % mod;
}

void u(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

ll n;

struct matrix{
    vector <vector <ll>> a;

    void build(ll n){
        a.resize(n);
        for(int i = 0; i < n; i++){
            a[i].resize(n);
        }
    }

    void operator *= (matrix b){
        matrix res;
        res.build(n);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)u(res.a[i][j], mul(a[i][k], b.a[k][j]));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)a[i][j] = res.a[i][j];

    }

};

matrix clr;


inline matrix operator *(matrix &a, matrix &b){
    matrix res;
    res = clr;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)u(res.a[i][j], mul(a.a[i][k], b.a[k][j]));
}

inline bool operator == (matrix &a, matrix &b){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)if(a.a[i][j] != b.a[i][j])return 0;
    return 1;
}


ll f(ll x){
    ll res = 0;
    while(x){
        res += x % 2;
        if(res == 3)res = 0;
        x >>= 1;
    }
    return (res == 0);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;

    if(k == 1)vout(n);

    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    clr.build(n);

    matrix res = clr;

    for(int i = 0; i < n; i++){
        res.a[i][i] = 1;
    }

    k--;

    matrix st = clr, resSt;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)if(f(a[i] ^ a[j]))st.a[i][j] = 1;

    resSt = clr;


    while(k){
        if(k & 1){
            if(resSt == clr)resSt = st;
            else resSt *= st;
        }
        st *= st;
        k >>= 1;
    }

    res *= resSt;

    ll ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)u(ans, res.a[i][j]);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}