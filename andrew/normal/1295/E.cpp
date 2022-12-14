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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll N;

ll t[MAXN], t1[MAXN];

void push(ll v){
    t[v << 1] += t1[v];
    t1[v << 1] += t1[v];
    t[v << 1 | 1] += t1[v];
    t1[v << 1 | 1] += t1[v];
    t1[v] = 0;
}

void u(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        t[v] += val;
        t1[v] += val;
        return;
    }
    push(v);
    ll tm = (tl + tr) >> 1;
    u(v << 1, tl, tm, l, min(r, tm), val);
    u(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void main_solve(){
    ll n;
    cin >> n;

    #ifdef LOCAL
        for(int i = 1; i <= 4 * n + 5; i++)t[i] = t1[i] = 0;
    #endif // LOCAL

    vector <ll> p(n + 1), where(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        where[p[i]] = i;
    }
    for(int i = 1; i <= n; i++)cin >> a[i];
    ll ans = a[1], sc = 0;
    vector <bool> f(n + 1);
    for(int i = 1; i <= n; i++){
        if(p[1] != i)sc += a[where[i]];
        u(1, 1, n, i, i, sc + ((p[1] <= i) ? 0 : a[1]));
    }

    for(int k = 2; k <= n; k++){
        ans = min(ans, t[1]);
        u(1, 1, n, 1, p[k] - 1, a[k]);
        u(1, 1, n, p[k], n, -a[k]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}