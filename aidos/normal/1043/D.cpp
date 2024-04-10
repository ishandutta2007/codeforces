#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[10][maxn];
int bad[maxn];
int nxt[maxn];
ll dp[maxn];
void solve() {
    cin >> n >> m;
    for(int j = 0; j < m; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[j][i];
        }
    }
    if(m == 1) {
        cout << n * (n + 1ll)/2 << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        nxt[a[0][i]] = a[0][i + 1];
    }
    for(int j = 0; j < m; j++) {
        for(int i = 1; i <= n; i++) {
            if(nxt[a[j][i]] != a[j][i + 1]) bad[a[j][i]] = 1;
        }
    }
    bad[a[0][n]] = 1;
    for(int i = n; i >= 1; i--) {
        if(bad[a[0][i]]) dp[i] = 1;
        else dp[i] = dp[i+1] + 1;
    }
    cout << accumulate(dp + 1, dp + n + 1, 0ll) << "\n";
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