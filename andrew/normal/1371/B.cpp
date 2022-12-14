#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 2123456;
const ll N = 2e5;
const ll inf = 1e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll f(ll x){
    return x * (x + 1) / 2;
}

void solve(){
    ll n, r;
    cin >> n >> r;
    ll ans = 0;
    if(n <= r){
        ans++;
    }
    ans += f(min(n - 1, r));
    fout(ans);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    cin >> t;

    while(t--)solve();



    return 0;
}