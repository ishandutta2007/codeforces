#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    scid(n);
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        scid(x);
        a[x]++;
    }
    int c1 = 0;
    int mx = 0;
    for (auto it = a.begin(); it != a.end(); ++it) {
        c1 += it->second & 1;
        mx = max(mx, it->first);
        if (it->second >= 2) {
            int t = it->second;
            it->second %= 2;
            int f = it->first;
            a[f + 1] += t / 2;
            it = a.find(f);
        }
    }

    cout << mx + 1 - c1;

    return 0;
}