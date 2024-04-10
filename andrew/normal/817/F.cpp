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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct node{
    int cnt;
    pll a, b;
};

node t[2 * N];

void push(int &v, int &tl, int &tr, int &tm){
    if(t[v].a < t[v].b){
        if(t[v].a.fi){
            t[v << 1].a = t[v].a;
            t[v << 1 | 1].a = t[v].a;
            if(t[v].a.se == 1){
                t[v << 1].cnt = tm - tl + 1;
                t[v << 1 | 1].cnt = tr - tm;
            }else{
                t[v << 1].cnt = 0;
                t[v << 1 | 1].cnt = 0;
            }
            t[v].a = {0, 0};
        }
        if(t[v].b.fi){

            if(t[v << 1].b > t[v << 1].a){
                t[v << 1].b = {0, 0};
            }else t[v << 1].b = t[v].b;

            if(t[v << 1 | 1].b > t[v << 1 | 1].a){
                t[v << 1 | 1].b = {0, 0};
            }else t[v << 1 | 1].b = t[v].b;

            t[v << 1].cnt = tm - tl + 1 - t[v << 1].cnt;
            t[v << 1 | 1].cnt = tr - tm - t[v << 1 | 1].cnt;

            t[v].b = {0, 0};
        }
    }else{
        t[v].b = {0, 0};
        if(t[v].a.fi){
            t[v << 1].a = t[v].a;
            t[v << 1 | 1].a = t[v].a;
            if(t[v].a.se == 1){
                t[v << 1].cnt = tm - tl + 1;
                t[v << 1 | 1].cnt = tr - tm;
            }else{
                t[v << 1].cnt = 0;
                t[v << 1 | 1].cnt = 0;
            }
            t[v].a = {0, 0};
        }
    }
}

void modify(int v, int tl, int tr, int l, int r, pll zp){
    if(l > r)return;
    if(tl == l && tr == r){
        if(zp.se == 1){
            t[v].a = zp;
            t[v].b = {0, 0};
            t[v].cnt = tr - tl + 1;
        }else if(zp.se == 2){
            t[v].a = zp;
            t[v].b = {0, 0};
            t[v].cnt = 0;
        }else{
            if(t[v].b.fi > t[v].a.fi){
                t[v].b = {0, 0};
            }else t[v].b = zp;
            t[v].cnt = tr - tl + 1 - t[v].cnt;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr, tm);
    modify(v << 1, tl, tm, l, min(r, tm), zp);
    modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, zp);
    t[v].cnt = t[v << 1].cnt + t[v << 1 | 1].cnt;
}

ll ans = -1;

void finding(int v, int tl, int tr){
    if(tr - tl + 1 == t[v].cnt)return;
    if(ans != -1)return;
    if(tl == tr){
        ans = tl;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr, tm);
    finding(v << 1, tl, tm);
    finding(v << 1 | 1, tm + 1, tr);
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
    vector <pair <pll, ll> > a(n);
    vector <ll> s;

    for(int i = 0; i < n; i++){
        cin >> a[i].se >> a[i].fi.fi >> a[i].fi.se;
        s.p_b(a[i].fi.fi - 1);
        s.p_b(a[i].fi.fi + 1);
        s.p_b(a[i].fi.fi);
        s.p_b(a[i].fi.se - 1);
        s.p_b(a[i].fi.se + 1);
        s.p_b(a[i].fi.se);
    }
    s.p_b(1);
    sort(all(s));

    s.erase(unique(all(s)), s.end());   
    if(*s.begin() == 0)s.erase(s.begin());

    map <ll, int> mp;

    for(int i = 0; i < sz(s); i++)mp[s[i]] = i + 1;

    int N = sz(s);

    for(int i = 0; i < n; i++){
        ans = -1;
        modify(1, 1, N, mp[a[i].fi.fi], mp[a[i].fi.se], {i + 1, a[i].se});
        finding(1, 1, N);
        cout << s[ans - 1] << "\n";
    }

    return 0;
}