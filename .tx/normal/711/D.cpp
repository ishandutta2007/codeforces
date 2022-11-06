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

int to[222222];
const int mod = 1e9 + 7;
lint p2[222222];
int col[222222];
int d[222222];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(to[i]);
        --to[i];
    }

    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2 % mod;
    }

    lint ans = 1;
    int rest = n;
    int cc = 0;

    for (int i = 0; i < n; i++) {
        if (col[i]) {
            continue;
        }
        int cur = i;
        bool cycle = false;
        ++cc;
        int cd = 0;
        int len = -1;
        while (col[cur] == 0) {
            col[cur] = cc;
            d[cur] = cd++;
            if (col[to[cur]] == cc) {
                cycle = true;
                len = cd - d[to[cur]];
                break;
            }
            cur = to[cur];
        }
        if (cycle) {
            rest -= len;
            ans = ans * (p2[len] - 2 + mod) % mod;
        }
    }

    ans = ans * p2[rest] % mod;

    cout << ans;


    return 0;
}