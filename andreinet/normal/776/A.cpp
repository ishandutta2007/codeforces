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

    string a, b;
    cin >> a >> b;
    cout << a << ' ' << b << '\n';
    int q;
    cin >> q;
    while (q-- > 0) {
        string x, y;
        cin >> x >> y;
        if (x == a) {
            a = y;
        } else {
            b = y;
        }
        cout << a << ' ' << b << '\n';
    }
}