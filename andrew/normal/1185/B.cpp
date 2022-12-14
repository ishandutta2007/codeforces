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

    ll q;
    cin >> q;

    while(q--){
        string sa, sb;
        cin >> sa >> sb;

        vector <char> a, b;

        for(auto i : sa)a.p_b(i);

        ll last = 0;

        string ans = "YES";

        reverse(all(sb));

        for(auto i : sb){
            if(a.empty() || a.back() != i){
                if(i != last)ans = "NO";
            }else{
                last = i;
                a.pop_back();
            }
        }

        if(!a.empty())ans = "NO";

        cout << ans << "\n";
    }

    return 0;
}