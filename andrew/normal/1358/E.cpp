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

ll t[3 * MAXN], t1[3 * MAXN];

void push(ll &v){
    t[v << 1] += t1[v];
    t[v << 1 | 1] += t1[v];
    t1[v << 1] += t1[v];
    t1[v << 1 | 1] += t1[v];
    t1[v] = 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        t[v] += val;
        t1[v] += val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    push(v);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return inf;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    push(v);
    return min(get(v << 1, tl, tm, l, min(r, tm)), get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int n;
    cin >> n;

    vector <ll> a(n + 1);
    for(int i = 1; i <= (n + 1) / 2; i++)cin >> a[i];
    ll x;
    cin >> x;
    for(int i = (n + 1) / 2 + 1; i <= n; i++)a[i] = x;

    vector <ll> pref(n + 1);

    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
    }

    if(pref[n] > 0)vout(n);

    if(x <= 0){
        ll pos = (n + 1) / 2 + 1;
        ll t = (n + 1) / 2;
        for(int i = 1; i <= n; i++)if(i + t - 1 <= n){
            modify(1, 1, n, i, i, pref[i + t - 1] - pref[i - 1]);
        }
        for(int k = (n + 1) / 2; k <= n; k++){
            if(get(1, 1, n, 1, n - k + 1) > 0)vout(k);
            modify(1, 1, n, 1, n, x);
        }
        vout(-1);
    }else{
        vout(-1);
    }

    return 0;
}