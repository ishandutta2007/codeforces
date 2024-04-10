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

#define maxN 100011
#define inf 3234567890123456789LL

struct Point {
    ll x, y, z;

    void read() {
        scanf("%lld%lld%lld", &x, &y, &z);
    }
};



int t, ti;
int n, i;
Point P[maxN];
ll l, r;

ll a1, a2, b1, b2, c1, c2, d1, d2;
ll xsol, ysol, zsol;



bool valid(int par) {
    ll a, b, c, d;
    ll need;

    a = a1; b = b1; c = c1;
    if (abs(a) % 2 != par) a++;
    if (abs(b) % 2 != par) b++;
    if (abs(c) % 2 != par) c++;

    if (a > a2 || b > b2 || c > c2) return false;
    if (a + b + c > d2) return false;

    if (a + b + c < d1) {
        need = min(a2 - a, d1 - a - b - c) / 2;
        a += 2 * need;
    }

    if (a + b + c < d1) {
        need = min(b2 - b, d1 - a - b - c) / 2;
        b += 2 * need;
    }

    if (a + b + c < d1) {
        need = min(c2 - c, d1 - a - b - c) / 2;
        c += 2 * need;
    }

    if (a + b + c < d1 && a + 2 <= a2) a += 2;
    if (a + b + c < d1 && b + 2 <= b2) b += 2;
    if (a + b + c < d1 && c + 2 <= c2) c += 2;

    d = a + b + c;
    if (a < a1 || a2 < a) return false;
    if (b < b1 || b2 < b) return false;
    if (c < c1 || c2 < c) return false;
    if (d < d1 || d2 < d) return false;

    xsol = (b + c) / 2;
    ysol = (a + c) / 2;
    zsol = (a + b) / 2;

    return true;
}

bool check(ll dist) {
    ll x, y, z;
    int i;

    a1 = b1 = c1 = d1 = -inf;
    a2 = b2 = c2 = d2 = inf;

    if (dist >= inf) return true;

    for (i = 1; i <= n; i++) {
        x = P[i].x;
        y = P[i].y;
        z = P[i].z;

        a1 = max(a1, -x + y + z - dist);
        a2 = min(a2, -x + y + z + dist);

        b1 = max(b1, x - y + z - dist);
        b2 = min(b2, x - y + z + dist);

        c1 = max(c1, x + y - z - dist);
        c2 = min(c2, x + y - z + dist);

        d1 = max(d1, x + y + z - dist);
        d2 = min(d2, x + y + z + dist);
    }

    if (valid(0)) return true;
    if (valid(1)) return true;

    return 0;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) P[i].read();

        l = 0; r = 3e18;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }

        check(l);
        printf("%lld %lld %lld\n", xsol, ysol, zsol);
    }


    return 0;
}