#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

pair<int, int> A[NMAX];
int64_t sum[NMAX];

int fans[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, B, cf, cm;
    cin >> n >> B >> cf >> cm;
    int64_t m;
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i].first;
        A[i].second = i;
        fans[i] = A[i].first;
    }
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + A[i].first;
    }

    int64_t ans = -1;
    int ansi = 0, ansj = 0, ansMinVal = 0;
    int64_t current = 0;
    for (int i = n + 1, j = n; i > 0; --i) {
        if (i <= n) {
            current += B - A[i].first;
        }
        if (current > m) break;
        while (j > 0) {
            int64_t total = (int64_t) A[j].first * j - sum[j];
            if (j >= i || total > m - current) {
                j--;
            } else {
                break;
            }
        }
        int64_t rem = m - current - ((int64_t) A[j].first * j - sum[j]);
        int minVal;
        if (j > 0) {
            minVal = min((int64_t) B, A[j].first + rem / j);
        } else {
            minVal = B;
        }

        int64_t c = (int64_t) cf * (n + 1 - i) + (int64_t) cm * minVal;
        if (c > ans) {
            ans = c;
            ansi = i;
            ansj = j;
            ansMinVal = minVal;
        }
    }

    for (int i = n; i >= ansi; --i) {
        fans[A[i].second] = B;
    }
    for (int i = 1; i <= ansj && A[i].first < ansMinVal; ++i) {
        fans[A[i].second] = ansMinVal;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << fans[i] << ' ';
    }
    cout << '\n';
}