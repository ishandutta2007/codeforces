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


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));



    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    vector <ll> a(n);

    set <ll> s;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }

    if(s.size() == 1)vout(0);

    if(s.size() == 2){
        ll a = *s.begin(), b = *(++s.begin());
        ll val = b - a;
        if(val % 2 == 0){
            vout((b - a) / 2);
        }

        vout(b - a);
    }

    if(s.size() == 3){
        ll a, b, c;
        a = *s.begin();
        b = *(++s.begin());
        c = *(--s.end());
        ll val = b - a;
        if(a + val == b && b + val == c)vout(val);
    }

    vout(-1);

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}