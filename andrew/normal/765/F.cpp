#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 2e9;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <int> ve[MAXN];

int t[MAXN], a[MAXN];
vector <pii> v[MAXN];


void build(int v, int tl, int tr){
    if(tl == tr){
        ve[v].p_b(a[tl]);
    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        ve[v] = ve[v << 1];
        for(auto j : ve[v << 1 | 1])ve[v].p_b(j);
        sort(all(ve[v]));
    }
}


int get(int v, int tl, int tr, int l, int r){
    if(l > r)return inf;
    if(tl == l && tr == r)return t[v];
    int tm = (tl + tr) >> 1;
    return min(get(v << 1, tl, tm, l, min(r, tm)), get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int f(vector <int> &v, int x){
    int l = 0, r = sz(v) - 1;
    while(l + 1 < r){
        int c = (l + r) >> 1;
        if(v[c] <= x)l = c;
        else r = c;
    }
    return min(abs(v[l] - x), abs(v[r] - x));
}

void modify(int v, int tl, int tr, int pos, int val, int &_min){
    if(tl >= pos)return;
    if(f(ve[v], val) >= _min)return;
    if(tl == tr){
        t[v] = min(t[v], abs(a[tl] - val));
        _min = min(_min, t[v]);
    }else{
        int tm = (tl + tr) >> 1;
        modify(v << 1 | 1, tm + 1, tr, pos, val, _min);
        modify(v << 1, tl, tm, pos, val, _min);
        t[v] = min(t[v << 1], t[v << 1 | 1]);
    }
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
    for(int i = 1; i <= n; i++)cin >> a[i];
    fill(t, t + MAXN, inf);

    int m;
    cin >> m;

    vector <pair <pii, int> > zp(m);
    vector <int> ans(m);

    for(int i = 0; i < m; i++){
        cin >> zp[i].fi.fi >> zp[i].fi.se;
        zp[i].se = i;
        v[zp[i].fi.se].p_b({zp[i].fi.fi, zp[i].se});
    }

    build(1, 1, n);

    for(int i = 1; i <= n; i++){
        int _min = inf;
        modify(1, 1, n, i, a[i], _min);
        for(auto j : v[i]){
            ans[j.se] = get(1, 1, n, j.fi, i);
        }
    }

    for(int i = 0; i < m; i++)cout << ans[i] << "\n";

    return 0;
}