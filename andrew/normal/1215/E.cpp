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

ll kol[20][MAXN];
ll dp[MAXN];

vector <ll> pos[21];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector <ll> a(n + 1), pref(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)a[i]--;
    for(int i = 1; i <= n; i++)pos[a[i]].p_b(i);

    for(int st = 0; st < 20; st++){

        for(int i = 1; i <= n; i++){
            pref[i] = pref[i - 1];
            if(a[i] == st)pref[i]++;
        }

        for(int j = 0; j < 20; j++)if(j != st){
            for(auto kek : pos[j]){
                kol[st][pw(j)] += ll(pos[st].size()) - pref[kek];
            }
        }

        for(int j = 0; j < 20; j++){
            for(int i1 = 0; i1 < pw(20); i1++)if((i1 & pw(j)) == 0){
                kol[st][i1 | pw(j)] += kol[st][i1];
            }
        }

    }

    for(int i = 1; i < pw(20); i++)dp[i] = 1e18;

    for(int i = 0; i < pw(20); i++){
        for(int j = 0; j < 20; j++)if((i & pw(j)) == 0){
            dp[i | pw(j)] = min(dp[i | pw(j)], dp[i] + kol[j][(pw(20) - 1) ^ i]);
        }
    }

    cout << dp[pw(20) - 1] << "\n";

    return 0;
}