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

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        A[i]--;
    }

    vector<bool> used(n, false);
    vector<bool> auxUsed(n, false);
    vector<int> when(n, 0);

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == i) {
            root = i;
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int time = 0, j;
            for (j = i; !auxUsed[j]; j = A[j]) {
                when[j] = time++;
                auxUsed[j] = true;
            }
            int changed = -1;
            if (!used[j]) {
                int cycleSize = time - when[j];
                if (root != -1) {
                    if (A[j] != root) {
                        changed = j;
                        ans++;
                    }
                } else {
                    if (cycleSize > 1) {
                        changed = j;
                        ans++;
                    }
                    root = j;
                }
            }
            for (j = i; !used[j]; j = A[j]) {
                used[j] = true;
            }
            if (changed != -1) {
                A[changed] = root;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << A[i] + 1 << ' ';
    }
    cout << '\n';
    

}