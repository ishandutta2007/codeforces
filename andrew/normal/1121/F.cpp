#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x) * (x)
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;

const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll dp[MAXN];

int z[5001][5001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s = "0" + s;

    for(int i = 1; i <= n; i++){
        z[i][i] = 1e9;
        for(int j = i + 1, l = i, r = i; j <= n; j++){
            if(j <= r)z[i][j] = min(z[i][j - l + i], r - j + 1);
            while(j + z[i][j] <= n && s[i + z[i][j]] == s[j + z[i][j]])z[i][j]++;
            if(j + z[i][j] - 1 > r){l = j, r = j + z[i][j] - 1;}
        }
    }
    for(int i = 1; i <= n; i++)dp[i] = 1e18;

    for(int i = 1; i <= n; i++){
        dp[i] = min(dp[i], dp[i - 1] + a);
        int mx = 0;
        for(int j = 1; j < i; j++)mx = max(mx, min(z[j][i], i - j));

        for(int j = i; j <= min(n, ll(i + mx - 1)); j++)dp[j] = min(dp[j], dp[i - 1] + b);

    }
    cout << dp[n] << "\n";
    return 0;
}