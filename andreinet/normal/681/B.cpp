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

    const int a = 1234567;
    const int b = 123456;
    const int c = 1234;
    int n;
    cin >> n;

    for (int i = 0; i * a <= n; ++i) {
        for (int j = 0; i * a + j * b <= n; ++j) {
            if ((n - i * a - j * b) % c == 0) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}