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

    int prev = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (prev == 1) {
            if (x == 0) {
                cout << "NO\n";
                return 0;
            } else {
                x--;
            }
        }
        x &= 1;
        prev = x;
    }

    cout << (prev ? "NO\n": "YES\n");
}