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

    if (n % 2 == 0) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            cout << 2 * i % n << ' ';
        }
        cout << '\n';
    }
}