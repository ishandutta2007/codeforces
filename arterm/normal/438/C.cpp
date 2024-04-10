#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define long long long
#define M 239
#define mod 1000000007ll

int n;
long x[M], y[M], d[M][M];
bool p[M][M];

long crs(long x1, long y1, long x2, long y2) {
    return x1 * y2 - x2 * y1;
}

void read(void){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    x[n] = x[0];
    y[n] = y[0];

    long area = 0;
    for (int k = 0; k < n; ++k)
        area += crs(x[k], y[k], x[k + 1], y[k + 1]);

    if (area < 0) {
        reverse(x, x + n + 1);
        reverse(y, y + n + 1);
    }
}

void din() {
    for (int t = 1; t < n; ++t)
        for (int i = 0; i + t <= n; ++i) {
            int j = i + t;
            if (t == 1)
                d[i][j] = 1;
            else
                for (int k = i; k <= j; ++k)
                    if (crs(x[i] - x[k], y[i] - y[k], x[j] - x[k], y[j] - y[k]) < 0)
                        d[i][j] = (d[i][j] + d[i][k] * d[k][j]) % mod;
        }

    cout << d[0][n - 1] << "\n";
}



int main(){
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    din();

    return 0;
}