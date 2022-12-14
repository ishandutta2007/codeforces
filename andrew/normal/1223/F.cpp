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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

map <int, int> mp[MAXN];

void sol(){
    ll n;
    cin >> n;

    vector <ll> nxt(n + 3), a(n + 3), dp(n + 3);

    for(int i = 1; i <= n; i++){
        mp[i].clear();
        cin >> a[i];
    }

    for(int i = n; i > 0; i--){
        nxt[i] = -1;
        if(mp[i + 1].find(a[i]) != mp[i + 1].end()){
            int pos = mp[i + 1][a[i]];
            nxt[i] = pos;
            if(pos < n)swap(mp[i], mp[pos + 1]);
        }
        mp[i][a[i]] = i;
    }

    ll ans = 0;

    for(int i = n - 1; i > 0; i--){
        if(nxt[i] == -1)continue;
        dp[i] = 1 + dp[nxt[i] + 1];
        ans += dp[i];
    }
    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll q;

    cin >> q;

    while(q--){
        sol();
    }

    return 0;
}