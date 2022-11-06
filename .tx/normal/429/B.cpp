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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int d11[1111][1111];
int d12[1111][1111];
int d21[1111][1111];
int d22[1111][1111];

int a[1111][1111];

int main() {
    sciid(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            sci(a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d11[i][j] = max(d11[i][j - 1], d11[i - 1][j]) + a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 0; j--) {
            d12[i][j] = max(d12[i][j + 1], d12[i - 1][j]) + a[i][j];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            d21[i][j] = max(d21[i + 1][j], d21[i][j - 1]) + a[i][j];
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = m; j > 0; j--) {
            d22[i][j] = max(d22[i + 1][j], d22[i][j + 1]) + a[i][j];
        }
    }

    int ans = 0;

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            int x1 = d11[i][j - 1] + d22[i][j + 1] + d21[i + 1][j] + d12[i - 1][j];
            int x2 = d11[i - 1][j] + d22[i + 1][j] + d21[i][j - 1] + d12[i][j + 1];
            ans = max(ans, max(x1, x2));
        }
    }

    cout << ans;

    return 0;
}