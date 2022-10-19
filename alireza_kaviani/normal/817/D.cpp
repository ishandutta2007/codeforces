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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , ans , A[MAXN] , L[MAXN] , R[MAXN] , L2[MAXN] , R2[MAXN];
vector<ll> vec;

int main() {
    fast_io;

    cin >> n;
    fill(R , R + MAXN , n + 1);
    fill(R2 , R2 + MAXN , n + 1);
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];

    for(ll i = 1 ; i <= n ; i++){
        while(vec.size() > 0 && A[vec.back()] < A[i]){
            R[vec.back()] = i;
            vec.pop_back();
        }
        if(vec.size() > 0)  L[i] = vec.back();
        vec.push_back(i);
    }

    vec.clear();
    for(ll i = 1 ; i <= n ; i++){
        while(vec.size() > 0 && A[vec.back()] > A[i]){
            R2[vec.back()] = i;
            vec.pop_back();
        }
        if(vec.size() > 0)  L2[i] = vec.back();
        vec.push_back(i);
    }

    for(ll i = 1 ; i <= n ; i++){
        ans += (R[i] - i) * (i - L[i]) * A[i];
        ans -= (R2[i] - i) * (i - L2[i]) * A[i];
    }
    cout << ans << endl;

    return 0;
}
/*

*/