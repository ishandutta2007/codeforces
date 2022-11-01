#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int VMAX = 10000000;

int64_t cnt[VMAX + 5];
int64_t total[VMAX + 5];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
        total[x]++;
    }

    int64_t sum = 0;
    for (int i = VMAX; i > 0; --i) {
        sum += cnt[i];
        if (sum >= k) {
            cout << i << "\n";
            return 0;
        }
        cnt[i / 2] += total[i];
        total[i / 2] += total[i];
        total[(i + 1) / 2] += total[i];
    }

    cout << "-1\n";
}