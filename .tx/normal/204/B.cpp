#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    scid(n);
    unordered_map<int, int> cf, cb, same;
    unordered_set<int> all;
    for (int i = 0; i < n; ++i) {
        sciid(x, y);
        cf[x]++;
        cb[y]++;
        all.insert(x);
        all.insert(y);
        if (x == y) {
            same[x]++;
        }
    }
    int half = (n + 1) / 2;
    int ans = 1e9;
    for (auto& i : all) {
        int inF = cf[i];
        int inB = cb[i];
        int sm = same[i];
        if (inF >= half) {
            ans = 0;
            break;
        }
        if (inF + inB - sm >= half) {
            ans = min(ans, half - inF);
        }
    }

    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}