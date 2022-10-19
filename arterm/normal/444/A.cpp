#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define M 507
#define long long long 

long n, w[M][M], m, x[M];
long u[M][M];
long a = 0, b = 0;

void bet(long x, long y) {
    if (x == 0 || y == 0)
        return;
    if (a * y <= b * x) {
        a = x;
        b = y;
    }
}

void read() {
    cin >> n >> m;
    for (long i = 1; i <= n; ++i)
        cin >> x[i];
    for (long i = 0, x, y, z; i < m; ++i) {
        cin >> x >> y >> z;
        w[x][y] = w[y][x] = z;
        u[x][y] = u[y][x] = 1;
    }

}

void kill() {
    
    for (long i = 1; i <= n; ++i)
        for (long j = i + 1; j <= n; ++j)
            if (u[i][j])
                bet(x[i] + x[j], w[i][j]);

    for (long i = 1; i <= n; ++i)
        for (long j = i + 1; j <= n; ++j)
            for (long k = j + 1; k <= n; ++k)
                if (u[i][j] + u[j][k] + u[k][i] >= 2)
                    bet(x[i] + x[j] + x[k], w[i][j] + w[j][k] + w[k][i]);

    cout.precision(13);
    cout << fixed;

    if (b == 0)
        cout << 0.0 << "\n";
    else
        cout << 1.0 * a / b << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    kill();

    return 0;
}