#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
 
using namespace std;

#define M 500
#define mod 1000000007

int n, m, x;
long long d[M][M], h[M][M];

void read() {
    cin >> n >> m >> x;
}

long long din() {
    
    if (n > m)
        return 0;

    d[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) 
            for (int c = 0; c <= n; ++c) {
                h[j][c + 1] += d[j][c];
                h[j + 1][c + 1] += d[j][c];
                if (i + 1 != x) {
                    h[j][c] += d[j][c];
                    if (j > 0)
                        h[j - 1][c] += d[j][c];
                }
            }

        for (int j = 0; j <= n; ++j)
            for (int c = 0; c <= n; ++c) {
                d[j][c] = h[j][c] % mod;
                h[j][c] = 0;
            }
    }

    return d[0][n];
}

void kill() {
    long long ans = din();
    for (int i = 1; i <= n; ++i)
        ans = (ans * i) % mod;
    cout << ans << "\n";
}
 
int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    read();

    kill();

    return 0;
}