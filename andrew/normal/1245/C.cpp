#include <bits/stdc++.h>

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
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    string s;
    cin >> s;

    ll n = s.size();

    vector <ll> dp(n + 3);

    dp[0] = 1;

    s = "+" + s;

    for(int i = 1; i <= n; i++){
        if(s[i] != 'm' && s[i] != 'w')dp[i] = dp[i - 1];
        if(i > 1 && ((s[i] == 'n' && s[i - 1] == 'n') || (s[i] == 'u' && s[i - 1] == 'u')))(dp[i] += dp[i - 2]) %= mod;
    }

    cout << dp[n] << "\n";

    return 0;
}