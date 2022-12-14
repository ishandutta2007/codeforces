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
const ll N = 1e5;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct edge{
    ll u, v;
};

vector <edge> g;
ll n;

ll pos[MAXN], p[MAXN], idx;

ll t[5 * MAXN], val;

set <pll> st[MAXN];

void modify(ll v, ll tl, ll tr, ll pos){
    t[v] = max(t[v], val);
    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos);
        else modify(v << 1 | 1, tm + 1, tr, pos);
    }else st[tl].insert({val, idx});
}

edge to_b;

set <pll> :: iterator it;

void solve(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return;
    if(t[v] < val)return;
    if(tl == tr){
        for(it = st[tl].end(); it != st[tl].begin();){
            --it;
            if(it -> fi < val)break;
            to_b.u = idx;
            to_b.v = it -> se;
            g.p_b(to_b);
            if(sz(g) > n - 1)vout("NO");
        }
        return;
    }
    ll tm = (tl + tr) >> 1;
    solve(v << 1, tl, tm, l, min(r, tm));
    solve(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
}


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

    cin >> n;
    vector <pll> a(n);
    for(auto &i : a)cin >> i.se >> i.fi;

    sort(all(a));

    int poz = 0;

    for(auto &i : a){
        swap(i.fi, i.se);
        idx = poz++;
        val = i.fi;
        solve(1, 1, 2 * n, 1, i.fi - 1);
        pos[i.fi] = idx;
        val = i.se;
        modify(1, 1, 2 * n, i.fi);
    }

    for(int i = 0; i < n; i++)p[i] = i;

    if(sz(g) != n - 1)vout("NO");

    for(auto i : g){
        if(get(i.u) == get(i.v))vout("NO");
        p[get(i.u)] = get(i.v);
    }

    vout("YES");

    return 0;
}