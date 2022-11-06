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

bool check1(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    return a.first == b.first && a.first == c.first;
}

bool check2(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    return a.first == b.first && (c.second <= min(a.second, b.second) || c.second >= max(a.second, b.second));
}

int main() {
    pair<int, int> a[3];
    for (int i = 0; i < 3; i++) {
        scii(a[i].first, a[i].second);
    }
    if (check1(a[0], a[1], a[2])) {
        cout << 1;
        return 0;
    }
    sort(a, a + 3);
    do {
        if (check2(a[0], a[1], a[2])) {
            cout << 2;
            return 0;
        }
    } while (next_permutation(a, a + 3));

    for (int i = 0; i < 3; i++) {
        swap(a[i].first, a[i].second);
    }

    if (check1(a[0], a[1], a[2])) {
        cout << 1;
        return 0;
    }
    sort(a, a + 3);
    do {
        if (check2(a[0], a[1], a[2])) {
            cout << 2;
            return 0;
        }
    } while (next_permutation(a, a + 3));

    cout << 3;

    return 0;
}