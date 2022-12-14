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
#define pii pair<int,int>
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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <vector <ll>> sstd, c;

ll n;

ll Max = 1e18 + 2;

ll mul(ll a, ll b){
    if(!a)return 0;
    if(Max / a < b)return Max;
    return a * b;
}

vector <vector <ll>> bp(vector <vector <ll>> a, ll N){
    vector <vector <ll>> res;
    while(N){
        if((N & 1)){
            if(res.empty())res = a;
            else{
                c = res;
                for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++){
                    res[i][j] = 0;
                    for(int k = 0; k < n; k++){
                        res[i][j] += mul(c[i][k], a[k][j]);
                        if(res[i][j] >= Max)res[i][j] = Max;
                    }
                }
            }
        }
        c = a;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
            for(int k = 0; k < n; k++){
                a[i][j] += mul(c[i][k], c[k][j]);
                if(a[i][j] >= Max)a[i][j] = Max;
            }
        }
        N >>= 1;
    }
    return res;
}

ll MultVectorMax(vector <ll> a, vector < vector <ll> > b){
    ll res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll sc = 0;
            for(int k = 0; k < n; k++){
                sc += mul(a[k], b[k][j]);
                if(sc >= Max)sc = Max;
            }
            res = max(res, sc);
        }
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;

    vector <ll> a;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        a.p_b(x);
        if(x >= k)vout(0);
    }

    reverse(all(a));

    while(!a.empty() && a.back() == 0)a.pop_back();
    reverse(all(a));

    if(a.size() > 10){
        vector <ll> b;
        for(int step = 0;;step++){
            for(auto i : a)if(i >= k)vout(step);
            ll sc = 0;
            b.clear();
            for(auto i : a){
                sc += i;
                if(sc >= k)sc = k;
                b.p_b(sc);
            }
            a = b;
        }
    }

    n = a.size();
    sstd.resize(n);
    c.resize(n);

    for(int i = 0; i < n; i++)sstd[i].resize(n), c[i].resize(n);


    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)sstd[i][j] = 1;

    ll l = 1, r = 1e18;
    while(l < r){
        ll c = (l + r) >> 1;
        if(MultVectorMax(a, bp(sstd, c)) < k)l = c + 1; else r = c;
    }
    cout << l << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}