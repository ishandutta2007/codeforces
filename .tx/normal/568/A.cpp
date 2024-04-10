#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>
#include <ctime>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

const int M = 1e7;
bool pr[M + 1];

int main() {
    sciid(p, q);
    pr[1] = true;
    for (int i = 2; i <= M; i++) {
        if (!pr[i]) {
            for (int j = i + i; j <= M; j += i) {
                pr[j] = true;
            }
        }
    }
    int kpr = 0, kpal = 0;
    int c[11];
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        if (!pr[i]) {
            kpr++;
        }
        int x = i;
        int k = 0;
        while (x > 0) {
            c[k++] = x % 10;
            x /= 10;
        }
        for (int j = 0; j * 2 < k; j++) {
            if (c[j] != c[k - 1 - j]) {
                kpal--;
                break;
            }
        }
        kpal++;
        if (1LL * q * kpr <= 1LL * p * kpal) {
            ans = i;
        }
    }
    cout << ans;


    return 0;
}