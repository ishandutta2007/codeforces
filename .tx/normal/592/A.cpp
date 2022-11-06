#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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

char a[11][11];

int main() {
    int n = 8;
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    int mb = 100;
    int mw = 100;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'W') {
                bool ok = true;
                for (int k = 0; k < i; k++) {
                    if (a[k][j] == 'B') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    mw = min(mw, i);
                }
            } else if (a[i][j] == 'B') {
                bool ok = true;
                for (int k = i + 1; k < n; k++) {
                    if (a[k][j] == 'W') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    mb = min(mb, n - 1 - i);
                }
            }
        }
    }
    cerr << mw << " " << mb << endl;
    cout << (mw <= mb ? "A" : "B");
    return 0;
}