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

int a[1111];
int ans[1111];

int main() {
    int mod = 1e9 + 7;
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        ans[i] = 2;
        for (int j = a[i]; j < i; j++) {
            ans[i] = (ans[i] + ans[j]) % mod;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        t = (t + ans[i]) % mod;
    }
    cout << t;
    return 0;
}