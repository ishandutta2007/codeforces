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
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll t[MAXN];

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)t[v] = val;
    else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return -inf;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, min(r, tm)), get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

ll sol(){
    ll n, m, ans = 0;
    cin >> n;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        modify(1, 1, n, i, a[i]);
    }
    cin >> m;
    vector <pll> b(m + 1);
    vector <ll> pref(m + 2);
    ll mx = 0;
    for(int i = 1; i <= m; i++)cin >> b[i].fi >> b[i].se;
    sort(b.begin() + 1, b.end());

    if(*max_element(a.begin() + 1, a.end()) > b[m].fi)return -1;

    for(int i = m; i > 0; i--){
        pref[i] = max(pref[i + 1], b[i].se);
    }

    ll Pos = 1;

    while(Pos <= n){
        ans++;
        ll l = Pos, r = n;
        pll xe;
        while(l < r){
            ll c = (l + r + 1) >> 1;
            int x = get(1, 1, n, Pos, c);
            xe = {x, -1};
            int i = lower_bound(all(b), xe) - b.begin();
            if(pref[i] >= c - Pos + 1)l = c; else r = c - 1;

        }
        Pos = l + 1;
    }
    return ans;
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
        cout << sol() << "\n";
    }


    return 0;
}