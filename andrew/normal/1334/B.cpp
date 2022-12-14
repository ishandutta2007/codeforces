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
#define fout(x) {cout << x << "\n"; return;}

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
    ll n, x;
    cin >> n >> x;
    vector <ll> a(n);
    for(auto &i : a)cin >> i;
    sort(all(a));
    reverse(all(a));
    ll ans = 0;
    ll sc = 0;
    for(int i = 0; i < n; i++){
        sc += a[i];
        if(sc >= x * (i + 1))ans = i + 1;
    }
    fout(ans);
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