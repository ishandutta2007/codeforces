#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define SZ(x) ((int) (x).size())
using namespace std;

const int NMAX = 100005;

int main()
{
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // LOCAL_RUN
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    A[0] = -10000;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 20;
        int p1 = upper_bound(A.begin(), A.end(), A[i] - 90) - A.begin();
        dp[i] = min(dp[i], dp[p1 - 1] + 50);
        int p2 = upper_bound(A.begin(), A.end(), A[i] - 1440) - A.begin();
        dp[i] = min(dp[i], dp[p2 - 1] + 120);
        cout << dp[i] - dp[i - 1] << '\n';
    }
}