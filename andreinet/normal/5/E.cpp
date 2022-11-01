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

    vector<int> A(3 * n), countEq(2 * n), left(2 * n);
    int cmax = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        cmax = max(cmax, A[i]);
    }

    for (int i = n; i < 3 * n; ++i) {
        A[i] = A[i - n];
    }

    int64_t ans = 0;
    vector<int> stk;
    for (int i = 0; i < 2 * n; ++i) {
        countEq[i] = 1;
        while (!stk.empty() && A[stk.back()] <= A[i]) {
            if (A[stk.back()] == A[i]) {
                countEq[i] += countEq[stk.back()];
            }
            stk.pop_back();
        }
        if (n <= i && A[i] != cmax) {
            left[i] = stk.back();
            ans += countEq[i];
        }
        stk.push_back(i);
    }
    stk.clear();
    for (int i = 3 * n - 1; i >= n; --i) {
        while (!stk.empty() && A[stk.back()] <= A[i]) {
            stk.pop_back();
        }
        if (i < 2 * n && A[i] != cmax) {
            int right = stk.back();
            if (right % n != left[i] % n) {
                ans++;
            }
        }
        stk.push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += A[i] == cmax;
    }

    ans += (int64_t) cnt * (cnt - 1) / 2;

    cout << ans << '\n';
}