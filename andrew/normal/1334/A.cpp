#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5;
const int MAXN = 1123456;
const ll inf = 3e18;
const ll mod = 1000000007;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n;
    cin >> n;
    ll a, b;
    a = b = 0;
    string ans = "YES\n";
    while(n--){
        ll x, y;
        cin >> x >> y;
        if(x < a || y < b)ans = "NO\n";
        else if(y - b > x - a)ans = "NO\n";
        a = x, b = y;
    }
    cout << ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}