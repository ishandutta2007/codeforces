#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAXN = 1000;
int x[MAXN + 1], y[MAXN + 1];

ll dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * ((ll)x1 - x2) + ((ll)y1 - y2) * (y1 - y2);
}

ll mul(int x1, int y1, int x2, int y2) {
    return (ll)x1 * y2 - (ll)x2 * y1;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    long double l = 0, r = 2e9 + 500, d;
    for(int t = 0; t < 70; t++) {
        d = (l + r) / 2.0;
        bool ok = true;
        for(int i = 0; i < n && ok; i++) {
            for(int j = i + 1; j < n && ok; j++) {
                if(dist(x[i], y[i], x[j], y[j]) < 4 * d * d) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            for(int i = 0; i < n; i++) {
                int j = (i + 1) % n;
                int k = (i + 2) % n;
                ll S = abs(mul(x[k] - x[j], y[k] - y[j], x[i] - x[j], y[i] - y[j]));
                ld h = S / (ld)sqrt(dist(x[i], y[i], x[k], y[k]));
                if(2 * d > h) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok)
            l = d;
        else
            r = d;
    }
    cout << fixed << setprecision(15) << (double)l << "\n";
    return 0;
}