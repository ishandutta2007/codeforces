#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")


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

ll mod;

void Evkl(ll a, ll b, ll &x, ll &y){
    if(!a){
        x = 0, y = 1;
        return;
    }
    ll x1, y1;
    Evkl(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
}

ll inv(ll a){
    ll x, y;
    Evkl(a, mod, x, y);
    x = (x + mod) % mod;
    return x;
}

ll divMOD(ll a, ll b){
    return (a * inv(b)) % mod;
}

ll p[MAXN], p1[MAXN], sum[MAXN], M, n;

vector <ll> ve[MAXN];
vector <ll> kek[20];
vector <ll> a;

void push(ll v){
    if(p1[v] != 1){
        ll x = p1[v];
        p1[v] = 1;
        (p[v << 1] *= x) %= mod;
        (p1[v << 1] *= x) %= mod;
        (p[(v << 1) + 1] *= x) %= mod;
        (p1[(v << 1) + 1] *= x) %= mod;
        (sum[v << 1] *= x) %= mod;
        (sum[(v << 1) + 1] *= x) %= mod;
    }
    for(int i = 0; i < M; i++)if(ve[v][i]){
        ve[v << 1][i] += ve[v][i];
        (sum[v << 1] *= kek[i][ve[v][i]]) %= mod;
        ve[(v << 1) + 1][i] += ve[v][i];
        (sum[(v << 1) + 1] *= kek[i][ve[v][i]]) %= mod;
        ve[v][i] = 0;
    }
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if(l > r)return;
    if(tl == l && tr == r){
        (p[v] *= x) %= mod;
        (sum[v] *= x) %= mod;
        (p1[v] *= x) %= mod;
        return;
    }
    ll tm = (tl + tr) >> 1;
    push(v);
    modify(v << 1, tl, tm, l, min(r, tm), x);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, x);
    p[v] = (p[v << 1] + p[(v << 1) + 1]) % mod;
    sum[v] = (sum[v << 1] + sum[(v << 1) + 1]) % mod;
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return sum[v];
    push(v);
    ll tm = (tl + tr) >> 1;
    return (get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r)) % mod;
}

void err(ll v, ll tl, ll tr, ll pos, ll x){
    if(tl == tr){
        p[v] = divMOD(p[v], x);
        sum[v] = p[v];
        for(int i = 0; i < M; i++)if(ve[v][i])(sum[v] *= kek[i][ve[v][i]]) %= mod;
    }
    else{
        ll tm = (tl + tr) >> 1;
        push(v);
        if(pos <= tm)err(v << 1, tl, tm, pos, x);
        else err((v << 1) + 1, tm + 1, tr, pos, x);
        p[v] = (p[v << 1] + p[(v << 1) + 1]) % mod;
        sum[v] = (sum[v << 1] + sum[(v << 1) + 1]) % mod;
    }
}

void err1(ll v, ll tl, ll tr, ll pos, ll j, ll kol){
    if(tl == tr){
        sum[v] = p[v];
        ve[v][j] -= kol;
        for(int i = 0; i < M; i++)if(ve[v][i])(sum[v] *= kek[i][ve[v][i]]) %= mod;
    }
    else{
        ll tm = (tl + tr) >> 1;
        push(v);
        if(pos <= tm)err1(v << 1, tl, tm, pos, j, kol);
        else err1((v << 1) + 1, tm + 1, tr, pos, j, kol);
        p[v] = (p[v << 1] + p[(v << 1) + 1]) % mod;
        sum[v] = (sum[v << 1] + sum[(v << 1) + 1]) % mod;
    }
}

void modi(ll v, ll tl, ll tr, ll l, ll r, ll j, ll kol){
    if(l > r)return;
    if(tl == l && tr == r){
        (sum[v] *= kek[j][kol]) %= mod;
        ve[v][j] += kol;
        return;
    }
    ll tm = (tl + tr) >> 1;
    push(v);
    modi(v << 1, tl, tm, l, min(r, tm), j, kol);
    modi((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, j, kol);
    p[v] = (p[v << 1] + p[(v << 1) + 1]) % mod;
    sum[v] = (sum[v << 1] + sum[(v << 1) + 1]) % mod;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> mod;

    ll x = mod;

    while(x != 1){
        bool fl = 0;
        ll j;
        for(j = 2; j * j <= x; j++)if(x % j == 0){
            fl = 1;
            break;
        }
        if(!fl)j = x;
        a.p_b(j);
        while(x % j == 0)x /= j;
    }

    sort(all(a));

    M = a.size();

    for(int i = 0; i < M; i++){
        kek[i].p_b(1ll);
        for(int j = 1; j <= 2e6; j++)kek[i].p_b((kek[i][j - 1] * a[i]) % mod);
    }

    for(int i = 1; i < 5e5; i++){
        sum[i] = p[i] = p1[i] = 1;
        ve[i].resize(M);
    }

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 0; j < M; j++){
            ll kol = 0;
            while(x % a[j] == 0)x /= a[j], kol++;
            if(kol)modi(1, 1, n, i, i, j, kol);
        }
        modify(1, 1, n, i, i, x);
    }


    ll q;
    cin >> q;
    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll l, r, x;
            cin >> l >> r >> x;
            for(int i = 0; i < M; i++){
                ll kol = 0;
                while(x % a[i] == 0)x /= a[i], kol++;
                if(kol)modi(1, 1, n, l, r, i, kol);
            }
            if(x != 1)modify(1, 1, n, l, r, x);
        }else if(t == 2){
            ll pos, x;
            cin >> pos >> x;
            for(int i = 0; i < M; i++){
                ll kol = 0;
                while(x % a[i] == 0)x /= a[i], kol++;
                if(kol)err1(1, 1, n, pos, i, kol);
            }
            if(x != 1)err(1, 1, n, pos, x);
        }else{
            ll l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}