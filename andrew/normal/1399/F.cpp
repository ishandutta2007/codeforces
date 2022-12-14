#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

short dp[6001][6001], dp1[6001], dp2[3005][6001];

short pos[N + 2];

void solve(){
    int n;
    cin >> n;
    vector <pii> a(n);
    set <int> order;
    for(auto &i : a){
        cin >> i.fi >> i.se;
        order.insert(i.fi);
        order.insert(i.se);
    }
    for(int i = 1; i <= 2 * n; i++)
        for(int j = 1; j <= 2 * n; j++)dp[i][j] = 0;

    for(int i = 1; i <= n + 3; i++)
        for(int j = 1; j <= 2 * n; j++)dp2[i][j] = 0;

    for(int i = 1; i <= 2 * n; i++)dp1[i] = 0;
    int stn = 0;
    for(auto i : order){
        stn++;
        pos[i] = stn;
    }
    for(auto &i : a){
        i.fi = pos[i.fi];
        i.se = pos[i.se];
        i.se *= -1;
    }
    sort(all(a));
    short ans = 0;
    short one = 1;
    for(int step = sz(a) - 1; step >= 0; step--){
        int l = a[step].fi, r = -a[step].se;
        dp[l][r] = 1;
        for(int i = 1; i <= 2 * n; i++)dp2[step + 1][i] = dp2[step + 2][i];
        int uk = step;
        for(int j = l; j < r; j++){
            while(uk < sz(a) && a[uk].fi <= j)uk++;
            if(uk < sz(a))dp[l][r] = max(dp[l][r], short(dp1[j] + dp2[uk + 1][r] + one));
            dp[l][r] = max(dp[l][r], short(dp1[j] + one));
        }
        while(uk < sz(a) && a[uk].fi <= r)uk++;
        if(uk < sz(a)){
            for(int i = r + 1; i <= 2 * n; i++){
                ans = max(ans, short(dp[l][r] + dp2[uk + 1][i]));
                dp1[i] = max(dp1[i], short(dp[l][r] + dp2[uk + 1][i]));
                dp2[step + 1][i] = max(dp2[step + 1][i], short(dp[l][r] + dp2[uk + 1][i]));
            }
        }
        dp1[r] = max(dp1[r], dp[l][r]);
        for(int j = r + 1; j <= 2 * n; j++){
            dp1[j] = max(dp1[j], dp1[j - 1]);
        }
        dp2[step + 1][r] = max(dp2[step + 1][r], dp[l][r]);
        for(int j = 2; j <= 2 * n; j++){
            dp2[step + 1][j] = max(dp2[step + 1][j], dp2[step + 1][j - 1]);
        }
        ans = max(ans, dp[l][r]);
    }
    cout << ans << "\n";
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    cin >> t;
    while(t--)solve();

    return 0;
}