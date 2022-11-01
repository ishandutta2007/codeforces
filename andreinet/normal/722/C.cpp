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
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    vector<int> xleft(n + 2, -1);
    vector<int> xright(n + 2, -1);
    vector<int64_t> sum(n + 2, 0);

    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
    }

    vector<int64_t> ans(n);
    int64_t vmax = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = vmax;
        int pos = P[i];
        xleft[pos] = xright[pos] = pos;
        int64_t csum = A[pos];
        if (xright[pos + 1] != -1) {
            csum += sum[pos + 1];
            xleft[xright[pos + 1]] = pos;
            xright[pos] = xright[pos + 1];
        }
        if (xleft[pos - 1] != -1) {
            csum += sum[pos - 1];
            xright[xleft[pos - 1]] = xright[pos];
            xleft[xright[pos]] = xleft[pos - 1];
            xleft[pos] = xleft[pos - 1];
        }
        sum[xright[pos]] = sum[xleft[pos]] = csum;
        vmax = max(vmax, csum);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}