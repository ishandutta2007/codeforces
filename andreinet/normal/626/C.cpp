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

    int n, m;
    cin >> n >> m;

    int len1 = n * 2;
    int len2 = m * 3;
    int com = min(n / 3, m / 2);

    int ans = max(len1, len2);

    while (com > 0) {
        if (len1 + 2 <= len2 + 3) {
            len1 += 2;
            if (len1 % 3 == 0 && len1 <= len2) {
                com++;
            }
        } else {
            len2 += 3;
            if (len2 % 2 == 0 && len2 <= len1) {
                com++;
            }
        }
        ans = max(len1, len2);
        com--;
    }

    cout << ans << '\n';
}