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
const ll mod = 998244353;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

int a[3011][3011], gr[3011][3011];
ll n, m, pos;
ll c[MAXN];

int pref[MAXN], suf[MAXN];

void build(int n, int k){
    for(int i = 1; i <= n; i++){
        pref[i] = c[i];
        if(i % k != 1 && k != 1)pref[i] = min(pref[i], pref[i - 1]);
    }

    suf[n + 1] = 1e9;

    for(int i = n; i > 0; i--){
        suf[i] = c[i];
        if(i % k)suf[i] = min(suf[i], suf[i + 1]);
    }

}

int get(int l, int r){
    return min(suf[l], pref[r]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int ra, b;
    cin >> n >> m >> ra >> b;
    ll g, x, y, z;
    cin >> g >> x >> y >> z;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = g;
            g = (g * x + y) % z;
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)c[j] = a[i][j];
        build(m, b);
        for(int j = 1; j <= m - b + 1; j++){
            gr[i][j] = get(j, j + b - 1);
        }
    }

    for(int j = 1; j <= m - b + 1; j++){
        for(int i = 1; i <= n; i++)c[i] = gr[i][j];
        build(n, ra);
        for(int i = 1; i <= n - ra + 1; i++){
            ans += get(i, i + ra - 1);
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}