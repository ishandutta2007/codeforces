#include <bits/stdc++.h>

using namespace std;

#define int long long

int solve(int r, int c, int dr, int dc) {
    if(dr == 0 && dc == 0) {
        return r * c;
    }
    if(dr >= r || dc >= c) {
        return r * c;
    }
    if(r >= 2 * dr || c >= 2 * dc)
        return r * c - (r - dr) * (c - dc);

    // return (r * dc) + (dr * c) + solve(r - dr, c - dc, 2 * dr - r, 2 * dc - c);
    return r * c - solve(r - dr, c - dc, 2 * dr - r, 2 * dc - c);
}

int lgput(int b, int e, int mod) {
    int ret = 1;
    while(e) {
        if(e & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;

        e /= 2;
    }

    return ret;
}

int32_t main() {
    int n, m, k, r, c; cin >> n >> m >> k >> r >> c;

    int ax, bx, ay, by;
    cin >> ax >> ay >> bx >> by;

    int ccrect = solve(r, c, abs(bx - ax), abs(by - ay));
    
    int aria = n * m;
    aria -= 2 * r * c;

    int dr = abs(bx - ax), dc = abs(by - ay);
    if(dr < r && dc < c)
    aria += (r - dr) * (c - dc);

    aria += ccrect;

    cout << lgput(k, aria, 1000 * 1000 * 1000 + 7) << endl;

    return 0;
}