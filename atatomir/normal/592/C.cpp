#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

long long t, a, b, cmmdc, mini;

long long ans_a, ans_b;
long long cmmmc;

long long gcd(long long a, long long b) {
    if (a < b) swap(a, b);

    while (b > 0) {
        a %= b;
        swap(a, b);
    }

    return a;
}

bool too_big() {
    long long aa = a / cmmdc;
    long long bb = b;

    double x = 1.00 * aa * bb;
    if (x > 5.00 * 1e18) return true;
    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%I64d %I64d %I64d", &t, &a, &b);
    cmmdc = gcd(a, b);

    mini = min(a, b);
    ans_b = t;

    if (too_big()) {
        ans_a = min(t + 1, mini);
    } else {
        cmmmc = (a / cmmdc) * b;

        long long how = t / cmmmc;
        ans_a = how * mini ;
        ans_a += min(t - how * cmmmc + 1, mini);
    }

    ans_a--;
    cmmdc = gcd(ans_a, ans_b);
    printf("%I64d/%I64d", ans_a/cmmdc, ans_b/cmmdc);


    return 0;
}