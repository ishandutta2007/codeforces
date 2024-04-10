#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5 + 5;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

struct Fenwick{
    ll N;
    vector <ll> t;
public:
    void anons(ll n){
        N = n;
        t.resize(N + 1);
    }
    void u(ll pos, ll val){
        for(int i = pos; i <= N; i += i & -i)t[i] += val;
    }

    ll f(ll x){
        ll res = 0;
        for(int i = x; i > 0; i -= i & -i)res += t[i];
        return res;
    }

};


Fenwick clr;

vector <Fenwick> T, T1;


ll ans_1;
ll G[MAXN], id, poz[MAXN];
vector <ll> c[MAXN], v[MAXN];

void dfs(ll x, ll pr){
    c[id].p_b(x);
    G[x] = id;
    poz[x] = c[id].size();
    for(auto to : v[x])if(to != pr)dfs(to, x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    T.p_b(clr);
    T[0].anons(n);
    T1.p_b(clr);
    T1[0].anons(n);

    for(auto to : v[1]){
        ++id;
        dfs(to, 1ll);
        T.p_b(clr);
        T1.p_b(clr);
        T[id].anons(c[id].size());
        T1[id].anons(c[id].size());
    }

    while(q--){
        ll t;
        cin >> t;
        if(t == 0){
            ll v, x, d;
            cin >> v >> x >> d;
            if(v == 1){
                ans_1 += x;
                T[0].u(1, x);
                T[0].u(d + 1, -x);
            }else{
                ll l = poz[v] - d, r = poz[v] + d;
                if(l < 1){
                    ans_1 += x;
                    l = 1;
                }
                r = min(r, ll(c[G[v]].size()));
                T[G[v]].u(l, x);
                T[G[v]].u(r + 1, -x);
                if(poz[v] < d){
                    ll k = d - poz[v];
                    T[0].u(1, x);
                    T[0].u(k + 1, -x);
                    T1[G[v]].u(1, x);
                    T1[G[v]].u(k + 1, -x);
                }
            }
        }else{
            ll x;
            cin >> x;
            if(x == 1)cout << ans_1 << "\n"; else{
                cout << T[0].f(poz[x]) + T[G[x]].f(poz[x]) - T1[G[x]].f(poz[x]) << "\n";
            }
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}