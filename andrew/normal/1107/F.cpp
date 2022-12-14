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
 
struct ver{
    ll a, b, k;
};
 
ll Len;
 
vector <ver> G;
 
ll a[501][501];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    G.resize(n);
 
    for(int i = 0; i < n; i++){
        cin >> G[i].a >> G[i].b >> G[i].k;
        for(int j = 1; j <= n; j++){
            a[i + 1][j] = -max(0ll, G[i].a);
            if(j <= G[i].k)G[i].a -= G[i].b;
        }
    }
 
    ll INF = 1e18;
 
    vector <ll> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
 
 
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<ll> minv(n + 1, INF);
        vector<bool> used(n + 1, 0);
 
        do {
            used[j0] = 1;
            ll i0 = p[j0], delta = INF,  j1;
            for (int j = 1; j <= n; ++j)
                if (!used[j]) {
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j = 0; j <= n; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
 
    vout(v[0]);
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}