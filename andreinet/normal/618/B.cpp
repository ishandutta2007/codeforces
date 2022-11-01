#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 55;

int A[NMAX][NMAX];
bool used[NMAX];

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
        int cmax = 0;
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            cmax = max(cmax, x);
        }
        if (!used[cmax]) {
            cout << cmax << ' ';
            used[cmax] = true;
        } else {
            cout << n << ' ';
        }
    }
    cout << '\n';
}