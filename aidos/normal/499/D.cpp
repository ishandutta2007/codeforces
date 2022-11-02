#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
double dp[5050];
double d[5050];
int n, T;
double pref[5050];
void solve() {
    dp[0] = 1;
    cin >> n >> T;
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        int P, t;
        cin >> P >> t;
        double p = P/100.0;
        double q = 1-p;
        double x = 1;
        for(int j = 1; j < t; j++) x *= q;
        for(int j = 0; j <= T; j++) {
            d[j] = dp[j];
            dp[j] = 0;
        }
        double s = 0;
        for(int j = 1; j <= T; j++) {
            s = s * q + d[j-1] * p;
            if(j >= t) {
                s -= x * d[j - t] * p;
                dp[j] = d[j-t]* x + s;
            } else {
                dp[j]=s;
            }
            ans += dp[j];
        }
    }
    printf("%.12lf\n", ans);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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