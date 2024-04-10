#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll MOD = 998244353;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <pll> b(n + 1);

    for(int i = 1; i <= n; i++)cin >> b[i].fi;
    for(int i = 1; i <= n; i++)b[i].se = i;

    vector <ll> ans;

    sort(b.begin() + 1, b.end());

    if(n == 2)vout(1);


    ll c = b[3].fi - b[2].fi;

    bool fl = 1;

    for(int i = 2; i < n; i++)if(b[i].fi + c != b[i + 1].fi)fl = 0;


    if(fl)vout(b[1].se);


    c = b[3].fi - b[1].fi;

    fl = 1;

    for(int i = 3; i < n; i++)if(b[i].fi + c != b[i + 1].fi)fl = 0;


    if(fl)vout(b[2].se);

    c = b[2].fi - b[1].fi;

    ll mb = 0;

    for(int i = 2; i < n; i++){
        if(b[i].fi + c != b[i + 1].fi){
            mb = i + 1;
            break;
        }
    }

    if(!mb)vout(b[n].se);

    vector <ll> kek;

    for(int i = 1; i <= n; i++)if(i != mb)kek.p_b(b[i].fi);

    c = kek[1] - kek[0];

    fl = 1;

    for(int i = 1; i < kek.size() - 1; i++)if(kek[i] + c != kek[i + 1])fl = 0;

    if(fl)vout(b[mb].se);

    vout(-1);

    return 0;
}