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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 32;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool f[MAXN];

ll p[MAXN];

ll get(ll x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    ll n;
    cin >> n;

    vector <ll> a(n + 1), x(n + 1), y(n + 1);

    for(int i = 1; i <= n; i++)cin >> x[i] >> y[i];

    vector <ll> c(n + 1), k(n + 1);

    for(int i = 1; i <= n; i++)cin >> c[i];
    for(int i = 1; i <= n; i++)cin >> k[i];
    for(int i = 1; i <= n; i++)p[i] = i;
    for(int i = 1; i <= n; i++)f[i] = 1;

    ll ans = 0;

    for(int i = 1; i <= n; i++)ans += c[i];

    vector < pair <ll, pll> > q;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)if(i != j){
        ll val = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        q.p_b({val, {i, j}});
    }
    vector <pll> res;
    sort(all(q));
    for(auto xe : q){
        ll a = xe.se.fi, b = xe.se.se;
        ll ra = get(a), rb = get(b);
        if(ra == rb)continue;
        if(max(c[ra], c[rb]) < xe.fi)continue;
        res.p_b({a, b});
        ans += xe.fi;
        ans -= max(c[ra], c[rb]);
        if(c[rb] > c[ra]){
            f[rb] = 0;
            p[rb] = ra;
        }else{
            f[ra] = 0;
            p[ra] = rb;
        }
    }

    cout << ans << "\n";

    vector <ll> w;

    for(int i = 1; i <= n; i++)if(f[i])w.p_b(i);
    cout << w.size() << "\n";
    for(auto i : w)cout << i << " ";
    cout << "\n";
    cout << res.size() << "\n";
    for(auto i : res)cout << i.fi << " " << i.se << "\n";

    return 0;
}