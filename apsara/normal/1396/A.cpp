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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;
LL a[V];
int n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        if (n == 1) {
            puts("1 1");
            printf("%I64d\n", -a[1]);
            puts("1 1");
            printf("%I64d\n", a[1]);
            puts("1 1");
            printf("%I64d\n", -a[1]);
            continue;
        }
        printf("%d %d\n", 1, n - 1);
        for (int i = 1; i < n; ++i) printf("%I64d ", a[i] * (n - 1)); puts("");
        printf("%d %d\n", n, n);
        printf("%I64d\n", -a[n]);
        printf("%d %d\n", 1, n);
        for (int i = 1; i < n; ++i) printf("%I64d ", -a[i] * n); puts("0");
    }
    return 0;
}

/*
4
1 3 2 4
*/