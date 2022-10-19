#include <bits/stdc++.h>


using namespace std;

#define y1 ladsafkl
#define y2 slkdfaslkfjla

typedef long double ld;

ld x1, y1, x2, y2, vmax, t;
ld xp, yp;
ld vx, vy, wx, wy;


void getPos(ld tim) {
    if (tim < t) {
        xp = x2 - tim * vx;
        yp = y2 - tim * vy;
        return;
    }
    xp = x2 - t * vx - (tim - t) * wx;
    yp = y2 - t * vy - (tim - t) * wy;
}


ld dist() {
    return (xp - x1) * (xp - x1) + (yp - y1) * (yp - y1);
}

void bin() {
    ld l = 0, r = 1e10, m;
    for (int i = 0; i < 300; ++i) {
        m = (l + r) / 2;
        getPos(m);
        if (dist() <= m * m * vmax * vmax)
            r = m;
        else
            l = m;
    }
    cout << l << endl;
}

ld solve(ld vx, ld vy) {
    ld dx = x2 - x1;
    ld dy = y2 - y1;

    ld A = dx * dx + dy * dy;
    ld B = -2 * (vx * dx + vy * dy);
    ld C = vx * vx + vy * vy - vmax * vmax;

    ld D = B * B - 4 * A * C;
    assert(D >= 0);

    ld a = (-B + sqrt(D)) / (2 * A);

    assert(a > 0);

    ld sx = a * dx, sy = a * dy;

    return 1 / a;
        
}
void read() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy >> wx >> wy;
}

void kill() {
    ld ans1 = solve(vx, vy);
    if (ans1 <= t) {
        //cerr << "first\n";
        cout << ans1 << endl;
        return;
    }
    
    x2 -= t * vx;
    y2 -= t * vy;
    x2 += t * wx;
    x2 += t * wy;

    ld ans2 = solve(wx, wy);
    ans2 = max(ans2, t);

    cout << ans2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(9);
    cout << fixed;

    read();
    bin();
    return 0;
}