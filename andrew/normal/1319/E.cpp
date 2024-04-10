#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define pll pair <ll, ll>
#define all(x) x.begin(),x.end()
#define pii pair <int, int>
#define sqr(x) ((x)*(x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll t[MAXN], t1[MAXN];

void push(ll v){
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
    if(t1[v])push(v);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = max(t[v << 1 | 1], t[v << 1]);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m, p;
    cin >> n >> m >> p;

    vector <pll> a(n), b(m);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    for(int i = 0; i < m; i++)cin >> b[i].fi >> b[i].se;

    sort(all(a));
    sort(all(b));

    vector < pair<pll, ll> > mb(p);

    for(int i = 0; i < m; i++){
        modify(1, 1, m, i + 1, i + 1, -b[i].se);
    }

    for(int i = 0; i < p; i++)cin >> mb[i].fi.fi >> mb[i].fi.se >> mb[i].se;

    sort(all(mb));

    ll ans = -inf;

    ll uk = 0;

    for(int i = 0; i < n; i++){
        while(uk < p && mb[uk].fi.fi < a[i].fi){
            if(b[m - 1].fi > mb[uk].fi.se){
                int l = 0, r = m - 1;
                while(l < r){
                    int c = (l + r) >> 1;
                    if(b[c].fi <= mb[uk].fi.se)l = c + 1;
                    else r = c;
                }
                modify(1, 1, m, l + 1, m, mb[uk].se);
            }
            uk++;
        }
        ans = max(ans, -a[i].se + t[1]);
    }

    cout << ans << "\n";

    return 0;
}