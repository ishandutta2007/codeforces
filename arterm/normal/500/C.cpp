#include <bits/stdc++.h>

using namespace std;

#define M 1007

int n, m, w[M], b[M], ans = 0;
bool used[M];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        fill(used, used + (n + 1), false);
        for (int j = i - 1; j >= 1; --j)
            if (b[j] != b[i]) {
                if (!used[b[j]]) {
                    ans += w[b[j]];
                    used[b[j]] = true;
                }
            } else {
                break;
            }
    }
    cout << ans << "\n";
    return 0;
}