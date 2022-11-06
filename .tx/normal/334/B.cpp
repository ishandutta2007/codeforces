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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    vector< pair<int, int> > a;
    for (int i = 0; i < 8; i++) {
        sciid(x, y);
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    bool ok = a[0].first == a[1].first && a[1].first == a[2].first;
    ok &= a[0].second != a[1].second && a[1].second != a[2].second && a[0].second != a[2].second;
    ok &= a[2].first != a[3].first;
    ok &= a[0].second == a[3].second;
    ok &= a[3].first == a[4].first;
    ok &= a[4].second == a[2].second;
    ok &= a[5].first != a[4].first;
    ok &= a[5].second == a[0].second;
    ok &= a[5].first == a[6].first && a[6].first == a[7].first;
    ok &= a[6].second == a[1].second;
    ok &= a[7].second == a[2].second;
    cout << (ok ? "respectable" : "ugly");

    return 0;
}