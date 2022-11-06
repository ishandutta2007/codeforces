#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

lint sum = 0;

int a[11];
int n;

int cntInv() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                res++;
            }
        }
    }
    return res;
}

void rev(int i, int j) {
    int len = j - i + 1;
    for (int k = 0; k * 2 < len; k++) {
        swap(a[i + k], a[j - k]);
    }
}

void go(int d) {
    if (d == 0) {
        sum += cntInv();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            rev(i, j);
            go(d - 1);
            rev(i, j);
        }
    }
}

int main() {
    sci(n);
    scid(k);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    go(k);

    printf("%.11f", sum / pow(n * (n + 1) / 2.0, k));

    return 0;
}