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

int a[333333];

int main() {
    scid(n);
    set<int> cAll;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        cAll.insert(a[i]);
    }
    if (cAll.size() == n) {
        cout << -1;
        return 0;
    }
    set<int> cc;
    vector<pair<int, int> > aa;
    int last = 0;
    cc.insert(a[0]);
    for (int i = 1; i < n; i++) {
        if (cc.find(a[i]) != cc.end()) {
            aa.push_back({last, i});
            last = i + 1;
            cc.clear();
        } else {
            cc.insert(a[i]);
        }
    }
    if (aa.empty()) {
        aa.push_back({0, n - 1});
    } else {
        aa.back().second = n - 1;
    }
    cout << aa.size() << "\n";
    for (auto& i : aa) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}