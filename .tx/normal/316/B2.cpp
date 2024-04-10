#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

bool cs[1111][1111];

int bef[1111];
bool hasaf[1111];

int len(int i) {
    if (bef[i] == -1) {
        return 1;
    }
    return len(bef[i]) + 1;
}

bool have(int i, int s) {
    if (i == s) {
        return true;
    }
    if (bef[i] == -1) {
        return false;
    }
    return have(bef[i], s);
}

int main() {
    sciid(n, s);
    --s;
    for (int i = 0; i < n; i++) {
        scid(x);
        --x;
        bef[i] = x;
        hasaf[x] = true;
    }

    vector<int> a;

    for (int i = 0; i < n; i++) {
        if (!hasaf[i] && !have(i, s)) {
            a.push_back(len(i));
        }
    }

    cs[0][0] = true;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= n; j++) {
            if (cs[i][j]) {
                cs[i + 1][j] = true;
                if (j + a[i] <= n) {
                    cs[i + 1][j + a[i]] = true;
                }
            }
        }
    }

    s = len(s);

    for (int i = 0; i <= n; i++) {
        if (cs[a.size()][i]) {
            cout << s + i << "\n";
        }
    }

    return 0;
}