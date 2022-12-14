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
#define fout(x) { cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e9;
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void main_solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n + 1);
    vector <pll> b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin() + 1, b.end());
    reverse(b.begin() + 1, b.end());

    ll ans = 1, res = 0;

    vector <ll> p;

    for(int i = 1; i <= k; i++){
        p.p_b(b[i].se);
        res += b[i].fi;
    }

    sort(all(p));

    for(int i = 1; i < sz(p); i++)(ans *= p[i] - p[i - 1]) %= mod;
    cout << res << " " << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif // LOCAL

    for(int id = 1; id <= t; id++){
        #ifdef LOCAL
            cout << "Test number " << id << ":\n";
        #endif // LOCAL
        main_solve();
    }


    return 0;
}