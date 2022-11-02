#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
ll dp[maxn];
ll binpow(ll x, int y) {
    ll res = 1;
    while(y>0) {
        if(y&1) {
            res = (res*x) % mod;
        }
        y >>= 1;

        x = x * x% mod;
    }
    return res;
}
void solve() {
    cin >> n >> m;
    if(m % n != 0) {
        cout << 0 << "\n";
        return;
    }
    m /= n;
    vector<int> a;
    for(int i = 1; i * i <= m; i++) {
        if(m % i == 0) {
            a.emplace_back(i);
            if(i != m/i) a.emplace_back(m/i);
        }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        dp[i] = binpow(2, m/a[i]-1);
        for(int j = 0; j < i; j++) {
            if(a[j] % a[i] == 0) dp[i] = (dp[i] + mod - dp[j]) % mod;
        }
    }
    cout << dp[a.size() - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}