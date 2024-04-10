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

    string S1, S2;
    cin >> S1 >> S2;

    int n = SZ(S1), m = SZ(S2);
    int ans = 0;
    for (int i = 0; i + m <= n; ++i) {
        if (S1.substr(i, m) == S2) {
            ans++;
            i += m - 1;
        }
    }

    cout << ans << '\n';
}