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

ll t[MAXN];

void u(ll pos, ll val){
    for(; pos <= N; pos += pos & -pos)t[pos] += val;
}

ll f(ll pos){
    ll res = 0;
    for(; pos > 0; pos -= pos & -pos)res += t[pos];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n;
    cin >> n;

    vector <ll> p(n + 1), s(n + 1);

    for(int i = 1; i <= n; i++)cin >> s[i];

    for(int i = 1; i <= n; i++)u(i, i);

    set <ll> mult;

    for(int i = 1; i <= n; i++)mult.insert(i);

    for(int i = n; i > 0; i--){
        ll l = 1, r = n;
        while(l < r){
            ll c = (l + r) >> 1;
            if(f(c - 1) < s[i])l = c + 1; else r = c;
        }
        p[i] = *mult.lower_bound(l);
        mult.erase(p[i]);
        u(p[i], -p[i]);
    }

    for(int i = 1; i <= n; i++)cout << p[i] << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}