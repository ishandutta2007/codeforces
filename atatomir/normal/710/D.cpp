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

ll a1, b1, a2, b2, A, B, mod;
ll x, y, d, dif, fr;

void gcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }

    ll xx, yy;
    gcd(b, a % b, xx, yy, d);
    x = yy;
    y = xx - (a / b) * yy;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &a2, &b2, &A, &B);

    A = max(A, max(b1, b2));

    /*b1 %= a1;
    b1 = (b1 + a1) % a1;

    b2 %= a2;
    b2 = (b2 + a2) % a2;*/

    gcd(a1, a2, x, y, d);
    dif = abs(b2 - b1);

    if (dif % d != 0) {
        printf("0");
        return 0;
    }

    x *= dif / d;
    y *= dif / d;

    if (b2 - b1 < 0) x = -x;
    mod = (a1 * a2) / d;

    x -= (mod / a1) * (x / (mod / a1));
    fr = a1 * x + b1;

    //printf("!!!%lld\n", x);

    if (B < fr) {
        printf("0");
        return 0;
    }

    ll p1 = (A - fr) / mod;
    while (fr + p1 * mod < A) p1++;
    while (fr + p1 * mod - mod >= A && p1 > 0) p1--;


    ll p2 = (B - fr) / mod;
    while (fr + p2 * mod + mod <= B) p2++;

    //if (p1 == -114554) p1--;

    printf("%lld\n", max(0LL, 1 + p2 - p1));
    //printf("%lld %lld", p1, p2);

    return 0;
}