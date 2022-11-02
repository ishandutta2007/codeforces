#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
ll dp[maxn];
ll st[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    n = 1e5+10;
    st[0] = 1;

    for(int i=1; i <= n; i++) {
        st[i] = st[i-1] * 2 % mod;
    }
    for(int i = n; i >= 1; i--) {
        dp[i] = 1;
        for(int j = i; j <= n; j += i) {
            if(a[j]) {
                dp[i] = (dp[i] * st[a[j]]) % mod;
            }
        }
        dp[i] = (dp[i] + mod - 1) % mod;
        for(int k = 2; k * i <= n; k++) {
            dp[i] = (dp[i] + mod  - dp[i*k]) % mod;
        }
    }
    cout << dp[1] << "\n";
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