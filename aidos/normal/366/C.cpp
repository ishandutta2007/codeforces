#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, k;
int dp[maxn];
int a[maxn];
int b[maxn];
int d[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < maxn; i++)
        dp[i]=-inf;
    dp[maxn/2] = 0;
    for(int i = 0; i < n; i++) {
        int x = a[i] - b[i] * k;
        for(int j = 0; j < maxn; j++) {
            d[j] = dp[j];
        }
        for(int j = 0; j < maxn; j++) {
            if(j + x >= 0 && j + x < maxn)
                dp[j + x] = max(d[j] + a[i], dp[j + x]);
        }
    }
    int val = dp[maxn/2];
    if(val) cout << val << "\n";
    else cout << -1 << "\n";

}

int main() {
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