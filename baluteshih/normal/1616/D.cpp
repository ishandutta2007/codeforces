#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int dp[50005], arr[50005];
ll sum[50005], x;

bool verify(int i, int t) {
    if (i == t + 1 || t < 0) return 1; 
    return sum[i] - sum[t] >= x * (i - t);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        cin >> x;
        deque<int> dq;
        for (int i = 1; i <= n; ++i) {
            while (!dq.empty() && dp[i - 1] - i + 1 >= dp[dq.back()] - dq.back())
                dq.pop_back();
            dq.pb(i - 1);
            for (int j = 1; j <= 5; ++j)
                if (!verify(i, i - j)) {
                    while (dq.front() <= i - j)
                        dq.pop_front();
                    break;
                }
            dp[i + 1] = max(dp[i], dp[dq.front()] + i - dq.front());
        }
        cout << *max_element(dp + 1, dp + n + 2) << "\n";
    }
}