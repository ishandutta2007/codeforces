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

    string A, B;
    cin >> A >> B;
    int n = SZ(A), m = SZ(B);

    int pos = -1;
    vector<int> left(m), right(m);
    for (int i = 0; i < m; ++i) {
        ++pos;
        while (pos < n && B[i] != A[pos]) {
            ++pos;
        }
        pos = min(pos, n);
        left[i] = pos;
    }
    if (left[m - 1] < n) {
        cout << B << '\n';
        return 0;
    }
    pos = n;
    int ans = m, begin = -1, end = -1;
    for (int i = m - 1; i >= 0; --i) {
        --pos;
        while (pos >= 0 && B[i] != A[pos]) {
            --pos;
        }
        pos = max(pos, -1);
        right[i] = pos;
        if (right[i] >= 0) {
            ans = i;
            begin = 0;
            end = i;
        }
    }
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < m && right[j] <= left[i]) {
            ++j;
        }
        if (left[i] < n) {
            if (j - i - 1 < ans) {
                ans = j - i - 1;
                begin = i + 1;
                end = j;
            }
        }
    }
    if (ans < m) {
        string fans;
        if (begin > 0) {
            fans += string(B.begin(), B.begin() + begin);
        }
        if (end < m) {
            fans += string(B.begin() + end, B.end());
        }
        cout << fans << '\n';
    } else {
        cout << "-\n";
    }
}