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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> d(n + 1), deep(2 * n + 2), ver(3 * n + 2);

    vector <pll> c, ans;

    for(int i = 1; i <= n; i++){
        cin >> d[i];
        c.p_b({d[i], i});
    }

    sort(all(c));
    reverse(all(c));

    for(int i = 1; i < n; i++){
        ans.p_b({2 * c[i].se, 2 * c[i - 1].se});
    }

    for(int i = 0; i < n; i++){
        deep[c[i].se] = i + 1;
        ver[i + 1] = 2 * c[i].se;
    }

    for(auto j : c){
        ll k = deep[j.se] + j.fi - 1;
        ans.p_b({j.se * 2 - 1, ver[k]});
        if(!ver[k + 1])ver[k + 1] = j.se * 2 - 1;
    }

    for(auto j : ans)cout << j.fi << " " << j.se << "\n";

    return 0;
}