#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 1100100
#define B 22
#define K 55

int n, m;
double din[M];
unsigned long long d[B][M];
string s[K];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    m = s[0].length();
}

void pre() {

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            int mask = 0;
            for (int k = 0; k < m; ++k)
                if (s[i][k] == s[j][k])
                    mask |= (1 << k);

            d[0][mask] |= (1ll << i);
            d[0][mask] |= (1ll << j);
        }

    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < (1 << m); ++j) {
            d[i][j] = d[i - 1][j];
            if (((j >> (i - 1)) & 1) == 0)
                d[i][j] |= d[i - 1][j | (1 << (i - 1))];
        }

}

double get() {
    fill(din, din + (1 << m), 0.0);
    for (int j = (1 << m) - 2; j >= 0; --j) {
        din[j] = 0;
        int x = __builtin_popcountll(d[m][j]);
        int s = 0;
        for (int i = 0; i < m; ++i)
            if (((j >> i) & 1) == 0) {
                din[j] += x + din[j | (1 << i)];
                ++s;
            }
        din[j] /= s;
    }

    return din[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    read();
    pre();
    double ans = 0;

    cout << get() / n << "\n";

    return 0;
}