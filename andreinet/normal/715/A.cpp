#include <algorithm>
#include <iostream>
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

    int64_t cval = 2;
    for (int i = 1; i <= n; ++i) {
        int64_t x = (int64_t) i / __gcd(i, i + 1) * (i + 1);
        int64_t v = x / i * x - cval / i;
        cout << v << '\n';
        cval = x;
    }
}