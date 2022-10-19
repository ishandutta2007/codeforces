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

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , neg , pos , a[MAXN];
map<ll , ll> cnt;
vector<ll> crime;

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(a[i] > 0)    pos++;
        else neg++;
    }

    for(ll i = 1 ; i <= n ; i++){
        ll truth = cnt[i] + neg - cnt[-i];
        if(truth != m) continue;
        crime.push_back(i);
    }

    for(ll i = 1 ; i <= n ; i++){
        if(crime.size() == 1 && crime[0] == a[i]){
            cout << "Truth" << endl;
            continue;
        }
        if(a[i] > 0 && *lower_bound(all(crime) , a[i]) == a[i]){
            cout << "Not defined" << endl;
            continue;
        }
        if(a[i] > 0){
            cout << "Lie" << endl;
            continue;
        }
        if(*lower_bound(all(crime) , -a[i]) != -a[i]){
            cout << "Truth" << endl;
            continue;
        }
        if(crime.size() == 1){
            cout << "Lie" << endl;
            continue;
        }
        cout << "Not defined" << endl;
    }

    return 0;
}
/*

*/