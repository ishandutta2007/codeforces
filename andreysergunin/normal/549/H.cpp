#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const double eps = 1e-12;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    double a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    double l = 0, r = 2 * 1e9;
    while (r - l > eps && (r / l > 1 + eps || l / r > 1 + eps))
    {
        double m = (l + r) / 2;
        double pl, pr, ql, qr, rl, rr, sl, sr, xl, xr, yl, yr;
        pl = a - m;
        pr = a + m;
        ql = b - m;
        qr = b + m;
        rl = c - m;
        rr = c + m;
        sl = d - m;
        sr = d + m;
        xl = min(min(pl * sl, pl * sr), min(pr *  sl, pr * sr));
        xr = max(max(pl * sl, pl * sr), max(pr *  sl, pr * sr));

        yl = min(min(ql * rl, ql * rr), min(qr *  rl, qr * rr));
        yr = max(max(ql * rl, ql * rr), max(qr *  rl, qr * rr));

        if (xl > yr || yl > xr)
            l = m;
        else
            r = m;
    }
    printf("%.10lf\n", l);
    return 0;
}