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
const int V = 200100;
int l[V], r[V], n, _;
LL S;

int b[V];

bool ok(int mid) {
    int bn = 0;
    LL use = 0;
    for (int i = 0; i < n; ++i) {
        if (r[i] < mid) {
            use += l[i];
        } else {
            use += l[i];
            b[bn++] = max(0, mid - l[i]);
        }
    }
    int need = (n + 1) / 2;
    //printf("M %d %d %d\n", mid, bn, need);
    //for (int i = 0; i < bn; ++i) printf("%d ", b[i]); puts("");
    if (bn < need) return false;
    sort(b, b + bn);
    for (int i = 0; i < need; ++i) use += b[i];
    //printf("USE %I64d %I64d\n", use, S);
    return use <= S;
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%I64d", &n, &S);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &l[i], &r[i]);
        int lo = l[0], up = r[0];
        for (int i = 0; i < n; ++i) {
            lo = min(lo, l[i]);
            up = max(up, r[i]);
        }
        while (lo < up) {
            int mid = (lo + up + 1) / 2;
            //printf("bi %d %d %d\n", lo, up, mid);
            if (ok(mid)) lo = mid;
            else up = mid - 1;
        }
        printf("%d\n", lo);
    }
    return 0;
}

/*
3
3 26
10 12
1 4
10 11
1 1337
1 1000000000
5 26
4 4
2 4
6 8
5 6
2 7

*/