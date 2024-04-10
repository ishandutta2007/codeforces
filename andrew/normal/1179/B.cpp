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
const ll MOD = 1e9 + 7;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector <pll> v;

    ll n, m;
    cin >> n >> m;

    ll l = 1, r = n;

    ll le = 1, ri = m;

    ll st = 0;

    while(l <= r){
        if(!st){
            v.p_b({l, le});
            le++;
        }else{
            v.p_b({r, ri});
            ri--;
            if(ri == 0){
                l++;
                le = 1;
                r--;
                ri = m;
            }
        }
        st = 1 - st;
        if(l == r && le > ri)break;
    }

    for(auto i : v)cout << i.fi << " " << i.se << "\n";

    return 0;
}