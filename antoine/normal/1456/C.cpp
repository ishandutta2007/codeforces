#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)5e5 + 9;
ll a[MxN + 9];
ll c[MxN + 9];
ll dp[MxN + 9];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; ++i) {
        c[i] = (i-1)/(k+1);
        dp[i] = dp[i-1] + 1LL * a[i] * c[i];
    }

    ll sum = 0, inc_sum = 0, ans = dp[n];
    for(int i = n; i >= 1; --i) {
        if(i == 2) {
            DBG(i);
            DBG(dp[i]);
            DBG(inc_sum);
            DBG(sum);
        }
        ans = max(ans, dp[i] + inc_sum + sum * (c[i] + 1LL));
        inc_sum += sum;
        sum += a[i];
    }


    cout << ans;



    return 0;
}