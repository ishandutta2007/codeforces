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
const ll N = 2e5;
const ll MOD = 998244353;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll kol[MAXN];
ll dp[MAXN];

vector <pll> v[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll musk = 0;

    while(n--){
        ll k;
        cin >> k;
        musk = 0;
        while(k--){
            ll x;
            cin >> x;
            x--;
            musk |= pw(x);
        }
        kol[musk]++;
    }

    for(int i = 0; i < pw(9); i++){
        ll sc = 0;
        for(int j = 0; j < pw(9); j++)if((i & j) == j)sc += kol[j];
        dp[i] = sc;
    }

    ll step = 0;

    while(m--){
        step++;
        ll k, cost, msk = 0;
        cin >> cost >> k;
        while(k--){
            ll x;
            cin >> x;
            x--;
            msk |= pw(x);
        }

        v[msk].p_b({cost, step});
    }

    for(int i = 0; i < pw(9); i++)sort(all(v[i]));

    ll res = -1;

    ll ans = 1e18;
    ll xa, xb;

    for(int i = 0; i < pw(9); i++)
    for(int j = 0; j < pw(9); j++)if(dp[i | j] >= res){
        if(i != j){
            if(!v[i].empty() && !v[j].empty()){
                if(res != dp[i | j]){
                    ans = 1e18;
                    res = dp[i | j];
                }
                ll sc = v[i][0].fi + v[j][0].fi;
                if(sc < ans){
                    ans = sc;
                    xa = v[i][0].se, xb = v[j][0].se;
                }
            }
        }else{
            if(v[i].size() > 1){
                if(res != dp[i | j]){
                    ans = 1e18;
                    res = dp[i | j];
                }
                ll sc = v[i][0].fi + v[i][1].fi;
                if(sc < ans){
                    ans = sc;
                    xa = v[i][0].se, xb = v[i][1].se;
                }
            }
        }
    }
    cout << xa << " " << xb << "\n";

    return 0;
}