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

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    priority_queue<pair<int, pair<int, int> > > q;
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < i; j++) {
            scid(x);
            q.push({x, {i, j}});
        }
    }
    vector<int> ans(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        ans[i] = i;
    }
    while (!q.empty()) {
        auto v = q.top().second;
        q.pop();
        if (ans[v.first] == v.first && ans[v.second] == v.second) {
            swap(ans[v.first], ans[v.second]);
        }
    }
    for (int i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}