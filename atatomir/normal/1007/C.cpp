#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define x1 xx1
#define y1 yy1
#define x2 xx2
#define y2 yy2

ll n, i, j;
ll x1, x2, y1, y2, xx, yy;

ll ask(ll x, ll y) {
    x = n - x + 1;
    y = n - y + 1;
    
    printf("%I64d %I64d\n", x, y);
    fflush(stdout);
    scanf("%I64d", &x);
    if (x == 0) exit(0);
    return x;
}

ll get_val(ll x, ll y, ll px, ll py) {
    ll ans, ans2;
    ll i;

    ans = ans2 = 0;
    for (i = 1; i <= px; i++) {
        ans += x / (px + py);
        ans2 += x % (px + py); 
    }
    for (i = 1; i <= py; i++) {
        ans += y / (px + py);
        ans2 += y % (px + py); 
    }

    return ans + (ans2 / (px + py));
}

void solve() {
    ll a, b, w, h;
    ll qx, qy;
    ll ans;

    if (xx < x1) {
        qx = get_val(xx + 1, x2, 1, 1);
        qy = get_val(yy + 1, y2, 1, 1);
    } else {
        a = x2 - x1 + 1;
        b = y2 - y1 + 1;
        h = yy - y1 + 1;
        w = xx - x1 + 1;

        if (1.00 * b * w > 1.00 * a * h) {
            qx = xx + 1;
            qy = get_val(yy + 1, y2, 1, 1);
        } else {
            qx = get_val(xx + 1, x2, 1, 1);
            qy = yy + 1;
        }
    }
    
    ans = ask(qx, qy);

    if (ans == 1) x2 = qx - 1;
    if (ans == 2) y2 = qy - 1;
    if (ans == 3) {
        xx = qx;
        yy = qy;
    }

    if (xx >= x2) {
        y1 = yy + 1;
        xx = x1 - 1;
        yy = y1 - 1;
    }

    if (yy >= y2) {
        x1 = xx + 1;
        xx = x1 - 1;
        yy = y1 - 1;
    }

    //cerr << x1 << ' ' << x2 << '\n';
    //cerr << y1 << ' ' << y2 << '\n';
    //cerr << xx << ' ' << yy << '\n';
    //cerr << '\n';

    //printf("%lld%lld ", x1, y1);
    //printf("%lld%lld ", x2, y2);
    //printf("%lld%lld\n", xx, yy);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%I64d", &n);
    x1 = y1 = 1;
    x2 = y2 = n;
    xx = yy = 0;

    for (int cnt = 60000; cnt > 0; cnt--) solve();

    //printf("%lld%lld%lld%lld%lld%lld", x1, y1, x2, y2, xx, yy);

    return 0;
}