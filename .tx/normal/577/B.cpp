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

bool d[1111];
bool e[1111];

int main() {
    sciid(n, m);
    for (int i = 0; !d[0] && i < n && i < 2 * m; i++) {
        scid(x);
        for (int j = 0; j < m; j++) {
            if (d[j]) {
                e[(j + x) % m] = true;
            }
        }
        e[x % m] = true;
        for (int i = 0; i < m; i++) {
            d[i] |= e[i];
        }
    }
    cout << (d[0] ? "YES" : "NO");
    return 0;
}