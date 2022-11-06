#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int P = 1000000007;

const LL gcd(LL x, LL y) {
    if (!y) return x;
    return gcd(y, x % y);
}

LL fac[12000], n;
int fn;

int main() {
    while (~scanf("%I64d", &n)) {
        fn = 0;
        LL x = n;
        for (int i = 2; (LL) i * i <= x; ++i) {
            if (x % i == 0) {
                fac[fn++] = i;
                while (x % i == 0) x /= i;
            }
        }
        if (x != 1) fac[fn++] = x;
        LL gd = 0;
        for (int i = 0; i < fn; ++i) gd = gcd(gd, fac[i]);
        if (n == 1) gd = 1;
        printf("%I64d\n", gd);
    }
    return 0;
}

/*

*/