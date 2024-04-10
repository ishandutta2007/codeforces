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

struct for_dp{
    ll Ost, k1, k2;
};

bool operator < (for_dp a, for_dp b){
    if(a.Ost < b.Ost)return 1;
    if(a.Ost > b.Ost)return 0;

    if(a.k1 < b.k1)return 1;
    if(a.k1 > b.k1)return 0;

    if(a.k2 < b.k2)return 1;
    if(a.k2 > b.k2)return 0;

    return 0;
}

for_dp clr;

vector <vector < vector <short int> > > dp[MAXN];

ll f1[MAXN], f2[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, p, k;
    cin >> n >> p >> k;

    ll m;
    cin >> m;
    while(m--){
        ll x;
        cin >> x;
        f1[x] = 1;
    }

    cin >> m;
    while(m--){
        ll x;
        cin >> x;
        f2[x] = 1;
    }

    if(2 * (n / k + (n % k > 0)) < p){
        ll ans = 0;
        for(int i = 1; i <= n; i++)ans += f1[i] | f2[i];
        vout(ans);
    }


    for(int i = 0; i <= n; i++){
        dp[i].resize(p + 1);
        for(int j = 0; j <= p; j++){
            dp[i][j].resize(k + 1);
            for(int i1 = 0; i1 <= k; i1++){
                dp[i][j][i1].resize(k + 1);
                for(int c = 0; c <= k; c++)dp[i][j][i1][c] = -1;
            }
        }
    }

    clr.Ost = p;
    clr.k1 = clr.k2 = 0;
    dp[0][clr.Ost][clr.k1][clr.k2] = 0;

    short int res;

    for(int i = 1; i <= n; i++){
        for(int Ost = 0; Ost <= p; Ost++)
            for(int k1 = 0; k1 <= k; k1++)
            for(int k2 = 0; k2 <= k; k2++)if(dp[i - 1][Ost][k1][k2] != -1){
                for(int j = 0; j < pw(2); j++){
                    clr.Ost = Ost;
                    clr.k1 = k1;
                    clr.k2 = k2;
                    res = dp[i - 1][Ost][k1][k2];
                    if((j & pw(0))){
                        clr.k1 = k;
                        clr.Ost--;
                    }
                    if((j & pw(1))){
                        clr.k2 = k;
                        clr.Ost--;
                    }
                    if(clr.Ost < 0)continue;
                    if((f1[i] && clr.k1) || (f2[i] && clr.k2))res++;
                    if(clr.k1)clr.k1--;
                    if(clr.k2)clr.k2--;
                    dp[i][clr.Ost][clr.k1][clr.k2] = max(dp[i][clr.Ost][clr.k1][clr.k2], res);

                }
        }
    }

    short int ans = 0;
    for(int Ost = 0; Ost <= p; Ost++)
        for(int k1 = 0; k1 <= k; k1++)
        for(int k2 = 0; k2 <= k; k2++)ans = max(ans, dp[n][Ost][k1][k2]);
    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}