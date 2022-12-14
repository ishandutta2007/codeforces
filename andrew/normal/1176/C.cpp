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

ll mp[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    multiset <ll> s;

    vector <ll> c;

    c.p_b(1ll);
    c.p_b(4ll);
    c.p_b(8ll);
    c.p_b(15ll);
    c.p_b(16ll);
    c.p_b(23ll);
    c.p_b(42ll);

    for(int i = 1; i <= 6; i++)mp[c[i]] = i;

    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++)s.insert(1ll);

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        ll poz = mp[x];
        if(s.find(c[poz - 1]) != s.end()){
            s.erase(s.find(c[poz - 1]));
            s.insert(x);
        }
    }

    cout << n - 6 * s.count(42) << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}