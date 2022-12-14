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
#define fout(x) {cout << x << endl; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll pr[MAXN];

ll get(ll x){
    if(pr[x] != x)pr[x] = get(pr[x]);
    return pr[x];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, k;
    cin >> n >> k;

    vector <ll> p(n + 1), q(n + 1);

    for(int i = 1; i <= n; i++)cin >> p[i];
    for(int i = 1; i <= n; i++)cin >> q[i];

    vector <ll> pos_in_first(n + 1);

    for(int i = 1; i <= n; i++)pos_in_first[p[i]] = i;
    for(int i = 1; i <= n; i++)pr[i] = i;

    vector <ll> pref(n + 1), suf(n + 1);

    for(int i = 1; i <= n; i++){
        pref[i] = suf[i] = pos_in_first[q[i]];
    }

    for(int i = n - 1; i > 0; i--)suf[i] = min(suf[i], suf[i + 1]);

    for(int i = 2; i <= n; i++)pref[i] = max(pref[i - 1], pref[i]);

    vector <pll> t;

    for(int i = 1; i <= n; i++){
        t.p_b({suf[i], pref[i]});
    }

    vector <ll> r(n + 1);

    for(auto i : t){
        r[i.fi] = max(r[i.fi], i.se);
    }

    ll last = 0;

    for(int i = 1; i <= n; i++){
        last = max(last, r[i]);
        if(i < last){
            pr[i] = get(i + 1);
        }
    }

    vector <ll> comp;

    for(int i = 1; i <= n; i++)if(get(i) == i)comp.p_b(i);

    vector <char> kek(n + 1);

    if(sz(comp) < k)vout("NO");

    for(ll i = 0; i < sz(comp); i++){
        kek[comp[i]] = char('a' + min(i + 1, k) - 1);
    }

    vector <char> ans(n + 1);

    for(int i = 1; i <= n; i++)ans[p[i]] = kek[get(i)];

    cout << "YES\n";
    for(int i = 1; i <= n; i++)cout << ans[i];

    cout << "\n";

    return 0;
}