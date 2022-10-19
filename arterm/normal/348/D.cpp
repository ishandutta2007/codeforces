#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
 
using namespace std;

#define M 3030
#define mod 1000000007ll
#define long long long

int n, m, d[M][M];
bool h[M][M];

void read() {
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> ch;
            h[i][j] = (ch == '.');
        }
}

long ways(int xs, int ys, int xf, int yf) {
    if (xs > xf || ys > yf)
        return 0;
    for (int i = xs; i <= xf; ++i)
        for (int j = ys; j <= yf; ++j) {
            d[i][j] = 0;
            if (!h[i][j])
                continue;
            if (i == xs && j == ys) {
                d[i][j] = 1;
            } else {
                if (i > xs)
                    d[i][j] += d[i - 1][j];
                if (j > ys)
                    d[i][j] += d[i][j - 1];
                if (d[i][j] >= mod)
                    d[i][j] -= mod;
            }
        }   
    return d[xf][yf];
}


 
int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    read();

    long ans = ways(1, 2, n - 1, m) * ways(2, 1, n, m - 1) - ways(1, 2, n, m - 1) * ways(2, 1, n - 1, m);
    ans %= mod;
    if (ans < 0)
        ans += mod;
    cout << ans << "\n";

    return 0;
}