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
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

LL gcd(LL x, LL y) {
    if (!y) return x;
    return gcd(y, x % y);
}
int _;
LL a, m;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%I64d%I64d", &a, &m);
        LL gd = gcd(a, m);
        m /= gd;
        LL ans = 1;
        for (int i = 2; (LL) i * i <= m; ++i) {
            if (m % i == 0) {
                int cnt = 0;
                while (m % i == 0) {
                    cnt++;
                    m /= i;
                }
                ans *= (i - 1);
                for (int j = 0; j < cnt - 1; ++j) ans *= i;
            }
        }
        if (m != 1) ans *= (m - 1);
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
4 9
5 10
42 9999999967

*/