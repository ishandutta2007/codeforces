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

    int n, m, k;
    cin >> n >> m >> k;

    int lane = (k - 1) / (2 * m) + 1;
    int desk = (k - 1) % (2 * m) + 1;
    desk = (desk - 1) / 2 + 1;
    char d = (k % 2 == 0) ? 'R': 'L';

    cout << lane << ' ' << desk << ' ' << d << '\n';
}