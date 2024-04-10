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
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

ll tin[MAXN], tout[MAXN], stn = -1, n;

struct node{
    ll t, t1;
};

node T[4 * MAXN];

void push(ll v){
    T[v << 1].t += T[v].t1;
    T[v << 1].t1 += T[v].t1;
    T[(v << 1) + 1].t += T[v].t1;
    T[(v << 1) + 1].t1 += T[v].t1;
    T[v].t1 = 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        T[v].t += val;
        T[v].t1 += val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(T[v].t1)push(v);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    T[v].t = max(T[v << 1].t, T[(v << 1) + 1].t);
}

void add(ll x){
    modify(1, 1, n, tin[x], tout[x], 1);
}

void del(ll x){
    modify(1, 1, n, tin[x], tout[x], -1);
}

void dfs(ll x){
    tin[x] = ++stn;
    for(auto to : v[x])dfs(to);
    tout[x] = stn;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll k;
    cin >> n >> k;

    vector <ll> a(n + 5);

    for(int i = 1; i <= n; i++)cin >> a[i];

    vector <ll> st;

    a[n + 1] = inf;

    st.p_b(n + 1);

    for(int i = n; i > 0; i--){
        while(a[st.back()] <= a[i])st.pop_back();
        v[st.back()].p_b(i);
        st.p_b(i);
    }

    dfs(n + 1);

    for(int i = 1; i <= k; i++)add(i);

    cout << T[1].t;

    for(int i = 2; i <= n - k + 1; i++){
        add(i + k - 1);
        del(i - 1);
        cout << " " << T[1].t;
    }

    cout << "\n";

    return 0;
}