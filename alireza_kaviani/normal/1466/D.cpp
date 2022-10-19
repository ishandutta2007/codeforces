#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , n , deg[MAXN] , w[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        fill(deg , deg + n + 2 , 0);
        ll ans = 0;
        for(int i = 1 ; i <= n ; i++){
            cin >> w[i];
            ans += w[i];
        }
        for(int i = 1 ; i < n ; i++){
            int v , u;
            cin >> v >> u;
            deg[v]++ , deg[u]++;
        }
        vector<ll> vec;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j < deg[i] ; j++){
                vec.push_back(w[i]);
            }
        }
        sort(all(vec) , greater<ll>());
        cout << ans << sep;
        for(int i : vec){
            ans += i;
            cout << ans << sep;
        }
        cout << endl;
    }

    return 0;
}
/*

*/