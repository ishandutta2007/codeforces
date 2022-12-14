#include <bits/stdc++.h>

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
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 3e5 + 5;
const ll inf = 1e18;
const int mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}

ll f(ll x){
    return x * (x + 1) / 2;
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, x;
    cin >> n >> x;

    vector <ll> d(n + 1);

    for(int i = 1; i <= n; i++)cin >> d[i];

    if(n == 1){
        ll sc = 0;
        while(x--){
            sc += d[1];
            d[1]--;
        }
        vout(sc);
    }

    ll xx = *max_element(all(d));
    if(xx >= x)vout(f(xx) - f(xx - x));

    vector <ll> pref(2 * n + 1), pref1(2 * n + 1);
    for(int i = 1; i <= n; i++)pref[i] = pref[i - 1] + d[i];
    for(int i = n + 1; i <= 2 * n; i++)pref[i] = pref[i - 1] + d[i - n];
    for(int i = 1; i <= n; i++)pref1[i] = pref1[i - 1] + f(d[i]);
    for(int i = n + 1; i <= 2 * n; i++)pref1[i] = pref1[i - 1] + f(d[i - n]);

    ll ans = 0, uk = 2, sc = d[1], sum = f(d[1]), st1, st2;

    for(int i = 1; i <= n; i++){
        ll l = i, r = 2 * n;
        while(l < r){
            ll c = (l + r + 1) >> 1;
            if(pref[c] - pref[i - 1] < x)l = c;
            else r = c - 1;
        }

        st1 = pref1[l] - pref1[i - 1] + f(x - pref[l] + pref[i - 1]);
        ans = max(ans, st1);
    }

    for(int i = n + 1; i <= 2 * n; i++){
        ll l = 1, r = i;
        while(l < r){
            ll c = (l + r) >> 1;
            if(pref[i] - pref[c - 1] >= x)l = c + 1;
            else r = c;
        }
        if(l == 1)continue;
        ll kek = l - 1;
        if(kek > n)kek -= n;
        st1 = pref1[i] - pref1[l - 1] + f(d[kek]) - f(d[kek] - (x - pref[i] + pref[l - 1]));
        ans = max(ans, st1);
    }

    vout(ans);

    return 0;
}