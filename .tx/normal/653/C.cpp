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

int a[222222];
int n;

bool check_around1(int i) {
    bool ok = true;
    if (i % 2 == 1) {
        if (i > 0 && a[i] <= a[i - 1]) {
            ok = false;
        }
        if (i + 1 < n && a[i] <= a[i + 1]) {
            ok = false;
        }
    } else {
        if (i > 0 && a[i] >= a[i - 1]) {
            ok = false;
        }
        if (i + 1 < n && a[i] >= a[i + 1]) {
            ok = false;
        }
    }
    return ok;
}

bool check_around(int i) {
    bool ok = check_around1(i);
    if (i > 0) {
        ok &= check_around1(i - 1);
    }
    if (i + 1 < n) {
        ok &= check_around1(i + 1);
    }
    return ok;
}

bool try_swap(int i, int j) {
    swap(a[i], a[j]);
    bool res = check_around(i) && check_around(j);
    swap(a[i], a[j]);
    return res;
}

bool check() {
    for (int i = 0; i + 1 < n; i++) {
        if (i % 2 == 0 && a[i] >= a[i + 1]) {
            return false;
        }
        if (i % 2 == 1 && a[i] <= a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool bad[222222];

int main() {
    sci(n);
    rea(a, n);
    vector<int> ps;
    for (int i = 0; i + 1 < n; i++) {
        if (i % 2 == 0 && a[i] >= a[i + 1]) {
            ps.push_back(i);
            bad[i] = true;
            bad[i + 1] = true;
        }
        if (i % 2 == 1 && a[i] <= a[i + 1]) {
            ps.push_back(i);
            bad[i] = true;
            bad[i + 1] = true;
        }
    }

    if (ps.size() > 10) {
        cout << 0;
        return false;
    }

    set<pair<int, int> > ok;

    for (int i = 0; i < n; i++) {
        if (bad[i] || (i > 0 && bad[i - 1]) || (i + 1 < n && bad[i + 1])) {
            for (int j = 0; j < n; j++) {
                swap(a[i], a[j]);
                bool f = check_around(j);
                for (int p : ps) {
                    f &= check_around(p);
                }
                if (f) {
                    ok.insert({min(i, j), max(i, j)});
                }
                swap(a[i], a[j]);
            }
        }
    }

    cout << ok.size();



//    if (ps.size() > 3) {
//        cout << 0;
//        return 0;
//    }
//
//    if (ps.size() == 3) {
//        int ans = 0;
//    }
//
//    int ans = 0;
//
//    if (ps.size() == 2) {
//        int p1 = ps[0];
//        int p2 = ps[1];
//        if (try_swap(p1, p2)) {
//            ans++;
//        }
//        if (try_swap(p1, p2 + 1)) {
//            ans++;
//        }
//        if (try_swap(p1 + 1, p2)) {
//            ans++;
//        }
//        if (try_swap(p1 + 1, p2 + 1)) {
//            ans++;
//        }
//
//        if (p1 + 1 == p2) {
//            for (int i = 0; i < n; i++) {
//                if (i == p1 || i == p1 + 1 || i == p1 + 2) {
//                    continue;
//                }
//                if (try_swap(p2, i)) {
//                    ans++;
//                }
//            }
//        }
//
//        cout << ans;
//        return 0;
//    }
//
//    int p = ps[0];
//    for (int i = 0; i < n; i++) {
//        if (i == p || i == p + 1) {
//            continue;
//        }
//        if (try_swap(i, p)) {
//            ans++;
//        }
//        if (try_swap(i, p + 1)) {
//            ans++;
//        }
//    }
//    if (try_swap(p, p + 1)) {
//        ans++;
//    }
//    cout << ans;

    return 0;
}