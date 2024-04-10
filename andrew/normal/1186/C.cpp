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
const ll N = 1e6;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    ll n = a.size(), m = b.size();
    ll sc1 = 0;
    for(int i = 1; i <= m; i++){
        sc1 += b[i - 1] - '0';
    }

    ll ans = 0, sc = 0;

    for(int i = 1; i <= m; i++)sc += a[i - 1] - '0';

    for(int i = 1; i <= n - m + 1; i++){
        if(sc1 % 2 == sc % 2)ans++;
        if(i == n + m - 1)continue;
        sc -= a[i - 1] - '0';
        sc += a[i + m - 1] - '0';
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}