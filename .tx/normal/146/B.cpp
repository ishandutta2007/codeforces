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

int main() {
    int a;
    string b;
    cin >> a >> b;
    int mc[10];
    for (int c = a + 1; ; c++) {
        int x = c;
        int pc = 0;
        while (x > 0) {
            if (x % 10 == 4 || x % 10 == 7) {
                mc[pc++] = x % 10;
            }
            x /= 10;
        }
        if (pc != b.size()) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i < pc; i++) {
            if (mc[pc - 1 - i] != b[i] - '0') {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << c;
            break;
        }
    }



    return 0;
}