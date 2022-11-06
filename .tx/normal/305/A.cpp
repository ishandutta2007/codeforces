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
    map<int, int> s;
    for (int i = 0; i < n; ++i) {
        scid(x);
        int ox = x;
        int y = 0;
        for (int j = 0; j < 3; j++) {
            y |= (x % 10 > 0 ? 1 : 0) << j;
            x /= 10;
        }
        s[y] = ox;
    }
    vector<int> a;
    for (auto& i : s) {
        a.push_back(i.first);
    }
    n = a.size();
    int ans = 0;
    int maskAns = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        bool ok = true;
        if (__builtin_popcount(mask) <= ans) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < i; j++) {
                    if (mask & (1 << j)) {
                        if (a[i] & a[j]) {
                            ok = false;
                        }
                    }
                }
            }
        }
        if (!ok) {
            continue;
        }
        maskAns = mask;
        ans = __builtin_popcount(mask);
    }
    vector<int> aans;
    for (int i = 0; i < n; i++) {
        if (maskAns & (1 << i)) {
            aans.push_back(s[a[i]]);
        }
    }

    cout << aans.size() << "\n";
    for (auto& i : aans) {
        cout << i << " ";
    }

    return 0;
}