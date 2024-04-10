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
    sciid(n, k);
    map<int, int> m;
    rveid(a, n);
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    if (m.size() < k) {
        cout << "-1 -1";
        return 0;
    }
    int x = m.size();
    int l = 0;
    while (x > k || m[a[l]] > 1) {
        m[a[l]]--;
        if (m[a[l]] == 0) {
            x--;
        }
        l++;
    }
    int r = n - 1;
    while (m[a[r]] > 1) {
        m[a[r]]--;
        r--;
    }
    cout << l + 1 << " " << r + 1;

    return 0;
}