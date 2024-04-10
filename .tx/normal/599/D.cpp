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
    init_cin();
    lint x;
    cin >> x;
    vector<pair<lint, lint> > ans;
    for (lint n = 1; ; n++) {
        lint m = x + n * n * (n - 1) / 2 - n * (n - 1) * (2 * n - 1) / 6;
        if (m <= 0) {
            break;
        }
        m *= 2;
        if (m % (n + n * n) == 0) {
            m /= n + n * n;
            if (m < n) {
                break;
            }
            ans.push_back({n, m});
            if (n != m) {
                ans.push_back({m, n});
            }
        }
    }
    sort(all(ans));
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
}