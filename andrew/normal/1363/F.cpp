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
const ll MAXN = 1123456;
const ll N = 2e5 + 2;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll pref[5001][26];
ll pref1[5001][26];

ll dp[2020][2020];

void u(ll &a, ll b){
    a = min(a, b);
}

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));
    if(a == b)fout(0);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            pref[i][j] = pref[i - 1][j];
            pref1[i][j] = pref1[i - 1][j];
        }
        pref[i][a[i - 1] - 'a']++;
        pref1[i][b[i - 1] - 'a']++;
    }

    for(int i = 0; i < 26; i++)if(pref[n][i] != pref1[n][i])fout(-1);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)dp[i][j] = inf;

    dp[0][0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i < n && j < n && a[i] == b[j])u(dp[i + 1][j + 1], dp[i][j]);
            if(i < n)u(dp[i + 1][j], dp[i][j]);
            if(j < n){
                if(pref[i][b[j] - 'a'] > pref1[j][b[j] - 'a'])u(dp[i][j + 1], dp[i][j] + 1);
            }
        }
    }

    cout << dp[n][n] << "\n";

}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll t;
    cin >> t;
    while(t--)solve();

    return 0;
}