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
    vector<int> a[3];
    bool wZero = false;
    int s3 = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        a[x % 3].push_back(x);
        wZero |= x == 0;
        s3 = (s3 + x) % 3;
    }
    if (!wZero) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        sort(a[i].rbegin(), a[i].rend());
    }

    if (s3 == 1) {
        if (!a[1].empty()) {
            a[1].pop_back();
        } else if (a[2].size() >= 2) {
            a[2].pop_back();
            a[2].pop_back();
        } else {
            cout << -1;
            return 0;
        }
    } else if (s3 == 2) {
        if (!a[2].empty()) {
            a[2].pop_back();
        } else if (a[1].size() >= 2) {
            a[1].pop_back();
            a[1].pop_back();
        } else {
            cout << -1;
            return 0;
        }
    }
    if (a[1].empty() && a[2].empty()) {
        if (a[0].empty()) {
            cout << -1;
            return 0;
        }
        if (a[0][0] == 0) {
            cout << 0;
            return 0;
        }
    }

    vector<int> ans;
    for (int i = 0; i < 3; i++) {
        for (int j : a[i]) {
            ans.push_back(j);
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (int i : ans) {
        cout << i;
    }

    return 0;
}