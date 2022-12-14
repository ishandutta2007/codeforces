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
#define fout(x) {cout << x << endl;return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e3;
const ll inf = 2e9;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n, d;
    cin >> n >> d;
    if(d <= n)fout("YES");
    for(ll i = max(0ll, (ll)sqrt(d) - 10); i <= sqrt(d) + 10; i++){
        ll k = d / (i + 1);
        if(d % (i + 1))k++;
        if(k + i <= n)fout("YES");
    }
    fout("NO");
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