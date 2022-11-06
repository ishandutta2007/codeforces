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

vector<int> g[111111];
vector<int> bd[111111];
int d[111111];

int main() {
    sciid(n, k);
    for (int i = 0; i < n; i++) {
        sci(d[i]);
        bd[d[i]].push_back(i);
    }
    if (bd[0].size() != 1) {
        cout << -1;
        return 0;
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (k == 1) {
        if (n > 2) {
            cout << -1;
            return 0;
        }
        if (bd[1].size() != 1) {
            cout << -1;
            return 0;
        }
        cout << "1\n1 2";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            continue;
        }
        int t = d[i] - 1;
        if (bd[t].empty()) {
            cout << -1;
            return 0;
        }
        int b = bd[t].back();
        g[b].push_back(i);
        if (g[b].size() == k - (t == 0 ? 0 : 1)) {
            bd[t].pop_back();
        }
    }

    cout << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            cout << i + 1 << " " << j + 1 << "\n";
        }
    }

    return 0;
}