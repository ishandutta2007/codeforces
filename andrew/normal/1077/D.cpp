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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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

map <ll, ll> mp;

ll b[MAXN];

ll f(ll x, ll k){
    ll N = 2e5;
    ll sc = 0;
    for(int i = 1; i <= N; i++)sc += b[i] / x;
    if(sc >= k)return 1;
    return 0;
}

void way(ll x, ll k){
    ll N = 2e5;
    vector <ll> a;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= b[i] / x; j++)a.p_b(i);
    }

    for(int i = 0; i < k; i++)cout << a[i] << " ";
    cout << "\n";
    exit(0);
    cout << "AKEL_SOSI\n";

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        b[x]++;
    }

    ll N = 2e5;

    ll l = 1, r = n;

    while(l < r){
        ll c = (l + r) >> 1;
        if(f(c, k))l = c + 1; else r = c;
    }

    if(!f(l, k))l--;
    way(l, k);
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}