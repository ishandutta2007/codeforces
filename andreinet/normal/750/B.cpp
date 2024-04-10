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

    int a = 20000;

    int n;
    cin >> n;

    int x = 0;
    while (n-- > 0) {
        int add;
        string dir;
        cin >> add >> dir;

        if (dir == "North") {
            x -= add;
            if (x < 0) {
                cout << "NO\n";
                return 0;
            }
        } else if (dir == "South") {
            x += add;
            if (x > a) {
                cout << "NO\n";
                return 0;
            }
        } else if (x == 0 || x == a) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << (x == 0 ? "YES\n": "NO\n");
}