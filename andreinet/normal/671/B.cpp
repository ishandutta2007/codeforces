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

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    int64_t sum = 0, hmax = 0, hmin = 1LL << 62;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        sum += A[i];
        hmax = max(hmax, (int64_t) A[i]);
        hmin = min(hmin, (int64_t) A[i]);
    }
    
    int64_t hunv = (sum + n - 1) / n;
    int64_t h1 = hmax;
    for (int64_t step = 1LL << 30; step > 0; step /= 2) {
        int64_t currH = h1 - step;
        if (currH < hunv) {
            continue;
        }
        int64_t cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max((int64_t) 0, A[i] - currH);
        }
        if (cnt <= k) {
            h1 = currH;
        }
    }
    hunv = sum / n;
    int64_t h2 = hmin;
    for (int64_t step = 1LL << 30; step > 0; step /= 2) {
        int64_t currH = h2 + step;
        if (currH > hunv) {
            continue;
        }
        int64_t cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max((int64_t) 0, currH - A[i]);
        }
        if (cnt <= k) {
            h2 = currH;
        }
    }

    cout << h1 - h2 << '\n';
}