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
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    sciiid(n, k, a);
    scid(m);
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    multiset<int> ms;
    ms.insert(n);
    int kf = (n + 1) / (a + 1);
    for (int i = 0; i < m; i++) {
        scid(x);
        auto it = s.upper_bound(x);
        int r = *it;
        --it;
        int l = *it;
        s.insert(x);
        ms.erase(ms.find(r - l - 1));
        ms.insert(x - l - 1);
        ms.insert(r - x - 1);
        kf -= (r - l) / (a + 1);
        kf += (x - l) / (a + 1);
        kf += (r - x) / (a + 1);
        if (kf < k) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}