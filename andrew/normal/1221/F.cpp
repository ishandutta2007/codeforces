#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
#define Pos(x) (lower_bound(all(Values), x) - Values.begin())

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct point{
    ll x, y, c;
};

bool FlexCmp(point a, point b){
    if(min(a.x, a.y) < min(b.x, b.y))return 1;
    if(min(a.x, a.y) > min(b.x, b.y))return 0;
    return (m_p(max(a.x, a.y), a.c) < m_p(max(b.x, b.y), b.c));
}

vector <ll> Values;

pll p[5 * MAXN];
ll p1[5 * MAXN];

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        p[v] = {-Values[tl - 1], tl};
    }else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
    }
}


void push(ll v){
    p[v << 1].fi += p1[v];
    p[(v << 1) + 1].fi += p1[v];
    p1[v << 1] += p1[v];
    p1[(v << 1) + 1] += p1[v];
    p1[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        p[v].fi += val;
        p1[v] += val;
        return;
    }
    if(p1[v])push(v);
    ll tm = (tl + tr) >> 1;
    update(v << 1, tl, tm, l, min(r, tm), val);
    update((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    p[v] = max(p[v << 1], p[(v << 1) + 1]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;

    vector <point> arr(n);

    set <ll> ord;

    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].c;
        ord.insert(arr[i].x);
        ord.insert(arr[i].y);
    }

    sort(all(arr), FlexCmp);

    ll M = ord.size(), ans = 0, X, Y, Uk = 0;

    for(auto i : ord)Values.p_b(i);

    build(1, 1, M);

    X = 2e9, Y = 2e9;

    for(auto i : arr){
        update(1, 1, M, Pos(max(i.x, i.y)) + 1, M, i.c);
    }

    for(auto i : ord){
        while(Uk < n && min(arr[Uk].x, arr[Uk].y) < i){
            update(1, 1, M, Pos(max(arr[Uk].x, arr[Uk].y)) + 1, M, -arr[Uk].c);
            Uk++;
        }
        if(Values[p[1].se - 1] >= i){
            if(p[1].fi + i > ans){
                ans = p[1].fi + i;
                X = i, Y = Values[p[1].se - 1];
            }
        }
        update(1, 1, M, Pos(i) + 1, Pos(i) + 1, -1e18);
    }

    cout << ans << "\n";
    cout << X << " " << X << " " << Y << " " << Y << "\n";

    return 0;
}