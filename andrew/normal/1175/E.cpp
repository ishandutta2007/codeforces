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
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll sp[500003][20];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector <pll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;
    for(auto &i : a){
        i.fi++;
        i.se++;
    }

    sort(all(a));

    ll uk = 0, Max = -3;

    for(int i = 1; i <= 5e5 + 1; i++){
        while(uk < n && a[uk].fi <= i){
            Max = max(Max, a[uk].se);
            uk++;
        }
        sp[i][0] = max(i - 1ll, Max);
    }

    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= 5e5 + 1; i++)sp[i][j] = max(sp[i][j - 1], sp[sp[i][j - 1]][j - 1]);
    }

    while(m--){
        ll x, y;
        cin >> x >> y;
        x++, y++;
        ll ans = 0;
        for(int i = 19; i >= 0; i--)if(sp[x][i] < y){
            ans += pw(i);
            x = sp[x][i];
        }

        if(sp[x][0] >= y){
            ans++;
            cout << ans << "\n";
        }else cout << "-1\n";

    }



    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}