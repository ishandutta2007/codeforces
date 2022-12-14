#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define hash sosat

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll mod = 1e9 + 7;
const ll mod1 = 998244353;

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
        if(n % 2)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

const ll N = 1e7 + 2;

struct _set{
    ll a, b;
    int pa, pb;

    void insert(ll x, int pos){
        if(b > x){
            b = x;
            pb = pos;
        }
        if(a > b){
            swap(a, b);
            swap(pa, pb);
        }
    }

};

_set clr;

int f[N + 2];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));



    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    ll ans = 1e18, ax, ay;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        if(f[x]){
            if(ans > x){
                ans = x;
                ax = f[x];
                ay = i;
            }
        }
        f[x] = i;
    }

    for(int i = 1; i <= N; i++){
        clr.a = clr.b = 1e18;
        for(int j = i; j <= N; j += i)if(f[j])clr.insert(j, f[j]);
        if(clr.b != 1e18){
            ll val = (clr.a * clr.b) / ll(i);
            if(ans > val){
                ans = val;
                ax = clr.pa;
                ay = clr.pb;
            }
        }
    }

    if(ax > ay)swap(ax, ay);

    cout << ax << " " << ay << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}