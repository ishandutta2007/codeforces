#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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
    vector<int> a(n);
    priority_queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = x;
        q.push({x, i});
    }
    int ans = 0;
    int last = n;
    int mn = (int) 1e9 + 1;
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        if (v.second < last) {
            if (v.first <= mn) {
                ans++;
            }
            for (int i = v.second; i < last; i++) {
                mn = min(mn, a[i]);
            }
            last = v.second;
        }
    }
    cout << ans;
    return 0;
}