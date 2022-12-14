#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e6;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(vector <ll> a) {
    ll x = a[1];
    for (ll i = 2; i < sz(a); i++) x = __gcd(x, a[i]);
    return x == 1;
}

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    b = a;
    if (check(b)) fout(0);
    
    b[n] = __gcd(b[n], n);
    if (check(b)) fout(1);
    
    b[n] = a[n];
    b[n - 1] = __gcd(b[n - 1], n - 1);
    if (check(b)) fout(2);

    fout(3);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    

    cin >> t;

    while (t--) {
        solve();
    }

    

    return 0;
}