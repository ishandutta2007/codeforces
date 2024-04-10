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
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return inf;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    if(t1[v])push(v);
    return min(get(v << 1, tl, tm, l, min(r, tm)), get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

ll sol(){

    ll k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    vector <ll> a(k1), b(k2), c(k3);
    ll n = k1 + k2 + k3;

    for(int i = 1; i < MAXN; i++){
        t[i] = t1[i] = 0;
    }

    vector <int> ct(n + 1);

    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    for(auto &i : c)cin >> i;

    for(auto i : a)ct[i] = 1;
    for(auto i : b)ct[i] = 2;
    for(auto i : c)ct[i] = 3;

    ll ans = inf, sc = 0;

    modify(1, 0, n, 0, 0, k1);

    for(int i = 1; i <= n; i++){
        if(ct[i] != 1)sc++;
        modify(1, 0, n, i, i, sc + k1 - (i - sc));
    }

    sc = 0;
    for(int i = 1; i <= n; i++)if(ct[i] == 2)sc++;

    for(int i = 1; i <= n + 1; i++){
        ans = min(ans, sc + get(1, 0, n, 0, i - 1));
        if(i == n + 1)continue;
        if(ct[i] == 3){
            sc++;
            modify(1, 0, n, i, n, -1);
        }
        else if(ct[i] == 2)sc--;
    }

    return ans;
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


    while(t--){
        cout << sol() << "\n";
    }

    return 0;
}