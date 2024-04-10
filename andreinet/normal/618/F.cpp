#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 1000005;

int64_t A[NMAX], B[NMAX];
int pos[NMAX], lastPos[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        A[i] += A[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> B[i];
        B[i] += B[i - 1];
    }
    memset(lastPos, -1, sizeof lastPos);
    lastPos[0] = 0;

    for (int i = 1, j = 0; i <= n; ++i) {
        while (j < n && B[j + 1] <= A[i]) {
            ++j;
        }
        pos[i] = j;
        int diff = A[i] - B[j];
        if (lastPos[diff] != -1) {
            int i1 = lastPos[diff];
            int j1 = pos[i1];
            cout << i - i1 << '\n';
            for (int k = i1 + 1; k <= i; ++k) {
                cout << k << ' ';
            }
            cout << '\n' << j - j1 << '\n';
            for (int k = j1 + 1; k <= j; ++k) {
                cout << k << ' ';
            }
            cout << '\n';
            return 0;
        } else {
            lastPos[diff] = i;
        }
    }

    return -8910;
}