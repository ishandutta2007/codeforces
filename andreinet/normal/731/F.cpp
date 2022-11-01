#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    const int VMAX = 400005;
    vector<int> count(VMAX + 1, 0);
    int vmax = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        count[x]++;
        vmax = max(x, vmax);
    }
    for (int i = 1; i <= VMAX; ++i) {
        count[i] += count[i - 1];
    }
    int64_t ans = 0;
    for (int i = 1; i <= vmax; ++i) {
        if (count[i] - count[i - 1] == 0) {
            continue;
        }
        int64_t sum = 0;
        for (int j = i + i; j <= VMAX; j += i) {
            sum += (int64_t) (count[j - 1] - count[j - i - 1]) * (j - i);
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}