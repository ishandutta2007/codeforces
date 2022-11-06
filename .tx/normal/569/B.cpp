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

int c[111111];

int main() {
    scid(n);
    rveid(a, n);
    for (auto i : a) {
        c[i]++;
    }
    int l = 1;
    for (int i = 0; i < n; i++) {
        if (c[a[i]] > 1 || a[i] > n) {
            while (c[l] > 0) {
                l++;
            }
            c[a[i]]--;
            c[l]++;
            a[i] = l;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}