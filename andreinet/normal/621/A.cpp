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

    int n;
    cin >> n;

    int cmin = 0x3f3f3f3f;
    int64_t sum = 0;
    while (n-- > 0) {
        int x;
        cin >> x;
        sum += x;
        if (x % 2 == 1) {
            cmin = min(cmin, x);
        }
    }
    if (sum % 2 == 1) {
        sum -= cmin;
    }
    cout << sum << '\n';
}