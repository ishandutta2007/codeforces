#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

inline int64_t sign(int64_t x) {
    return x < 0 ? -1: 1;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int64_t x;
    cin >> n >> k >> x;

    vector<int64_t> A(n);
    for (int64_t& p: A) {
        cin >> p;
    }
    vector<int64_t> mul(n);
    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] >= 0) {
            mul[i] = 1;
        } else if (prev == -1) {
            prev = i;
            mul[i] = 1;
        } else {
            mul[i] = -1;
            mul[prev] = -1;
            A[i] *= -1;
            A[prev] *= -1;
            prev = -1;
        }
    }
    if (*min_element(A.begin(), A.end()) - k * x >= 0) {
        int p = min_element(A.begin(), A.end()) - A.begin();
        A[p] -= k * x;
    } else {
        int p = min_element(A.begin(), A.end()) - A.begin();
        int cnt = A[p] / x;
        if (A[p] < 0) {
            cnt = 0;
        }
        A[p] -= cnt * x;
        k -= cnt;
        if (A[p] >= 0) {
            A[p] -= x;
            k--;
        }
        priority_queue<pair<int64_t, int>> h;
        for (int i = 0; i < n; ++i) {
            h.push(make_pair(-(A[i] * sign(A[i])), i));
        }
        while (k-- > 0) {
            int pos = h.top().second;
            h.pop();
            A[pos] += x * sign(A[pos]);
            h.push(make_pair(-(A[pos] * sign(A[pos])), pos));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << A[i] * mul[i] << ' ';
    }
    cout << '\n';
}