#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int dx[] = {-1, -2, -1, 1, 2, 1};
int dy[] = {2, 0, -2, -2, 0, 2};

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int64_t n;
    cin >> n;

    if (n == 0) {
        cout << "0 0\n";
        return 0;
    }

    int64_t rsteps = 0;
    for (int64_t step = 1LL << 30; step > 0; step /= 2) {
        int64_t csteps = rsteps + step;
        
        int64_t total = csteps * (csteps + 1) * 3;
        if (total < n) {
            rsteps = csteps;
        }
    }
    //cerr << rsteps << '\n';

    int64_t cx = rsteps * 2, cy = 0;
    n -= rsteps * (rsteps + 1) * 3;

    rsteps++;
    cx += dx[5]; cy += dy[5];
    n--;

    for (int i = 0; i < 6 && n > 0; ++i) {
        int64_t c = i == 0 ? rsteps - 1: rsteps;
        int64_t x = min(c, n);
        n -= x;
        cx += x * dx[i];
        cy += x * dy[i];
    }

    cout << cx << ' ' << cy << '\n';
}