#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const ll N = 1e5 + 6;
const ll inf = 2e9;
const ll M = 300000;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

char a[510][510];

ll pos[510][510];

vector <int> dp[510][510];

vector <pii> r1[1500], r2[1500];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cin >> a[i][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            r1[i + j - 2].p_b({i, j});
            pos[i][j] = sz(r2[n + m - i - j]);
            r2[n + m - i - j].p_b({i, j});
        }
    }

    ll Rust = n + m - 1;

    if(a[1][1] != a[n][m])vout(0);

    dp[1][1].resize(1);


    dp[1][1][0] = 1;

    vector <pii> mb_f, mb_s;

    for(int i = 0; i < (Rust - 1) / 2; i++){
        for(pii j : r1[i + 1]){
            dp[j.fi][j.se].resize(sz(r2[i + 1]));
        }
        for(pii f_old : r1[i]){
            for(int j = 0; j < sz(r2[i]); j++){
                pii s_old = r2[i][j];
                mb_f.clear(), mb_s.clear();
                if(f_old.fi + 1 <= n)mb_f.p_b({f_old.fi + 1, f_old.se});
                if(f_old.se + 1 <= m)mb_f.p_b({f_old.fi, f_old.se + 1});
                if(s_old.fi - 1 > 0)mb_s.p_b({s_old.fi - 1, s_old.se});
                if(s_old.se - 1 > 0)mb_s.p_b({s_old.fi, s_old.se - 1});
                for(pii f_new : mb_f)
                for(pii s_new : mb_s)if(a[f_new.fi][f_new.se] == a[s_new.fi][s_new.se]){
                    (dp[f_new.fi][f_new.se][pos[s_new.fi][s_new.se]] += dp[f_old.fi][f_old.se][j]) %= mod;
                }
            }
            dp[f_old.fi][f_old.se].clear();
        }
    }

    ll ans = 0;

    if(Rust & 1){
        for(auto i : r1[Rust / 2])(ans += dp[i.fi][i.se][pos[i.fi][i.se]]) %= mod;
    }else{
        for(auto i : r1[Rust / 2 - 1])
            for(auto j : r2[Rust / 2 - 1])if(abs(i.fi - j.fi) + abs(i.se - j.se) == 1)(ans += dp[i.fi][i.se][pos[j.fi][j.se]]) %= mod;
    }

    cout << ans << "\n";

    return 0;
}