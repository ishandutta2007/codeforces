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

ll a[10010001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        ll n, l, r;
        unsigned long long x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
        a[1] = (b1 % (r - l + 1)) + l;
        a[2] = (b2 % (r - l + 1)) + l;
        unsigned long long nw;
        for(int i = 3; i <= n; i++){
            nw = (b1 * x + b2 * y + z) % pw(32);
            b1 = b2;
            b2 = nw;
            a[i] = (nw % (r - l + 1)) + l;
        }

        ll ans = 5e18;

        ll mn = a[1];

        for(int i = 2; i <= n; i++){
            if(mn < a[i]){
                ans = min(ans, a[i] * mn);
            }else mn = a[i];
        }

        ll mx = a[n];

        for(int i = n - 1; i > 0; i--){
            if(mx > a[i])ans = min(ans, a[i] * mx);
            else mx = a[i];
        }

        if(ans == 5e18)cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }

    return 0;
}