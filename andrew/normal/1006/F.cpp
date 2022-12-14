#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

unordered_map <ll, ll> dp[21][21];

ll a[21][21], n, m;

void go(ll x, ll y, ll mask){
    if(x > n || y > m)return;
    mask ^= a[x][y];
    if(y == m - x + 1){
        dp[x][y][mask]++;
        return;
    }
    go(x + 1, y, mask);
    go(x, y + 1, mask);
}
ll k;

ll ans(ll x, ll y, ll mask){
    if(x < 1 || y < 1)return 0;
    if(m - x + 1 == y)return dp[x][y][mask];
    return ans(x - 1, y, mask ^ a[x][y]) + ans(x, y - 1, mask ^ a[x][y]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)cin >> a[i][j];
    go(1, 1, 0);
    return cout << ans(n, m, k) << "\n", 0;
}