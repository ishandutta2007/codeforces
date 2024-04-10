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

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        int x, y, useless1, useless2;
        cin >> x >> y >> useless1 >> useless2;
        cout << 1 + ((x & 1) + ((y & 1) << 1)) << '\n';
    }
}