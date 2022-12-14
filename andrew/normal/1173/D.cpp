#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
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
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

const ll mod = 998244353;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll ans = 1;

    ll n;
    cin >> n;

    vector <ll> p(n + 1), fact(n + 1);

    fact[0] = 1;

    for(ll i = 1; i <= n; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        p[a]++;
        p[b]++;
    }

    ans = n;

    for(int i = 1; i <= n; i++)ans = (fact[p[i]] * ans) % mod;

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}