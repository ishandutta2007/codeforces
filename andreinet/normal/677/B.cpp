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

    int64_t n, h, k;
    cin >> n >> h >> k;

    int64_t ans = 0;
    int64_t lastp = 0;
    for (int i = 1; i <= n; ++i) {
        int64_t x;
        cin >> x;
        int64_t diff = h - lastp;
        if (x <= diff) {
            lastp += x;
        } else {
            diff = x - diff;
            int64_t p = (diff + k - 1) / k;
            ans += p;
            lastp -= p * k;
            if (lastp < 0) {
                lastp = 0;
            }
            lastp += x;
        }
    }
    ans += (lastp + k - 1) / k;

    cout << ans << '\n';
    
}