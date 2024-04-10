#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , n , T , a[2] , A[MAXN] , B[MAXN] , cnt[2][MAXN];
vector<pll> vec;

int main() {
    fast_io;

    cin >> q;
    while(q--){
        vec = {};
        cin >> n >> T >> a[0] >> a[1];
        fill(cnt[0] , cnt[0] + n + 10 , 0);
        fill(cnt[1] , cnt[1] + n + 10 , 0);
        for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
        for(ll i = 1 ; i <= n ; i++)    cin >> B[i] , vec.push_back({B[i] , A[i]});
        vec.push_back({-1 , - 1});
        Sort(vec);
        for(ll i = 1 ; i <= n ; i++)    cnt[0][i] = cnt[0][i - 1] + 1 - vec[i].Y , cnt[1][i] = cnt[1][i - 1] + vec[i].Y;

        ll ans = 0 , timer = 0;
        vec.push_back({T + 1 , 0});
        for(ll i = 1 ; i <= n + 1 ; i++){
            if(timer < vec[i].X){
                ll t1 = cnt[0][n] - cnt[0][i - 1] , t2 = cnt[1][n] - cnt[1][i - 1] , t3 = vec[i].X - timer - 1;
                ll x = min(t1 , (a[0] == 0 ? INF : t3 / a[0]));
                t3 -= x * a[0];
                ll y = min(t2 , (a[1] == 0 ? INF : t3 / a[1]));
                t3 -= y * a[1];
                ans = max(ans , i - 1 + x + y);
            }
            timer += a[vec[i].Y];
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/