#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int dp[maxn];
int n;
int sum[maxn];
int u[maxn];
int p[maxn];

void solve() {
    cin >> n;
    for(int i = 3; i <= n; i++) {
        for(int k = 2; k * (k + 1)/2 <= i; k++) {
            if((2 * i) % k != 0) continue;
            int l = 2 * i/k - k + 1;
            if(l % 2 != 0) continue;
            l/=2;
            int r = l + k - 1;
            u[sum[r]^sum[l-1]] = i;
            if((sum[l-1]^sum[r]) == 0 && p[i] == 0) p[i] = k;
        }
        while(u[dp[i]]==i) dp[i]++;
        sum[i] = sum[i-1] ^ dp[i];
    }
    if(dp[n] == 0) {
        cout << -1 << "\n";
        return;
    }
    cout << p[n] << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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