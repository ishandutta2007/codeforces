#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int64_t solve(int64_t n) {
    if (n <= 1) return 0;
    int pos = 0;
    while ((1LL << pos + 1) <= n) ++pos;

    int64_t ret = (pos - 1) * pos / 2, cnt = 0;
    for (int i = pos - 1; i >= 0; --i) {
        if ((n & (1LL << i)) && cnt == 0) {
            ret++;
        } 
        if ((n & (1LL << i)) == 0) cnt++;
    }
    if (cnt == 1) ret++;

    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int64_t left, right;
    cin >> left >> right;

    cout << solve(right) - solve(left - 1) << '\n';
}