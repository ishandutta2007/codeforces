#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 1e18;
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <ll> v[MAXN];

ll h[MAXN], h1[MAXN], st[MAXN], st1[MAXN], a[MAXN];
map <pll, ll> mp;
ll gcd(ll a, ll b){
    if(!a || !b)return a + b;
    return __gcd(a, b);
}

void main_solve(){
    ll n, m;
    cin >> n >> m;
    mp.clear();
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v[i].clear();
    }
    while(m--){
        ll a, b;
        cin >> b >> a;
        v[a].p_b(b);
    }

    for(int i = 1; i <= n; ++i){
        if(sz(v[i])){
            sort(all(v[i]));
            ll h, h1;
            h = h1 = 0;
            for(auto j : v[i]){
                (h += st[j]) %= mod1;
                (h1 += st1[j]) %= mod2;
            }
            mp[{h, h1}] += a[i];
        }
    }

    ll ans = 0;
    for(auto i : mp)ans = gcd(ans, i.se);
    cout << ans << "\n";
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    st[0] = st1[0] = 1;
    for(int i = 1; i < MAXN; i++){
        st[i] = (st[i - 1] * 2) % mod1;
        st1[i] = (st1[i - 1] * 2) % mod2;
    }

    ll t;
    cin >> t;
    while(t--){
        main_solve();
    }

    return 0;
}