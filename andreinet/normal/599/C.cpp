#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int ans = 0;
    vector<int> maxs(n + 2), mins(n + 2);
    maxs[0] = 0;
    mins[n + 1] = 0x3f3f3f3f;
    vector<int> A(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    for (int i = 1; i <= n; ++i)
        maxs[i] = max(maxs[i - 1], A[i]);
    for (int i = n; i > 0; --i)
        mins[i] = min(mins[i + 1], A[i]);
    for (int i = 1; i <= n; ++i)
        if (maxs[i] <= mins[i + 1])
            ++ans;

    cout << ans << '\n';
}