#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 20;

double p[N], f[1 << N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == 1) {
            for (int j = 0; j < n; j++) cout << p[j] << ' ';
            return 0;
        }
    }
    for (int i = 0; i < (1 << n) - 1; i++) {
        double po = 0;
        for (int j = 0; j < n; j++) {
            if (bit(i, j) == 1) po += p[j];
        }
        if (po == 1) f[i] = 0;
        else f[i] = 1.0 / (1.0 - po);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (bit(j, i) == 1) {
                f[j] -= f[j ^ (1 << i)];
            }
        }
    }
    cout << setprecision(10) << fixed;
    for (int i = 0; i < n; i++) {
        double res = 0;
        for (int j = 0; j < (1 << n); j++) {
            if (bit(j, i) == 0 && __builtin_popcount(j) < k) {
                res += p[i] * f[j];
            }
        }
        cout << res << ' ';
    }
    return 0;
}