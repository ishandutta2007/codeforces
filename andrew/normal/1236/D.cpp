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
#define sz(x) (ll)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


set <ll> str[MAXN], stl[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;



    ll kol = 1;


    for(int i = 0; i < k; i++){
        ll y, x;
        cin >> y >> x;
        str[y].insert(x);
        stl[x].insert(y);
    }


    ll sx = 1, sy = 1;
    ll ly = 0, ry = m + 1, lx = 0, rx = n + 1;

    for(int i = 1; i <= n; i++){
        str[i].insert(0);
        str[i].insert(m + 1);
    }

    for(int i = 1; i <= m; i++){
        stl[i].insert(0);
        stl[i].insert(n + 1);
    }

    ll Kol = 0;

    for(int i = 1; i <= n; i++)if(stl[1].find(i) != stl[1].end())break;
    else Kol++;

    if(Kol == n * m - k)vout("Yes");

    ll step = 1;

    while(1){
        if(step == 1){
            ll tx = sx, ty = *str[sx].upper_bound(sy) - 1;
            ty = min(ty, ry - 1);
            if(ty <= sy)break;
            kol += abs(sy - ty);
            lx = sx;
            sy = ty;
            step = 2;
            continue;
        }

        if(step == 2){
            ll ty = sy, tx = *stl[sy].upper_bound(sx) - 1;
            tx = min(tx, rx - 1);
            if(tx <= sx)break;
            kol += abs(sx - tx);
            ry = sy;
            sx = tx;
            step = 3;
            continue;
        }

        if(step == 3){
            ll tx = sx, ty = *(--str[sx].lower_bound(sy)) + 1;
            ty = max(ty, ly + 1);
            if(ty >= sy)break;
            kol += abs(ty - sy);
            rx = sx;
            sy = ty;
            step = 4;
            continue;
        }

        if(step == 4){
            ll ty = sy, tx = *(--stl[sy].lower_bound(sx)) + 1;
            tx = max(tx, lx + 1);
            if(tx >= sx)break;
            kol += abs(tx - sx);
            ly = sy;
            sx = tx;
            step = 1;
            continue;
        }
    }

    if(kol == n * m - k)cout << "Yes\n";
    else cout << "No\n";

    return 0;
}